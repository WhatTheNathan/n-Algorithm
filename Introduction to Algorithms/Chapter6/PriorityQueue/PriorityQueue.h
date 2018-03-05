#include <iostream>
#ifndef _Nathan_QUEUE_H
#define _Nathan_QUEUE_H

namespace Nathan {

    template <class T>
    class PriorityQueue {
    public:
        PriorityQueue(int capacity = 16);
        PriorityQueue(T *values, int size);

        int parent(int index);
        int left(int index);
        int right(int index);

        int getSize() const;
        T maximum() const;

        /* operations */
        void insert(const T &value);
        T extraxMax();

        void changeSize();
        void buildMaxHeap();
        void maxHeapify(int index);

        void print();

    private:
        T *_elements;
        int _size;
        int _capacity;
    };

    template <class T>
    PriorityQueue<T>::PriorityQueue(int capacity) {
        _capacity = (capacity > 0 ? capacity : 16);
        _elements = new T[_capacity + 1];
        _size = 0;
    }

    template <class T>
    PriorityQueue<T>::PriorityQueue(T *values, int size) {
        _size = _capacity = size;
        _elements = new T[_capacity + 1];
        for(int i = 0;i < _capacity; i++) {
            _elements[i + 1] = values[i];
        }
        buildMaxHeap();
    }

    template <class T>
    int PriorityQueue<T>::parent(int index) {
        return index / 2;
    }

    template <class T>
    int PriorityQueue<T>::left(int index) {
        return 2 * index;
    }

    template <class T>
    int PriorityQueue<T>::right(int index) {
        return 2 * index + 1;
    }

    template <class T>
    int PriorityQueue<T>::getSize() const {
        return _size;
    }

    template <class T>
    T PriorityQueue<T>::maximum() const {
        return _elements[1];
    }

    template <class T>
    T PriorityQueue<T>::extraxMax() {
        if (_size < 1)
            return nullptr;
        T max = _elements[1];
        _elements[1] = _elements[_size];
        maxHeapify(1);
        return max;
    }

    template <class T>
    void PriorityQueue<T>::changeSize() {
        T *temp = new T[_capacity * 2 + 1];
        std::copy(_elements,_elements+_capacity+1,temp);
        delete[] _elements;
        _elements = temp;
    }

    // 时间复杂度为O(n)
    template <class T>
    void PriorityQueue<T>::maxHeapify(int index) {
        int l = left(index);
        int r = right(index);
        int largest = 0;
        if(l <= _size && _elements[l] > _elements[index])
            largest = l;
        else largest = index;
        if(r <= _size && _elements[r] > _elements[largest])
            largest = r;
        if(largest != index) {
            T temp = _elements[largest];
            _elements[largest] = _elements[index];
            _elements[index] = temp;
            maxHeapify(largest);
        }
    }

    template <class T>
    void PriorityQueue<T>::buildMaxHeap() {
        for(int i = _size / 2; i >= 1; i--) {
            maxHeapify(i);
        }
    }

    template <class T>
    void PriorityQueue<T>::insert(const T &value) {
        if(_size == _capacity)
            changeSize();
        int currentIndex = ++_size;
        while(currentIndex != 1 && _elements[currentIndex/2] < value) {
            _elements[currentIndex] = _elements[currentIndex/2];
            currentIndex /= 2;
        }
        _elements[currentIndex] = value;
    }

    template <class T>
    void PriorityQueue<T>::print() {
        for(int i = 0; i < _size; i++)
            std::cout<<_elements[i+1]<<" ";
        std::cout<<std::endl;
    }

}
#endif