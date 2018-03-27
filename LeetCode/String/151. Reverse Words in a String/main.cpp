#include <iostream>

using namespace::std;

class Solution {
public:

    void subReverseWords(string &s, int low, int high) {
        while(low < high) {
            swap(s[low++],s[high--]);
        }
    }

    void reverseWords(string &s) {
        int start = 0;
        int length = s.size();
        subReverseWords(s,start,length-1);

        int low=start,high=start;
        for(int i=0;i<=length;i++) {
            if(s[i] == ' ' || s[i] == '\0'){
                high = i - 1;
                subReverseWords(s,low,high);
                low = i + 1;
            }
        }
    }
};

int main(){
    Solution solution = Solution();
    string s = "the sky is blue";
    solution.reverseWords(s);
    cout<<s<<endl;
}