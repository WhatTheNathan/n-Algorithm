//
// Created by Nathan on 05/03/2018.
//

#include "MaxHeap.h"

using nathan::MaxHeap;

int main() {
    int array[] = {4,1,3,2,16,9,10,14,8,7};
    int size = 10;
    MaxHeap<int> heap = MaxHeap<int>(array,size);
//    heap.print();
//    heap.buildMaxHeap();
//    heap.print();

    heap.heapSort();
}


