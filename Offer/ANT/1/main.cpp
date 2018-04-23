#include <iostream>
#include <vector>

using namespace::std;

//8.10张图，屏幕上，怎样让两列的高度差最小(内推的笔试题...)
//dp问题，转化为求数组的一个子集，使得整个子集中的元素的和尽可能接近sum/2，其中sum为数组中所有元素的和。

void solution(int* array, int length, int sum) {
    vector<vector<int>> dp;
    for (int i = 0; i <= sum / 2; i++) {
        vector<int>tmp;
        for (int j = 0; j <= length; j++) {
            tmp.push_back(0);
        }
        dp.push_back(tmp);
    }

    for(int i = 1; i <= sum/2; i++) {
        for(int j = 1; j <= length; j++) {
            if(i >= array[j-1]) {
                dp[i][j] = max(dp[i-array[j-1]][j-1] + array[j-1], dp[i][j-1]);
            } else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }

    cout<<dp[sum/2][length]<<endl;
}

int main() {
    const int length = 10;
    int array[length] = {1,2,3,4,5,6,7,8,9,10};
    int sum = 0;
    for(int i = 0; i < length; i++) {
        sum += array[i];
    }
    solution(array,length,sum);
}

