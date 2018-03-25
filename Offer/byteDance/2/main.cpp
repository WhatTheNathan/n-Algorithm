#include <iostream>
#include <queue>
#include <map>

using namespace::std;
typedef pair<string,string> pairr;
map<pair<string,string> ,int> mp;

inline pairr firstOp(pairr p) {
    pairr p_1;
    p_1.second = p.first;
    p_1.first = p.first + p.first;
    return p_1;
}

inline pairr secondOp(pairr p) {
    pairr p_2;
    p_2.second = p.second;
    p_2.first = p.first + p.second;
    return p_2;
}

int main() {
    string s = "a";
    string m = s;

    int n;
    scanf("%d", &n);

    queue<pairr> q;
    q.push({s,m});
    mp[{s,m}] = 0;

    while(!q.empty()) {
        pairr p = q.front();
        q.pop();

        if(p.first.size() == n) {
            printf("%d\n",mp[p]);
            exit(0);
        }

        pairr p_1 = firstOp(p);
        if(!mp.count(p_1)) {
            q.push(p_1);
            mp[p_1] = mp[p] + 1;
        }

        pairr p_2 = secondOp(p);
        if(!mp.count(p_2)) {
            q.push(p_2);
            mp[p_2] = mp[p] + 1;
        }
    }
    return 0;
}
