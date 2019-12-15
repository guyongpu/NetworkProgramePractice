/**
 * epoll惊群测试，独享epollfd树根
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>


#define IP   "127.0.0.1"
#define PORT  8888
#define PROCESS_NUM 4
#define MAXEVENTS 64

static int create_and_bind() {
    int fd = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    inet_pton(AF_INET, IP, &serveraddr.sin_addr);
    serveraddr.sin_port = htons(PORT);
    bind(fd, (struct sockaddr *) &serveraddr, sizeof(serveraddr));
    return fd;
}

static int make_socket_non_blocking(int sfd) {
    int flags, s;
    flags = fcntl(sfd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl");
        return -1;
    }
    flags |= O_NONBLOCK;
    s = fcntl(sfd, F_SETFL, flags);
    if (s == -1) {
        perror("fcntl");
        return -1;
    }
    return 0;
}

int worker(int sfd, int k) {
    int efd = epoll_create(MAXEVENTS);
    if (efd == -1) {
        perror("epoll_create");
        abort();
    }
    struct epoll_event event;
    struct epoll_event *events;
    event.data.fd = sfd;

    int op = 3;                                         /* 此处自己设置测试的环境 */
    if(op == 1){
        event.events = EPOLLIN;                         /* LT模式，读事件 */
    }
    else if(op == 2){
        event.events = EPOLLIN|EPOLLET;                 /* ET模式，读事件 */
    }
    else if(op == 3){
        event.events = EPOLLIN|EPOLLEXCLUSIVE;          /* LT模式，EPOLLEXCLUSIVE选项，读事件 */
    }
    else if(op == 4){
        event.events = EPOLLIN|EPOLLET|EPOLLEXCLUSIVE;  /* ET模式，EPOLLEXCLUSIVE选项，读事件 */
    }

    int s = epoll_ctl(efd, EPOLL_CTL_ADD, sfd, &event);
    if (s == -1) {
        perror("epoll_ctl");
        abort();
    }

    events = calloc(MAXEVENTS, sizeof(event));
    /* The event loop */
    while (1) {
        int n, i;
        n = epoll_wait(efd, events, MAXEVENTS, -1);
        sleep(1);
        printf("worker %d return from epoll_wait!\n", k);
        for (int i = 0; i < n; i++) {
            /* 文件描述符发生错误，被挂断，不可读 */
            if ((events[i].events & EPOLLERR) || (events[i].events & EPOLLHUP) || (!(events[i].events & EPOLLIN))) {
                fprintf(stderr, "epoll error\n");
                close(events[i].data.fd);
                continue;
            }
                /* 到来一个连接请求 */
            else if (sfd == events[i].data.fd) {
                struct sockaddr in_addr;
                socklen_t in_len;

                char hbuf[NI_MAXHOST], sbuf[NI_MAXSERV];
                in_len = sizeof(in_addr);
                int infd = accept(sfd, &in_addr, &in_len);
                if (infd == -1) {
                    printf("woker %d accept failed!\n", k);
                    break;
                }
                printf("woker %d accept successed!\n", k);
                /* 将connfd设置为非阻塞并加入到epoll的监听树上 */
                close(infd);
            }
        }
    }
    free(events);
    return 0;
}

int main() {
    int sfd, s;

    sfd = create_and_bind();
    if (sfd == -1) {
        abort();
    }
    s = make_socket_non_blocking(sfd);
    if (s == -1) {
        abort();
    }
    s = listen(sfd, SOMAXCONN);
    if (s == -1) {
        perror("listen");
        abort();
    }


    for (int i = 0; i < PROCESS_NUM; i++) {
        printf("Create worker %d\n", i + 1);
        int pid = fork();
        if (pid == 0) { /* 子进程 */
            printf("I am %dth sub process,pid = %d!", i, pid);
            worker(sfd, i);    /* 新进程开始epoll监听 */
        }
    }

    int status;
    wait(&status);
    close(sfd);
    return EXIT_SUCCESS;
}
