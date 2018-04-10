#include <iostream>
#include <queue>

using namespace::std;

typedef pair<int,int> pairr; // 当前index,当前跳跃次数
int main() {
    int n;
    int* nums;
    scanf("%d",&n);
    nums = new int[n];
    int value;
    for(int i = 0; i < n; i++) {
        scanf("%d",&value);
        nums[i] = value;
    }

    queue<pairr> q;
    q.push({0,0});
    int ans = INT_MAX;
    while(!q.empty()) {
        pairr current = q.front();
        q.pop();
        if(current.second < ans && current.first == n-1) {
            ans = current.second;
        }
        for(int i = 1; i <= nums[current.first]; i++) {
            if(current.first+i <= n-1 )
                q.push({current.first+i,current.second+1});
        }
    }
    printf("%d",ans);
    return 0;
}

