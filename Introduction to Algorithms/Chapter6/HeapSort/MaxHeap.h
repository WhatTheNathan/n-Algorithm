//
// Created by Nathan on 05/03/2018.
// 时间复杂度为nlgn,。最大堆许多基本操作至多与树的高度成正比
//

#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

#ifndef INSERT_SORT_MAXHEAP_H
#define INSERT_SORT_MAXHEAP_H


namespace nathan {
    template <class T>
    class MaxHeap {
    public:
        MaxHeap(int capacity = 16);
        MaxHeap(T *values, int size);

        int parent(int index);
        int left(int index);
        int right(int index);

        int getSize() const;
        T top() const;

        /* operations */
        void maxHeapify(int index);
        void buildMaxHeap();
        void push(const T &value);
        void changeSize();
        void heapSort();

        void print();

    private:
        T *_elements;
        int _size;
        int _capacity;
    };

    template <class T>
    MaxHeap<T>::MaxHeap(int capacity) {
        _capacity = (capacity > 0 ? capacity : 16);
        _elements = new T[_capacity + 1];
        _size = 0;
    }

    template <class T>
    MaxHeap<T>::MaxHeap(T *values, int size) {
        _size = _capacity = size;
        _elements = new T[_capacity + 1];
        for(int i = 0;i < _capacity; i++) {
            _elements[i + 1] = values[i];
        }
    }

    template <class T>
    int MaxHeap<T>::parent(int index) {
        return index / 2;
    }

    template <class T>
    int MaxHeap<T>::left(int index) {
        return 2 * index;
    }

    template <class T>
    int MaxHeap<T>::right(int index) {
        return 2 * index + 1;
    }

    template <class T>
    int MaxHeap<T>::getSize() const {
        return _size;
    }

    template <class T>
    T MaxHeap<T>::top() const {
        return _elements[1];
    }

    template <class T>
    void MaxHeap<T>::changeSize() {
        T *temp = new T[_capacity * 2 + 1];
        std::copy(_elements,_elements+_capacity+1,temp);
        delete[] _elements;
        _elements = temp;
    }

    // 时间复杂度为O(n)
    template <class T>
    void MaxHeap<T>::maxHeapify(int index) {
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
    void MaxHeap<T>::buildMaxHeap() {
        for(int i = _size / 2; i >= 1; i--) {
            maxHeapify(i);
        }
    }

    template <class T>
    void MaxHeap<T>::push(const T &value) {
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
    void MaxHeap<T>::print() {
        for(int i = 0; i < _size; i++)
            std::cout<<_elements[i+1]<<" ";
        std::cout<<std::endl;
    }

    template <class T>
    void MaxHeap<T>::heapSort() {
        // 先构建最大堆
        buildMaxHeap();
        for(int i = _size; i >= 2; i--) {
            T temp = _elements[1];
            _elements[1] = _elements[i];
            _elements[i] = temp;
            std::cout<<_elements[_size]<<" ";
            _size--;
            maxHeapify(1);
        }
        std::cout<<std::endl;
    }

}

#endif //INSERT_SORT_MAXHEAP_H
