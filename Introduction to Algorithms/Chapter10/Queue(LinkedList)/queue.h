#include "LinkedList.h"

#ifndef _Nathan_QUEUE_H
#define _Nathan_QUEUE_H

namespace Nathan {

    template <class T>
    class Queue {
    public:
        Queue<T>() {
            list = LinkedList<T>();
        }

        bool isEmpty() {
            return list.isEmpty();
        }

        void push(const T& item) {
            ListNode<T> *node = new ListNode<T>(item, nullptr);
            list.insertTail(node);
        }

        T& pop() {
            T value = list.head();
            list.removeHead();
            return value;
        }

        T front() {
            return list.head();
        }

    private:
        LinkedList<T> list;
    };
}
#endif