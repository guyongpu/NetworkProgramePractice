//
// Created by yongpu on 12/12/19.
//

#include "sort_timer_lst.h"


sort_timer_lst::sort_timer_lst() {
    this->head = nullptr;
    this->tail = nullptr;
}

sort_timer_lst::~sort_timer_lst() {
    util_timer *tmp = head;
    while (tmp) {
        head = tmp->next;
        delete tmp;
        tmp = head;
    }
}

void sort_timer_lst::add_timer(util_timer *timer) {
    if (!timer) {
        return;
    }
    if (!head) {
        head = tail = timer;
        return;
    }

    if (timer->expire < head->expire) {
        timer->next = head;
        head->prev = timer;
        head = timer;
        return;
    }
    add_timer(timer, head);
}

void sort_timer_lst::adjust_timer(class util_timer *timer) {
    if (!timer) {
        return;
    }

    util_timer *tmp = timer->next;
    if (!tmp || (timer->expire < tmp->expire)) {
        return;
    }

    if (timer == this->head) {
        head = head->next;
        head->prev = nullptr;
        timer->next = nullptr;
        add_timer(timer, head);
    } else {
        timer->prev->next = timer->next;
        timer->next->prev = timer->prev;
        add_timer(timer, timer->next);
    }
}

void sort_timer_lst::del_timer(class util_timer *timer) {
    if (!timer) {
        return;
    }

    if ((timer == head) && (timer == tail)) {
        delete timer;
        head = nullptr;
        tail = nullptr;
        return;
    }

    if (timer == tail) {
        tail = timer->prev;
        tail->next = nullptr;
        delete timer;
        return;
    }

    timer->prev->next = timer->next;
    timer->next->prev = timer->prev;
    delete timer;
    return;
}

void sort_timer_lst::tick() {
    if (!head) {
        return;
    }

    printf("timer tick\n");
    time_t cur = time(NULL);
    util_timer *tmp = head;

    while (tmp) {
        if (cur < tmp->expire) {
            break;
        }
    }

    tmp->cb_func(tmp->user_data);

    head = tmp->next;
    if (head) {
        head->prev = nullptr;
    }
    return;
}

/** 一个辅助重载函数，它被公有的add_timer函数和adjust_timer函数调用。
 * 该函数表示讲目标定时器timer添加到节点lst_head之后的部分链表中 */
void sort_timer_lst::add_timer(util_timer *timer, util_timer *lst_head) {
    util_timer *prev = lst_head;
    util_timer *tmp = prev->next;
    /* 遍历lst_head节点之后的部分链表，直到找到一个超时时间大于目标定
     * 时器的超时时间的节点，并将目标定时器插入到该节点之前*/
    while (tmp) {
        if (timer->expire < tmp->expire) {
            /* 插在tmp节点之前 */
            timer->prev = tmp->prev;
            tmp->prev->next = timer;

            timer->next = tmp;
            tmp->prev = timer;
            break;
        }
        // prev为tmp的前一个节点
        prev = tmp;
        tmp = tmp->next;
    }

    /* 如果遍历完lst_head节点之后的部分链表，仍然没有找到超时时间大于目标定时器
     * 的超时时间的节点，则讲目标定时器插入尾部，并把它设置为链表新的尾节点 */
    if (!tmp) {
        prev->next = timer;
        timer->prev = prev;
        timer->next = nullptr;
        tail = timer;
    }
}