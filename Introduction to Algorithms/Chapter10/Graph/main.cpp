//
// Created by Nathan on 05/03/2018.
//

#include "Graph.h"

using Nathan::Graph;
using Nathan::ListNode;
using Nathan::DoubleLinkedList;
using namespace::std;

int main() {
    ListNode<int> *node_0 = new ListNode<int>(0);
    ListNode<int> *node_1 = new ListNode<int>(1);
    ListNode<int> *node_2 = new ListNode<int>(2);
    ListNode<int> *node_3 = new ListNode<int>(3);
    ListNode<int> *node_4 = new ListNode<int>(4);
    ListNode<int> *node_5 = new ListNode<int>(5);
    ListNode<int> *node_6 = new ListNode<int>(6);
    ListNode<int> *node_7 = new ListNode<int>(7);

    DoubleLinkedList<int> list_0(node_0);
    list_0.insertTail(node_1);
    list_0.insertTail(node_2);

    node_0 = new ListNode<int>(0);
    node_1 = new ListNode<int>(1);
    node_2 = new ListNode<int>(2);

    DoubleLinkedList<int> list_1(node_1);
    list_1.insertTail(node_0);
    list_1.insertTail(node_3);
    list_1.insertTail(node_4);

    node_0 = new ListNode<int>(0);
    node_1 = new ListNode<int>(1);
    node_3 = new ListNode<int>(3);
    node_4 = new ListNode<int>(4);

    DoubleLinkedList<int> list_2(node_2);
    list_2.insertTail(node_0);
    list_2.insertTail(node_5);
    list_2.insertTail(node_6);

    node_0 = new ListNode<int>(0);
    node_2 = new ListNode<int>(2);
    node_5 = new ListNode<int>(5);
    node_6 = new ListNode<int>(6);

    DoubleLinkedList<int> list_3(node_3);
    list_3.insertTail(node_1);
    list_3.insertTail(node_7);

    node_1 = new ListNode<int>(1);
    node_3 = new ListNode<int>(3);
    node_7 = new ListNode<int>(7);

    DoubleLinkedList<int> list_4(node_4);
    list_4.insertTail(node_1);
    list_4.insertTail(node_7);

    node_1 = new ListNode<int>(1);
    node_4 = new ListNode<int>(4);
    node_7 = new ListNode<int>(7);

    DoubleLinkedList<int> list_5(node_5);
    list_5.insertTail(node_2);
    list_5.insertTail(node_7);

    node_2 = new ListNode<int>(2);
    node_5 = new ListNode<int>(5);
    node_7 = new ListNode<int>(7);

    DoubleLinkedList<int> list_6(node_6);
    list_6.insertTail(node_2);
    list_6.insertTail(node_7);

    node_2 = new ListNode<int>(2);
    node_6 = new ListNode<int>(6);
    node_7 = new ListNode<int>(7);

    DoubleLinkedList<int> list_7(node_7);
    list_7.insertTail(node_3);
    list_7.insertTail(node_4);
    list_7.insertTail(node_5);
    list_7.insertTail(node_6);

    Graph<int> graph(8);
    graph.insertVertice(list_0);
    graph.insertVertice(list_1);
    graph.insertVertice(list_2);
    graph.insertVertice(list_3);
    graph.insertVertice(list_4);
    graph.insertVertice(list_5);
    graph.insertVertice(list_6);
    graph.insertVertice(list_7);

//    graph.DFS();
    graph.BFS(0);
}


