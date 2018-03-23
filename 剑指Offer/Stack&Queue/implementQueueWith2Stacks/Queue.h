//
// Created by Nathan on 28/02/2018.
//

#include <stack>

#ifndef IMPLEMENTQUEUEWITH2STACKS_QUEUE_H
#define IMPLEMENTQUEUEWITH2STACKS_QUEUE_H

template <class T>
class Queue {
public:
    Queue();
    void appendTail(T data);
    void deleteHead();
private:
    std::stack<T> stack_1;
    std::stack<T> stack_2;
};

template <class T>
Queue<T>::Queue() {

}

template <class T>
void Queue<T>::appendTail(T data) {
    stack_1.push(data);
}

template <class T>
void Queue<T>::deleteHead() {
    if (stack_2.empty()) {
        while(!stack_1.empty()) {
            T temp = stack_1.top();
            stack_1.pop();
            stack_2.push(temp);
        }
    }
    if (stack_2.empty())
        return;
    stack_2.pop();
}

#endif //IMPLEMENTQUEUEWITH2STACKS_QUEUE_H
