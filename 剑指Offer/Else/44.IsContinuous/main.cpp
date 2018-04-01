/**
 * Description:
 * 从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
 * 2~10为数字本身，A为1，J为11，Q为12，K为13，而大、小王可以看成任意数字。
 */

#include <iostream>
#include <iomanip>

using namespace::std;

// 大小王为0
int poker[14] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
int length = 5;

bool isContinuous(int* nums) {
    if(!nums)
        return false;
    sort(nums,nums+length);
    int numsOf0 = 0;
    int numsOfGap = 0;

    for(int i = 0; i < length && nums[i] == 0; i++) {
        numsOf0++;
    }

    int small = numsOf0;
    int big = small + 1;

    while(big < length) {
        int gap = nums[big] - nums[small];
        if(gap == 0) {
            return false;
        }
        numsOfGap += (gap - 1);
        small = big;
        big++;
    }
    return (numsOfGap > numsOf0) ? false : true;
}

int main() {
    int test[5] = {0,2,4,5,6};
    cout<<isContinuous(test)<<endl;
}
