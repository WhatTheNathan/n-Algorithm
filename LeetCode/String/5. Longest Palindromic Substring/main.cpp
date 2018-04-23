#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string ans;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                dp[i][j] = ( s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1]) );
                if (dp[i][j] && j + 1 - i > ans.length()) {
                    ans = s.substr(i, j + 1 - i);
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution solution = Solution();
    cout<<solution.longestPalindrome("abcba")<<endl;
}