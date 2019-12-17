#include <iostream>
#include <vector>
#include <algorithm>
#include "heap_timer.h"

using namespace std;

int main() {
    heap_timer_node *node1 = new heap_timer_node(6);
    heap_timer_node *node2 = new heap_timer_node(2);
    heap_timer_node *node3 = new heap_timer_node(4);
    heap_timer_node *node4 = new heap_timer_node(11);
    heap_timer_node *node5 = new heap_timer_node(5);

    timer_heap heaps(10);
    heaps.add_timer(node1);
    heaps.add_timer(node2);
    heaps.add_timer(node3);
    heaps.add_timer(node4);
    heaps.add_timer(node5);

    heaps.get_top();

    heaps.disPlay();
    heaps.del_timer(node1);

    heaps.del_timer(node2);

    heaps.del_timer(node3);
    heaps.disPlay();


    return 0;
}
