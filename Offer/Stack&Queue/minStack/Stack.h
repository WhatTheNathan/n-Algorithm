//
// Created by Nathan on 10/03/2018.
//

#ifndef _STACK_H
#define _STACK_H

namespace Nathan {
    template <class T>
    class Stack {
    public:
        Stack(int size);
        void push(T element);
        void pop();
        T Top() const;
        T minTop() const;
        bool isEmpty() const;
        bool isFull() const;
    private:
        T* stack;
        T* assistStack;
        int maxSize;
        int top;
    };

    template <class T>
    Stack<T>::Stack(int size) {
        maxSize = size;
        stack = new T[maxSize];
        assistStack = new T[maxSize];
        top = -1;
    }

    template <class T>
    bool Stack<T>::isEmpty() const {
        if (top == -1)
            return true;
        return false;
    }

    template <class T>
    bool Stack<T>::isFull() const {
        return !isEmpty();
    }

    template <class T>
    T Stack<T>::Top() const {
        if(isEmpty()) {

        } else {
            return stack[top];
        }
    }

    template <class T>
    T Stack<T>::minTop() const {
        if(isEmpty()) {

        } else {
            return assistStack[top];
        }
    }

    template <class T>
    void Stack<T>::push(T element) {
        int flag = -1;
        if(isEmpty() || element < assistStack[top]) {
            flag = 1;
        }
        top++;
        stack[top] = element;
        if(flag) {
            assistStack[top] = element;
        }
        else
            assistStack[top] = assistStack[top-1];
    }

    template <class T>
    void Stack<T>::pop() {
        if(isEmpty()) {
            return;
        }
        top--;
    }
}


#endif //_STACK_H
