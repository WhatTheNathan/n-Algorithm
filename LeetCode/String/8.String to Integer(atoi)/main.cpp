#include <iostream>

using namespace::std;

class Solution {
public:
    int myAtoi(char* str) {
        if(!str)
            return 0;
        int i = 0, sign = 1;
        long ans = 0;
        while(str[i] == ' ') { i++; }
        if(str[i] == '-' || str[i] == '+') {
            sign = (str[i++] == '-') ? -1 : 1;
        }

        while(str[i] >= '0' && str[i] <='9') {
            ans = 10 * ans + (str[i++] - '0');
            if(ans * sign >= INT_MAX) return INT_MAX;
            else if(ans * sign <= INT_MIN) return INT_MIN;
        }
        return ans * sign;
    }
};

int main(){
    Solution solution = Solution();
    cout<<solution.myAtoi("2147483648")<<endl;
}