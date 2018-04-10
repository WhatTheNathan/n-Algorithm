/**
 * Description:
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增数组的一个旋转，输出旋转数组的最小元素
 * 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1.
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace::std;

int minInOrder(vector<int> A, int left,int right) {
    int min = INT_MAX;
    for(int i = left; i <= right; i++){
        if(A[i] <= min){
            min = A[i];
        }
    }
    return min;
}

int findMinInSpinArray(vector<int> A, int left,int right) {
    if(A[left] < A[right])
        return A[left];
    if (right - left == 1)
        return min(A[left],A[right]);

    int middle = (left + right) / 2;
    if( A[middle] > A[left] )
        return findMinInSpinArray(A,middle,right);
    else if( A[middle < A[right]])
        return findMinInSpinArray(A,left,middle);
    else if(A[left] == A[right] && A[left] == A[middle])
        return minInOrder(A,left,right);
}

int main(){
    vector<int> A = {5,1,2,3,4};
    cout<<findMinInSpinArray(A,0,4);
}