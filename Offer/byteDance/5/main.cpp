#include <iostream>
#include <queue>

using namespace::std;
// 当前高度,当前跳的次数
typedef pair<int,int> pair;
int* stages;
bool* visited;

// BFS搜索，因为存在跳跃策略选择的情况，比如 1,5,7的阶梯, H为10
// 还他妈的可以向下跳，比如 1,4,5,7的阶梯, H为5
int main() {
    int N,K,H;

    scanf("%d%d%d", &N, &K, &H);

    stages = new int[N];
    visited = new bool[N];

    int value;
    for(int i = 0 ;i < N; i++) {
        scanf("%d", &value);
        stages[i] = 1;
    }

    queue<pair> queue;
    queue.push({0,0});
    int ans = 0;

    while(!queue.empty()) {
        pair p = queue.front();
        queue.pop();

        // 次数超越
        if(p.second > K)
            break;

        ans = max(ans, p.first);

        for(int i = 1; i <= H; i++) {
            if( stages[p.first + i] && !visited[p.first + 2 * i]) {
                visited[p.first + 2 * i] = true;
                queue.push( make_pair(p.first + 2 * i, p.second + 1) );
            }
            if( p.first - 2 * i > 0 && stages[p.first - i] && !visited[p.first - 2 * i]) {
                visited[p.first - 2 * i] = true;
                queue.push( make_pair(p.first - 2 * i, p.second + 1) );
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}

