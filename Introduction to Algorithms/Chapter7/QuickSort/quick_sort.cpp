#include <iostream>
#include <vector>
using namespace::std;

void swap(int &a,int &b) {
    int c = b;
    b = a;
    a = c;
}

/*
 * 总是选择A[r]作为pivot element
 * i为小于A[r]的元素的指针
 * j为大于A[r]的元素的指针
 */
int partion(vector<int> &A, int p, int r) {
    int pivot = A[r];
    int smallP = p - 1;
    for(int i = p; i < r; i++) {
        if(A[i] < pivot) {
            smallP++;
            /* 小于A[r]的元素交换 */
            swap(A[smallP],A[i]);
        }
    }
    /* 将A[r]交换到中间的位置 */
    swap(A[smallP+1],A[r]);
    return smallP + 1;
}


void quickSort(vector<int> &A, int p,int r) {
    if(p < r) {
        int q = partion(A,p,r);
        quickSort(A,p,q-1);
        quickSort(A,q+1,r);
    }
}

int main(){
    vector<int> A = {4,2,3,7,1,90};
    quickSort(A,0,5);
    for(auto element: A){
        cout<<element<<endl;
    }
}