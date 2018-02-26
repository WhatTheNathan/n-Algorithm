#include <cmath>
#include "LinkedList.h"

#ifndef _Nathan_STACK_H
#define _Nathan_STACK_H

namespace Nathan {

    template <class T>
    class Stack {
    public:

        Stack<T>() {
            list = LinkedList<T>();
        }

        bool isEmpty(){
            return list.isEmpty();
        }

        T Top()
        {
            if (isEmpty()) {

            }
            return list.tail();
        }

        void push(const T& item) {
            ListNode<T> *node = new ListNode<T>(item,nullptr);
            list.insertTail(node);
        }

        T& pop() {
            if (isEmpty()) {

            } else {
                list.removeTail();
            }
        }

        int getSize() {
            return list.getSize();
        }

    private:
        LinkedList<T> list;
    };

}
#endif














