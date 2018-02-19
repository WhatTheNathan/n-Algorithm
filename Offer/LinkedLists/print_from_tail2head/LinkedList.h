#include <iostream>
#include <stack>

#ifndef _Nathan_LINKEDLIST_H
#define _Nathan_LINKEDLIST_H

namespace Nathan {

    template<class T> class LinkedList;

    template <class T>
    class ListNode
    {
        friend class LinkedList<T>;
    public:
        ListNode(T _data, ListNode* next = nullptr) {
            data = _data;
            link = next;
        }
    private:
        T data;
        ListNode *link;
    };

    template <class T>
    class LinkedList {
    public:

        LinkedList(ListNode<T>* _first = nullptr) {
            first = _first;
        }

        void attach(ListNode<T>* element) {
            if(!first) {
                first = element;
            } else {
                ListNode<T> *temp = first;
                while(temp->link != nullptr) {
                    temp = temp->link;
                }
                temp->link = element;
            }
        }

        void print_from_tail2head() {
            std::stack<T> stack;
            ListNode<T> *temp = first;
            while(temp != nullptr) {
                stack.push(temp->data);
                temp = temp->link;
            }
            while(!stack.empty()) {
                std::cout<<stack.top()<<std::endl;
                stack.pop();
            }
        }

        void print() {
            ListNode<T> *temp = first;
            while(temp != nullptr) {
                std::cout << temp->data<<" ";
                temp = temp->link;
            }
            std::cout<<std::endl;
        }
    private:
        ListNode<T> *first;
    };
}
#endif