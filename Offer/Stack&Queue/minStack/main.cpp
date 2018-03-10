/**
 * Description:
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min函数。
 * 在该栈中，调用min、push及pop的时间复杂度都是O(1)
 */

#include <iostream>
#include "Stack.h"

using namespace::std;
using Nathan::Stack;

int main(){
    Stack<int> stack(10);
    stack.push(10);
    stack.push(4);
    stack.push(7);
    cout<<stack.Top()<<endl;
    cout<<stack.minTop()<<endl;
    stack.push(12);
    stack.pop();
    stack.pop();
    stack.pop();
    cout<<stack.Top()<<endl;
    cout<<stack.minTop()<<endl;
}