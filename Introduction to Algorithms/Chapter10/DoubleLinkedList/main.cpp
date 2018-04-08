#include <iostream>
#include "DoubleLinkedList.h"

using namespace::std;
using Nathan::ListNode;
using Nathan::DoubleLinkedList;

int main(){
    ListNode<int> *node_1 = new ListNode<int>(3);
    DoubleLinkedList<int> list(node_1);
    list.insertTail(2);
    list.insertTail(10);


    list.invert();
    list.print();
//    list.removeHead();
//    list.removeTail();
//    list.print();
}