/**
 * Description:
 * 在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
 * 输入一个数组，求出这个数组中的逆序对的总数。
 */

#include <iostream>

int inversePairsCore(int* nums, int* copy, int low, int high) {
    if(low == high) {
        copy[low] = nums[low];
        return 0;
    }
    int mid = (low + high) / 2;
    int leftPairs = inversePairsCore(copy,nums, low , mid);
    int rightPairs = inversePairsCore(copy,nums, mid + 1, high);
    int count = 0;
    int leftP = mid;
    int rightP = high;
    int indexCopy = high;

    while(leftP >= low && rightP >= mid+1) {
        if(nums[leftP] > nums[rightP]) {
            copy[indexCopy--] = nums[leftP--];
            count += (rightP - mid);
        }
        else {
            copy[indexCopy--] = nums[rightP--];
        }
    }
    while(leftP>=low) { copy[indexCopy--] = nums[leftP--]; }
    while(rightP>=mid+1) { copy[indexCopy--] = nums[rightP--]; }
    return leftPairs + rightPairs + count;
}

using namespace::std;
int inversePairs(int* nums,int length) {
    if(!nums || length < 0) {
        return 0;
    }
    int* copy = new int[length];
    for(int i = 0; i < length; i++) {
        copy[i] = nums[i];
    }
    int count = inversePairsCore(nums,copy,0,length-1);
    delete[] copy;
    
    return count;
}

int main(){
    const int length = 5;
    int nums[length] = {4,7,3,2,2};
    cout<<inversePairs(nums,length)<<endl;
}