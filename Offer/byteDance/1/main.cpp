#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

/*
 * 在n个元素的数组中，找到差值为k的数组对去重后个数
 * 第一行,n和k，n表示数字个数，k表示差值
 * 第二行，n个正整数
 * 5 2
 * 1 5 3 4 2
 */

int main() {
    int n,k;
    int* nums;
    cin >> n >> k;
    int value;
    nums = new int[n];
    for(int i = 0; i < n; i++){
        cin >> value;
        nums[i] = value;
    }

    sort(nums,nums+n);
    n = unique(nums,nums + n) - nums;
    int j = 0, sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            while( j < n && nums[j] - nums[i] < k)
                j++;
            if(j == n) break; // 可提前结束
            if(nums[j] - nums[i] == k)
                sum++;
        }
    }
    cout<<sum<<endl;
}

