#include <iostream>
#include <algorithm>
#include <string>

using namespace::std;

bool is3(unsigned long long num){
    if(num % 3 == 0)
        return true;
    return false;
}

int main() {
    int l,r;

    scanf("%d%d", &l, &r);

    string s[r+1];
    s[1] = "1";
    for(int i=2;i<=r;i++) {
        s[i] = s[i-1] + to_string(i);
    }

    int ans = 0;

    for(int i=l;i<=r;i++) {
        unsigned long long sum = 0;
        for(int j=0;j<s[i].size();j++){
            sum += (s[i][j] - '0');
        }
        if(is3(sum))
            ans++;
    }
    printf("%d",ans);
    return 0;
}

