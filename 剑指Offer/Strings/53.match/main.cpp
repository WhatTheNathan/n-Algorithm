/**
 * Description:
 * 请实现一个函数用来匹配包含'.'和'*'的正则表达式。
 * 模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次(含0次)。
 * 在本题中，匹配是指字符串的所有字符匹配整个模式。
 * 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"以及"ab*a"均不匹配。
 */

#include <iostream>

using namespace::std;

bool match(char* str, char* pattern) {
    if(*str == '\0' && *pattern == '\0') {
        return true;
    }
    if(*str != '\0' && *pattern == '\0') {
        return false;
    }
    if(*(pattern+1) == '*') {
        if(*str == *pattern || (*pattern == '.' && *str != '\0')) {
            return match(str+1,pattern+2) || match(str+1,pattern) ||
                   match(str,pattern+2);
        } else {
            return match(str,pattern+2);
        }
    }
    if(*str == *pattern || (*pattern == '.' && *str != '\0')) {
        return match(str+1,pattern+1);
    }
    return false;
}

int main(){
    char* str = "aaa";
    char* pattern_1 = "a.a";
    char* pattern_2 = "ab*ac*a";
}