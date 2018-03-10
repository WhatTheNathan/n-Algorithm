/**
 * Description:
 * 输入两个证书序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
 * 假设压入栈的所有数字均不相等。
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace::std;

bool isPopOrder(vector<int> inOder, vector<int> outOrder) {
    if( (inOder.size() != outOrder.size()) || inOder.size() == 0 )
        return false;

    stack<int> stack;
    int inP = 0;
    int outP = 0;

    while(inP != inOder.size()) {
        int element = inOder[inP++];
        stack.push(element);
        if(element == outOrder[outP]) {
            outP++;
            stack.pop();
        }
    }
    while(!stack.empty()) {
        if(stack.top() == outOrder[outP]) {
            outP++;
            stack.pop();
        }else break;
    }
    if(outP == outOrder.size())
        return true;
    return false;
}

int main(){
    vector<int> inOrder = {1};
    vector<int> outOder = {1};
    cout<<isPopOrder(inOrder,outOder)<<endl;
}