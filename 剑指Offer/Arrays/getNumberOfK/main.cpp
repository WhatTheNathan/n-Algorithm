/**
 * Description:
 * 统计一个数字在排序数组中出现的次数。
 * 例如输入排序数组{1,2,3,3,3,3,4,5}和数字3，由于3在这个数组中出现了4次，因此输出4。
 */

#include <iostream>

using namespace::std;

int getFirstK(int* nums, int k, int low, int high) {
    if(low <= high) {
        int mid = (low + high) / 2;
        if(nums[mid] == k) {
            if( (nums[mid - 1] != k && mid > 0) || mid == 0)
                return mid;
            else return getFirstK(nums,k,low,mid-1);
        }
        else if(nums[mid] < k) return getFirstK(nums,k,mid+1,high);
        else return getFirstK(nums,k,low,mid-1);
    }
    return -1;
}

int getLastK(int* nums, int k, int low, int high) {
    if(low <= high) {
        int mid = (low + high) / 2;
        if(nums[mid] == k) {
            if( nums[mid + 1] != k || mid == high )
                return mid;
            else return getLastK(nums,k,mid+1,high);
        }
        else if(nums[mid] > k) return getLastK(nums,k,low,mid-1);
        else return getLastK(nums,k,mid+1,high);
    }
    return -1;
}

int getNumberOfK(int* nums, int k, int low, int high) {
    if(!nums || low > high || low < 0 || high < 0)
        return 0;
    int count = 0;
    int indexOfFirstK = getFirstK(nums,k,low,high);
    int indexOfLastK = getLastK(nums,k,low,high);
    if(indexOfFirstK != -1 && indexOfLastK != -1) {
        count = indexOfLastK - indexOfFirstK + 1;
    }
    return count;
}

int main(){
    const int length = 4;
    int nums[length] = {1,4,6,9};
    int k = 1;
    cout<<getNumberOfK(nums,k,0,length-1)<<endl;
}