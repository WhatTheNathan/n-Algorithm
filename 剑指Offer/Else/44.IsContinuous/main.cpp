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
int numbsers = 5;

bool isContinuous(int* nums) {
    if(!nums)
        return false;
    sort(nums,nums+numbsers);
    int numsOf0 = 0;
    int minus = 0;
    for(int i = 0; i < numbsers; i++) {
        if(nums[i] == 0) {
            numsOf0++;
        }
        if(i) {
            // 有差值
            if(nums[i] - nums[i-1] > 1 && nums[i-1] != 0) {
                minus += 1;
            }
            // 有重复
            if(nums[i] - nums[i-1] == 0 && nums[i] != 0) {
                return false;
            }
        }
    }
    if(minus == numsOf0 || minus == 0) {
        return true;
    }
    return false;
}

int main() {
    int test[5] = {5,6,8,7,4};
    cout<<isContinuous(test)<<endl;
}
