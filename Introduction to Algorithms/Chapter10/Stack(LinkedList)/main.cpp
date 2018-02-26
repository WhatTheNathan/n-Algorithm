#include <iostream>
#include "stack.h"

using namespace::std;
using Nathan::Stack;

int main(){
    Stack<int> stack;
    cout<<stack.isEmpty()<<endl;
    stack.push(1);
    cout<<stack.isEmpty()<<endl;
    cout<<"-----"<<endl;
    cout<<stack.Top()<<endl;
    cout<<stack.getSize()<<endl;
    stack.push(2);
    cout<<"-----"<<endl;
    cout<<stack.Top()<<endl;
    cout<<stack.getSize()<<endl;
    stack.push(3);
    cout<<"-----"<<endl;
    cout<<stack.Top()<<endl;
    cout<<stack.getSize()<<endl;
    stack.push(4);
    cout<<"-----"<<endl;
    cout<<stack.Top()<<endl;
    cout<<stack.getSize()<<endl;
}