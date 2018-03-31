/**
 * Description:
 * 输入一个递增排序的数组和一个数字s，在数组中查找两个数，
 * 使得它们的和正好是s。如果有多对数字的和等于s，输出任意一对即可。
 * 输入一个正数s，打印所有和为s的连续正数序列(至少含有两个数)。
 * 例如输入15，由于1+2+3+4+5 = 4+5+6 = 7+8 = 15
 */

#include <iostream>

using namespace::std;

void findNumsWithSum(int* nums, int low, int high, int sum, int &num_1, int &num_2) {
    if(!nums) {
        return;
    }
    while(low <= high) {
        int currentSum = nums[low] + nums[high];
        if(currentSum == sum) {
            num_1 = nums[low];
            num_2 = nums[high];
            return;
        } else if (currentSum < sum) {
            low++;
        } else {
            high--;
        }
    }
}

void printSequence(int small, int big) {
    for(int i = small; i <= big; i++) {
        cout<<i<<" ";
    }
    cout<<endl;
}

void findContainSequence(int sum) {
    if(sum < 3)
        return;
    int small = 1;
    int big = 2;
    int currentSum = small + big;
    while(small < (sum+1)/2) {
        if(currentSum == sum) {
            printSequence(small,big);
            currentSum -= small++;
        }
        else if (currentSum < sum) {
            big++;
            currentSum += big;
        } else {
            currentSum -= small++;
        }
    }
}

int main(){
    const int length = 6;
    int nums[length] = {1,2,4,7,11,15};
    int sum = 15;
    int num_1,num_2;
    findNumsWithSum(nums, 0, length-1,sum,num_1,num_2);
    findContainSequence(15);
}