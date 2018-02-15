#include <cmath>

#ifndef _Nathan_STACK_H
#define _Nathan_STACK_H

namespace Nathan {

    template <class T>
    class Stack {
    public:

        Stack(int maxStackSize)
            : maxSize(maxStackSize)
        {
            stack = new T[maxSize];
            top = -1;
        }

        ~Stack()
        {
            delete []stack;
        }

        bool isFull() const{
            if (top == maxSize - 1)
                return true;
            else return false;
        }

        bool isEmpty() const{
            if (top == -1)
                return true;
            else return false;
        }

        T& Top() const
        {
            if (isEmpty()) {

            }
            return stack[top];
        }

        void changeSize(T* a, const int oldSize, const int newSize)
        {
            if(newSize < 0) {
                return;
            } else {
                maxSize = newSize;
                T* temp = new T[maxSize];
                int number = fmin(oldSize,newSize);
                for(int i = 0; i < oldSize; i++) {
                    temp[i] = a[i];
                }
                a = temp;
            }
        }

        void push(const T& item) {
            top++;
            if(isFull()) {
                changeSize(stack, maxSize, maxSize * 2);
            }
            stack[top] = item;
        }

        T& pop() {
            if (isEmpty()) {

            } else {
                return stack[top--];
            }
        }

        int getSize() {
            return maxSize;
        }

    private:
        int top;
        T* stack;
        int maxSize;
    };

}
#endif














