#include <iostream>

using namespace::std;

const int length = 8;
int *B =  new int(length);

void merge(int* A,int low,int mid,int high){
    // 将A中元素复制到B中
    for(int i = low; i <= high; i++) {
        B[i] = A[i];
    }
    int i = low, j = mid + 1;
    int k = i;
    for(; i <= mid && j <= high; k++) {
        if(B[i] < B[j])
            A[k] = B[i++];
        else
            A[k] = B[j++];
    }
    while(i <= mid) A[k++] = B[i++];
    while(j <= high) A[k++] = B[j++];
}

void merge_sort(int A[],int low,int high){
    if(low<high){
        int mid = (low+high)/2;
        merge_sort(A,low,mid);
        merge_sort(A,mid + 1,high);
        merge(A,low,mid,high);
    }
}

int main(){
    int instance[] = {2,4,5,7,1,2,3,6};
    merge_sort(instance,0,7);
    for(int i = 0;i < length; i++)
        cout<<instance[i]<<" ";
    cout<<endl;
}