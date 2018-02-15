#ifndef _Nathan_QUEUE_H
#define _Nathan_QUEUE_H

namespace Nathan {

    template <class T>
    class Queue {
    public:
        Queue(int maxQueueSize)
            :maxSize(maxQueueSize)
        {
            queue = new T[maxSize];
            head = tail = 0;
            lastOp = -1;
        }

        ~Queue() {
            delete []queue;
        }

        bool isFull() const {
            if (tail == maxSize - 1) {
                return true;
            } else return false;
        }

        bool isEmpty() const {
            if (head == tail) {
                return true;
            } else return false;
        }

        void push(const T& item) {
            int k = (tail + 1) % maxSize;
            if (head == k) {

            } else {
                queue[tail] = item;
                tail = k;
            }
        }

        T& pop() {
            if (isEmpty()) {

            } else return queue[++head %= maxSize];
        }

        T& front() {
            return queue[head];
        }

    private:
        int head,tail;
        T* queue;
        int maxSize;
        int lastOp;   /* 1 means push, -1 means pop */
    };
}
#endif