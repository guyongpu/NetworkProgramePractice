//
// Created by yongpu on 12/12/19.
//

#ifndef LST_TIMER_UTIL_TIMER_H
#define LST_TIMER_UTIL_TIMER_H

#include <iostream>
#include <time.h>
#include <netinet/in.h>

using namespace std;

#define BUFFER_SIZE 64

class util_timer;

/**
 * 用户数据结构
 */
struct client_data {
    sockaddr_in address;        /* 客户端socket */
    int sockfd;                 /* socket文件描述符 */
    char buf[BUFFER_SIZE];      /* 读缓存 */
    util_timer *timer;          /* 定时器 */
};

/**
 * 定时器类
 */
class util_timer {
public:
    util_timer() : prev(NULL), next(NULL) {};
public:
    time_t expire;                  /* 任务的超时时间，这里使用绝对时间 */

    void (*cb_func)(client_data *); /* 任务回调函数 */

    client_data *user_data;         /* 回调函数处理的客户数据，由定时器的执行者传递给回调函数 */
    util_timer *prev;               /* 指向前一个定时器 */
    util_timer *next;               /* 指向下一个定时器 */
};


#endif //LST_TIMER_UTIL_TIMER_H
