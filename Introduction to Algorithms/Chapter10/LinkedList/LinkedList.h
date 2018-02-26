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

        LinkedList(ListNode<T>* firstVal = nullptr) {
            _first = firstVal;
            if (_first != nullptr)
                size = 1;
        }

        bool isEmpty() {
            return getSize() == 0;
        }

        int getSize() {
            return size;
        }

        void insertTail(ListNode<T>* element) {
            if(!_first) {
                _first = element;
            } else {
                ListNode<T> *temp = _first;
                while(temp->link != nullptr) {
                    temp = temp->link;
                }
                temp->link = element;
            }
            size++;
        }

        void removeHead() {
            if (!_first)
                return;
            ListNode<T> *temp = _first;
            _first = _first->link;
            delete temp;
        }

        void removeTail() {
            ListNode<T> *tail = _first;
            ListNode<T> *temp;
            while(tail->link != nullptr) {
                temp = tail;
                tail = tail->link;
            }
            temp->link = nullptr;
        }

        T head() {
            return _first->data;
        }

        T tail() {
            ListNode<T> *temp = _first;
            while(temp->link != nullptr) {
                temp = temp->link;
            }
            return temp->data;
        }

        ListNode<T> search(T element) {
            ListNode<T> *temp = _first;
            while(temp->link != nullptr) {
                if (temp->data == element) {
                    return temp;
                }
                temp = temp->link;
            }
            return nullptr;
        }

        void invert() {
            ListNode<T> *p = _first, *q = nullptr;
            while (p != nullptr) {
                ListNode<T> *r = q;
                q = p;
                p = p->link;
                q->link = r;
            }
            _first = q;
        }

        void print() {
            ListNode<T> *temp = _first;
            while(temp->link != nullptr) {
                std::cout << temp->data<<" ";
                temp = temp->link;
            }
            std::cout<<temp->data<<std::endl;
        }
    private:
        ListNode<T> *_first;
        int size = 0;
    };
}
#endif