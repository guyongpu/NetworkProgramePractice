#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <pthread.h>

#include "sort_timer_lst.h"
#include "util_timer.h"

using namespace std;

#define FD_LIMIT 65535
#define MAX_EVENT_NUMBER 1024
#define TIMESLOT 5

static int pipefd[2];

static sort_timer_lst timer_lst;
static int epollfd = 0;

int setnonblocking(int fd);

void addfd(int epollfd, int fd);

void sig_handler(int sig);

void addsig(int sig);

void timer_handler();

void cb_func(client_data *user_data);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage:%s ip_address port_number\n", basename(argv[0]));
    }
    const char *ip = argv[1];
    int port = atoi(argv[2]);

    int ret = 0;
    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr);
    address.sin_port = htons(port);

    int listenfd = socket(PF_INET, SOCK_STREAM, 0);
    assert(listenfd >= 0);

    /* 绑定端口 */
    ret = bind(listenfd, (struct sockaddr *) &address, sizeof(address));
    assert(ret != -1);

    /* 开始监听 */
    ret = listen(listenfd, 5);
    assert(ret != -1);

    epoll_event events[MAX_EVENT_NUMBER];
    int epollfd = epoll_create(5);
    assert(epollfd != -1);

    /* 添加listenfd到红黑树上监听 */
    addfd(epollfd, listenfd);

    /* socketpair创建的管道和pip管道不同就是 他创建的管道两端都可读写 */
    /* 使用socketpair，和pipe的区别是pipe是半双工，这个是全双工 */
    ret = socketpair(PF_UNIX, SOCK_STREAM, 0, pipefd);
    assert(ret != -1);
    setnonblocking(pipefd[1]);
    addfd(epollfd, pipefd[0]);

    /* 设置信号处理函数 */
    addsig(SIGALRM);
    addsig(SIGTERM);
    bool stop_server = false;

    /* 用户数据的  指针  指向那么多的结构吧 指针加1  数组下标加1 */
    client_data *users = new client_data[FD_LIMIT];
    bool timeout = false;
    alarm(TIMESLOT); /* 定时 */

    while (!stop_server) {
        int number = epoll_wait(epollfd, events, MAX_EVENT_NUMBER, -1);
        if ((number < 0) && (errno != EINTR)) {
            printf("epoll failure\n");
        }

        for (int i = 0; i < number; i++) {
            int sockfd = events[i].data.fd;
            /* 处理新到的客户连接 */
            if (sockfd == listenfd) {
                struct sockaddr_in client_address;
                socklen_t client_addrlength = sizeof(client_address);
                int connfd = accept(listenfd, (struct sockaddr *) &client_address, &client_addrlength);

                addfd(epollfd, connfd);

                //就用已连接文件描述符号作为下标来保存已经连接套接字和套接字绑定的信息
                users[connfd].address = client_address;
                users[connfd].sockfd = connfd;
                /* 定时器类 是用来初始化升序链表节点的这个很重要//里面包含成员client_data的指针等 */
                /* 创建定时器，设置回调函数与超时时间，然后绑定定时器与用户数据，最后将定时器添加到链表timer_lst中 */
                util_timer *timer = new util_timer;
                timer->user_data = &users[connfd];  /* client_data的指针回填到链表节点上 */
                timer->cb_func = cb_func;           /* 函数指针回填 入参就是节点自己的user_data成员 */
                time_t cur = time(NULL);
                timer->expire = cur + 3 * timeout;  /* 给这个已经连接的套接字定时 */

                /* 前面创建定时、回掉函数、绑定socket信息、都是为下面一行服务的理解就好 */
                users[connfd].timer = timer;        /* 用户数据回填 定时器类的信息 */
                timer_lst.add_timer(timer);         /* 定时器类 加到链表中去 */
            }
                /* 处理信号 */
            else if ((sockfd == pipefd[0]) && (events[i].events && EPOLLIN)) {
                int sig;
                char signals[1024];
                ret = recv(pipefd[0], signals, sizeof(signals), 0);
                if (ret == -1) {
                    // handle the error
                    continue;
                } else if (ret == 0) {
                    continue;
                } else {
                    for (int i = 0; i < ret; ++i) {
                        switch (signals[i]) {
                            case SIGALRM: {
                                /* 用timeout变量标记有定时任务需要处理，但不立即处理定时任务。
                                 * 这是因为定时任务的优先级不是很高，我们优先处理其他更重要的任务。 */
                                timeout = true;
                                break;
                            }
                            case SIGTERM: {
                            }
                                stop_server = true;
                        }
                    }
                }
            }
                /* 处理客户端连接上接收到的数据 */
            else if (events[i].events & EPOLLIN) {
                memset(users[sockfd].buf, '\0', BUFFER_SIZE);
                ret = recv(sockfd, users[sockfd].buf, BUFFER_SIZE - 1, 0);
                printf("get %d bytes of client data %s from %d\n", ret, users[sockfd].buf, sockfd);

                util_timer *timer = users[sockfd].timer;
                if (ret < 0) {
                    /* 如果发生读错误，则关闭连接，并移除其对应的定时器 */
                    if (errno != EAGAIN) {
                        cb_func(&users[sockfd]);
                        if (timer) {
                            timer_lst.del_timer(timer);
                        }
                    }
                } else if (ret == 0) {
                    /* 如果对方已经关闭连接，则我们也关闭连接，并移除对应的定时器 */
                    cb_func(&users[sockfd]);
                    if (timer) {
                        timer_lst.del_timer(timer);
                    }
                } else {
                    /* 如果某个客户连接上有数据可读，则我们要调整该连接对应的定时器，以延迟该连接关闭的时间 */
                    if (timer) {
                        time_t cur = time(NULL);
                        timer->expire = cur + 3 * TIMESLOT;
                        printf("adjust timer once\n");
                        timer_lst.add_timer(timer);
                    }
                }
            } else {
                //others
            }
        } // end of for

        /* 最后处理定时事件，因为I/O事件有更高的优先级。当然，这样做将导致定时任务不能精确地按照预期的时间执行 */
        if (timeout) {
            timer_handler();
            timeout = false;
        }

    } // end of while


    close(listenfd);
    close(pipefd[1]);
    close(pipefd[0]);
    delete[]users;
    printf("Hello, World!\n");
    return 0;
}

