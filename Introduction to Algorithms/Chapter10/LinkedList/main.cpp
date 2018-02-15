#include <iostream>
#include "LinkedList.h"

using namespace::std;
using Nathan::ListNode;
using Nathan::LinkedList;

int main(){
    ListNode<int> *node_3 = new ListNode<int>(10, nullptr);
    ListNode<int> *node_2 = new ListNode<int>(2, node_3);
    ListNode<int> *node_1 = new ListNode<int>(3, node_2);
    LinkedList<int> list(node_1);

    list.print();
    list.invert();
    list.print();
}