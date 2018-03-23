/**
 * Description:
 * 实现一个函数，把字符串中的每个空格替换成"%20"。
 * 例如输入"We are happy."，则输出"We%20are%20happy."
 */

#include <iostream>

using namespace::std;

void replaceSpace(char str[],int length) {
    if (str == nullptr || length < 0) {
        return;
    }
    int i = 0;
    int numberOfSpace = 0;
    int old_length = 0;
    while(str[i] != '\0') {
        old_length++;
        if (str[i] == ' ') {
            numberOfSpace++;
        }
        i++;
    }

    int new_length = old_length + numberOfSpace * 2;
    if (new_length > length) {
        return;
    }
    int indexOfOld = old_length;
    int indexOfNew = new_length;
    while (indexOfOld > 0 && indexOfNew > indexOfOld) {
        if (str[indexOfOld] == ' ') {
            str[indexOfNew--] = '0';
            str[indexOfNew--] = '2';
            str[indexOfNew--] = '%';
        } else {
            str[indexOfNew--] = str[indexOfOld];
        }
        indexOfOld--;
    }
}

int main(){
    char str[100] = "We are happy.";
    replaceSpace(str,100);
    cout<<str<<endl;
}