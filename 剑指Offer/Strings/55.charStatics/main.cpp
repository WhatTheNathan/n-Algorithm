/**
 * Description:
 * 请实现一个函数用来找出字符流中第一个只出现一次的字符。
 */

#include <iostream>
#include <map>

using namespace::std;

char firstChar(char* str, int length) {
    map<char,int> mapp;
    int index = 0;
    for(int i = 0; i < length; i++) {
        if(!mapp.count(str[i])) {
            mapp[str[i]] = index;
        } else {
            mapp[str[i]] = -1;
        }
        index++;
    }
    auto it = mapp.begin();
    int minIndex = INT_MAX;
    while(it != mapp.end()) {
        if(it->second >= 0) {
            if(it->second < minIndex) {
                minIndex = it->second;
            }
        }
        it++;
    }
    return (minIndex == INT_MAX)? '\0' : str[minIndex];
}

int main(){
    char* test_1 = "go";
    char* test_2 = "googllee";
    cout<<firstChar(test_1,2)<<endl;
    cout<<firstChar(test_2,8)<<endl;
}