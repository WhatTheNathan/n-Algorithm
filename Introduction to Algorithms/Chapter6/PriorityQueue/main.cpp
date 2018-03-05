#include <iostream>
#include "PriorityQueue.h"

using namespace::std;
using Nathan::PriorityQueue;

int main(){
    PriorityQueue<int> queue(10);
    queue.insert(16);
    queue.insert(7);
    queue.insert(8);
    queue.insert(9);
    queue.insert(3);
    queue.insert(14);
    queue.insert(10);
    queue.print();

}