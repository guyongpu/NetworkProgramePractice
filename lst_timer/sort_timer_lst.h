//
// Created by yongpu on 12/12/19.
//

#ifndef LST_TIMER_SORT_TIMER_LST_H
#define LST_TIMER_SORT_TIMER_LST_H

#include <iostream>
#include <time.h>
#include <netinet/in.h>
#include "util_timer.h"

using namespace std;

/**
 * 定时器链表
 * 它是一个升序、双向的链表，且带有头结点和尾节点.
 */
class sort_timer_lst {
public:
    sort_timer_lst();                       /* 构造函数 */
    ~sort_timer_lst();                      /* 析构函数 */

    void add_timer(util_timer *timer);      /* 添加一个定时器 */
    void adjust_timer(util_timer *timer);   /* 调整计时器的位置 */
    void del_timer(util_timer *timer);      /* 删除一个定时器 */

    void tick();                            /* 定时器触发函数 */

private:
    void add_timer(util_timer *timer,util_timer *lst_head); /* 调整定时器在链表中的位置 */

private:
    util_timer *head;                       /* 指向头结点定时器 */
    util_timer *tail;                       /* 指向尾结点定时器 */
};


#endif //LST_TIMER_SORT_TIMER_LST_H
