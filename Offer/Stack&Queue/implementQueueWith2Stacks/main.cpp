/**
 * Description:
 * 用两个栈实现一个队列，队列的声明如下，实现appendTail和deleteHead。
 */

#include <iostream>
#include "Queue.h"

using namespace::std;

int main(){
    Queue<int> queue;
    queue.appendTail(3);
    queue.deleteHead();
}