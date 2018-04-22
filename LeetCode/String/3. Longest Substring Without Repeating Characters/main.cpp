#include <iostream>
#include <map>

using namespace::std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mapp;
        int start = -1;
        int maxLength = 0;

        for(int i = 0; i < s.size(); i++) {
            if(mapp.count(s[i])) {
                start = max(start, mapp[s[i]]);
            }
            mapp[s[i]] = i;
            maxLength = max(maxLength, i - start);
        }
        return maxLength;
    }
};

int main(){
    Solution solution = Solution();
    cout<<solution.lengthOfLongestSubstring("abcabcbb")<<endl;
}