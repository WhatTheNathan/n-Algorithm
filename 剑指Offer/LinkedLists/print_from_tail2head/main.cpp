#include <iostream>
#include "LinkedList.h"

/*
 * Description:
 * 输入一个链表的头结点，从尾到头反过来打印每个结点的值
 */

using namespace::std;
using Nathan::ListNode;
using Nathan::LinkedList;

int main(){
    ListNode<int> *node_5 = new ListNode<int>(21, nullptr);
    ListNode<int> *node_4 = new ListNode<int>(12, node_5);
    ListNode<int> *node_3 = new ListNode<int>(10, node_4);
    ListNode<int> *node_2 = new ListNode<int>(2, node_3);
    ListNode<int> *node_1 = new ListNode<int>(3, node_2);
    LinkedList<int> list(node_1);

    list.print();
    list.print_from_tail2head();
}