#include <iostream>
#include <vector>

/*
 * 在十进制表示中，任意一个正整数都可以用字符'0'-'9'表示出来。但是当'0'-'9'这些字符每种字符
 * 的数量有限时，可能有些正整数就无法表示出来了。比如有两个'1'，一个'2'，表示不出10,122。
 * 现在你手上拥有一些字符，它们都是'0'-'9'的字符。输出无法组成的最小的正整数。
 */
using namespace::std;

int number(int index, int num) {
    int number = 0;
    int value = 10;
    for(int i = 0; i < index; i++) {
        number += value;
        value *= 10;
    }
    return num + number;
}

int theLeastNumber(string s){
    int min = 0;
    vector<int> count(10);
    for(auto num: count)
        num = 0;

    for(auto _char: s){
        if(_char != '\0') {
            count[ (_char - 48) ]++;
        }
    }

    int index = 0;
    while(1) {
        for(int i = 0; i < 10; i++) {
            if(count[i] <= 0) {
                if(i == 0)
                    i++;
                return number(index,i);
            }
            count[i]--;
        }
        index++;
    }

    return min;
}

int main() {
    string s = "";
    while(cin>> s)
        cout << theLeastNumber(s) << endl;
    return 0;
}