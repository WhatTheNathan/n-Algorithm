/**
 * Description:
 * 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
 * 其中B中的元素B[i] = A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法
 */

#include <iostream>

using namespace::std;

void multiply(int* A, int* B, int length) {
    if(length <= 1) {
        return;
    }
    // 自己写的时候是完全构造了新数组C和D,然而更剩空间的是直接用数组B来操作
//    int C[length];
//    int D[length];
//    C[0] = 1;
//    for(int i = 1; i < length; i++) {
//        C[i] = A[i-1] * C[i-1];
//    }
//    D[length-1] = 1;
//    for(int i = length-2; i >= 0; i--) {
//        D[i] = A[i+1] * D[i+1];
//    }
//    for(int i = 0; i < length; i++) {
//        B[i] = C[i] * D[i];
//    }
    B[0] = 1;
    for(int i = 1; i < length; i++) {
        B[i] = A[i-1] * B[i-1];
    }
    int temp = 1;
    for(int i = length-2; i >= 0; i--) {
        temp *= A[i+1];
        B[i] *= temp;
    }
}

int main(){
    const int length = 5;
    int A[length] = {1,2,3,4,5};
    int B[length] = {};
    multiply(A,B,length);
    for(int i = 0; i < length; i++) {
        cout<<B[i]<<endl;
    }
}