int setnonblocking(int fd) {
    int old_option = fcntl(fd, F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd, F_SETFL, new_option);
    return old_option;
}

void addfd(int epollfd, int fd) {
    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET;   /* epoll的ET模式 */
    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event);
    setnonblocking(fd);
}

void sig_handler(int sig) {
    int save_errno = errno;
    int msg = sig;
    send(pipefd[1], (char *) &msg, 1, 0);  /* 写端口发送信号 */
    errno = save_errno;
}

void addsig(int sig) {
    struct sigaction sa;
    memset(&sa, '\0', sizeof(sa));
    sa.sa_handler = sig_handler;    /* 信号调用函数 */
    /*
     * 该标志位重启被该信号中断的当前系统调用  就是让系统调用函数恢复运行
     * 有些信号会中断当前的系统调用，如connect epoll_wait
     */
    sa.sa_flags |= SA_RESTART;
    sigfillset(&sa.sa_mask);                /* 屏蔽其他信号 */
    assert(sigaction(sig, &sa, NULL) != -1);
}

void timer_handler() {
    /* 定时处理任务，实际上是调用tick函数 */
    timer_lst.tick();
    /* 因为一次alarm调用只会引起一次SIGALRM信号，所以我们要重新定时，以不断触发SIGALRM信号 */
    alarm(TIMESLOT);
}

/* 定时器回调函数，它删除非活动连接socket上的注册事件，并关闭之 */
void cb_func(client_data *user_data) {
    epoll_ctl(epollfd, EPOLL_CTL_DEL, user_data->sockfd, 0);
    assert(user_data);
    close(user_data->sockfd);
    printf("close fd %d\n", user_data->sockfd);
}