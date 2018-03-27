#include <iostream>
#include <map>
#include <algorithm>

using namespace::std;
int job[100000];
int person[100000];
map<int,int> mapp;

int binarySearch(int* nums, int x, int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        if(nums[mid] == x) return mid;
        else if(nums[mid] < x) return binarySearch(nums,x,mid+1,high);
        else return binarySearch(nums,x,low,mid-1);
    }
    while(nums[low] > x)
        low--;
    return low;
}

// 存在难度低，但报酬高
// 存在一样难度的工作，会覆盖hash表的值
int chooseJob(int ability, int* job,int N) {
    int index = binarySearch(job,ability,0,N);
    int ans = 0;
    while(index >= 0) {
        if(mapp[job[index]] > ans) {
            ans = mapp[job[index]];
        }
        index--;
    }
    return ans;
}

int main() {
    int N,M;

    scanf("%d%d", &N, &M);

    for(int i=0;i<N;i++){
        scanf("%d",&job[i]);
        int pay;
        scanf("%d",&pay);
        mapp[job[i]] = pay;
    }
    sort(job,job+N);

    for(int i=0;i<M;i++){
        scanf("%d",&person[i]);
    }

    for(int i=0;i<M;i++){
        printf("%d\n", chooseJob(person[i],job,N));
    }
    return 0;
}

