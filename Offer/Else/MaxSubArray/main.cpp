/**
 * Description:
 * 输入一个整型数组，数组里有正数也有负数。数组中一个或连续的多个整数组成了一个子数组。
 * 求所有子数组的和的最大值。要求O(n)
 */

#include <iostream>

using namespace::std;
/* 分治法 nlog(n)
int findmaxCrossSumOfSubArray(int* numbers, int low, int mid, int high) {
    int leftSum = INT_MIN;
    int sum = 0;
    for(int i = mid; i >= low; i--) {
        sum += numbers[i];
        if(sum > leftSum) {
            leftSum = sum;
        }
    }

    int rightSum = INT_MIN;
    sum = 0;
    for(int i = mid + 1; i <= high; i++) {
        sum += numbers[i];
        if(sum > rightSum){
            rightSum = sum;
        }
    }
    return leftSum + rightSum;
}

int max(int a, int b, int c) {
    int d = a > b ? a : b;
    return d > c ? d : c;
}

int maxSumOfSubArray(int* numbers, int low, int high) {
    if(!numbers || low < 0 || high < 0 || low > high)
        return 0;
    if(low == high)
        return numbers[low];
    int mid = (low + high) / 2;
    int leftMaxSum = maxSumOfSubArray(numbers, low, mid);
    int rightMaxSum = maxSumOfSubArray(numbers, mid + 1 ,high);
    int crossMaxSum = findmaxCrossSumOfSubArray(numbers,low,mid,high);
    return max(leftMaxSum,rightMaxSum,crossMaxSum);
}
 */

int main() {
    const int length = 8;
    int numbers[] = {1,-2,3,10,-4,7,2,-5};
//    cout<<maxSumOfSubArray(numbers,0,length - 1)<<endl;
    
}
