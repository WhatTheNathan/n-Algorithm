/**
 * Description:
 * 在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
 * 输入一个数组，求出这个数组中的逆序对的总数。
 */

#include <iostream>

using namespace::std;

int inversePairs(int* nums ,int low, int high) {
    if(!nums || low >= high)
        return 0;
    int mid = (low + high) / 2;
    int leftPairs = inversePairs(nums, low , mid);
    int rightPairs = inversePairs(nums, mid + 1, high);
    int count = 0;

    int leftP = mid;

    while(leftP >= low) {
        for(int rightP = high; rightP >= mid + 1; rightP--) {
            if(nums[leftP] > nums[rightP]){
                count++;
            }
        }
        leftP--;
    }
    return leftPairs + rightPairs + count;
}

int main(){
    const int length = 5;
    int nums[length] = {4,7,3,2,2};
    cout<<inversePairs(nums,0,length - 1)<<endl;
}