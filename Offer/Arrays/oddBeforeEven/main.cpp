/**
 * Description:
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分
 * 所有偶数位于数组的后半部分。
 */

#include <iostream>
#include <vector>

using namespace::std;

bool isOdd(int num) {
    if(num % 2 > 0)
        return true;
    return false;
}

bool isEven(int num) {
    return !isOdd(num);
}

void swap(int &a, int &b) {
    int temp = b;
    b = a;
    a = temp;
}

void evenBeforeOdd(vector<int> &A, int n) {
    if(n <= 1)
        return;
    int left = 0;
    int right = n - 1;

    while(left < right) {
        while(!isEven(A[left]) && left < n)
            left++;
        while(!isOdd(A[right]) && right > 0)
            right--;
        if(left < right) {
            swap(A[left],A[right]);
        }
    }

}

int main(){
    vector<int> A = {1,2,3,4,5};
    evenBeforeOdd(A, 5);
    for(auto i: A) {
        cout<<i<<endl;
    }
}