#include <iostream>
#include <map>

using namespace::std;

class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
};

int main(){
    Solution solution = Solution();
    cout<<solution.reverse(-123)<<endl;
}