/**
 * Description:
 * 写一个函数，输入n，求斐波那契数列的第n项
 */

#include <iostream>

using namespace::std;

long long RecursionFibonacci(unsigned int n) {
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;
    return RecursionFibonacci(n - 1) + RecursionFibonacci(n - 2);
}

long long iterationFibonacci(unsigned int n) {
    int result[2] = {0,1};
    if(n < 2)
        return result[n];
    long long fib_1 = 0;
    long long fib_2 = 1;
    long long fibN = 0;
    for(unsigned int i = 1; i <= n; i++){
        fibN = fib_1 + fib_2;
        fib_2 = fib_1;
        fib_1 = fibN;
    }
    return fibN;
}

int main(){
    cout<<RecursionFibonacci(5)<<endl;
    cout<<iterationFibonacci(8)<<endl;
}