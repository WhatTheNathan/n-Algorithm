#include <iostream>
using namespace::std;

void swap(int a,int b) {
    int c = b;
    b = a;
    a = c;
}

/*
 * 总是选择A[r]作为pivot element
 * i为小于A[r]的元素的指针
 * j为大于A[r]的元素的指针
 */
int partion(int* A, int low, int high) {
    int pivot = A[high];
    int smallP = low - 1; // 初始值
    for(int i = low; i < high; i++) {
        if(A[i] < pivot) {
            smallP++;
            /* 小于A[r]的元素交换 */
            swap(A[smallP],A[i]);
        }
    }
    /* 将A[r]交换到中间的位置 */
    swap(A[smallP+1],A[high]);
    return smallP + 1;
}


void quickSort(int* A, int low,int high) {
    if(low < high) {
        int mid = partion(A,low,high);
        quickSort(A,low,mid-1);
        quickSort(A,mid+1,high);
    }
}

int main(){
    const int length = 6;
    int A[] = {4,2,3,7,1,90};
    quickSort(A,0,length-1);
    for(int i = 0; i < length; i++)
        cout<<i<<" ";
    cout<<endl;
}