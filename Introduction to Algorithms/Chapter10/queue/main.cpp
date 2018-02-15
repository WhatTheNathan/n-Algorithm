#include <iostream>
#include "queue.h"

using namespace::std;
using Nathan::Queue;

int main(){
    Queue<int> queue(10);

    queue.push(2);
    cout<<queue.front()<<endl;
    queue.push(2);
    int x = queue.pop();
    cout<<x<<endl;

    queue.push(2);
    queue.push(2);
    int y = queue.pop();
    cout<<y<<endl;
}