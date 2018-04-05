/**
 * Description:
 * 在一个长度为n的数组里的所有数字都在0~n-1的范围内。数组中某些数字是重复的。
 * 请找出数组中的任意一个重复的数字。
 * 例如，如果输入长度为7的数组{2,3,1,0,2,5,3},那么对应的输出是重复的数字2或者3。
 */

#include <iostream>

using namespace::std;

int duplicate(int* nums, int length) {
    if(!nums || length <= 0) {
        return -1;
    }
    // 自己写的时候少了这个检查循环
    for(int i = 0; i < length; i++) {
        if(nums[i] < 0 || nums[i] > length - 1)
            return -1;
    }
    for(int i = 0; i < length; i++) {
        while(nums[i] != i) {
            if(nums[nums[i]] == nums[i]) {
                return nums[i];
            }else {
                swap(nums[nums[i]],nums[i]);
            }
        }
    }
    return -1;
}

int main(){
    const int length = 7;
    int nums[length] = {2,3,1,0,2,5,3};
    cout<<duplicate(nums,length)<<endl;
}