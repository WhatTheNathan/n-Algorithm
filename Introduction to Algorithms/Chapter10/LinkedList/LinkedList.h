#include <iostream>

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

        ListNode<T> search(T element) {
            ListNode<T> *temp = first;
            while(temp->link != nullptr) {
                if (temp->data == element) {
                    return temp;
                }
                temp = temp->link;
            }
            return nullptr;
        }

        void invert() {
            ListNode<T> *p = first, *q = nullptr;
            while (p != nullptr) {
                ListNode<T> *r = q;
                q = p;
                p = p->link;
                q->link = r;
            }
            first = q;
        }

        void print() {
            ListNode<T> *temp = first;
            while(temp->link != nullptr) {
                std::cout << temp->data<<" ";
                temp = temp->link;
            }
            std::cout<<temp->data<<std::endl;
        }
    private:
        ListNode<T> *first;
    };
}
#endif