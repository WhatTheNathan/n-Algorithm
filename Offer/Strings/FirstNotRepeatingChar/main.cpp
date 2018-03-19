/**
 * Description:
 * 在字符串中找出第一个只出现一次的字符
 * 如输入"abaccdeff"，则输出'b'。
 */

#include <iostream>

using namespace::std;

char firstNotRepeatingChar(char* string) {
    if(!string)
        return '\0';

    const int size = 256;
    int* hashTable = new int[size];

    for(int i = 0; i < size; i++) {
        hashTable[i] = 0;
    }

    char* key = string;
    while(*(key) != '\0') {
        hashTable[*(key)]++;
        key++;
    }

    key = string;
    while(*(key) != '\0') {
        if(hashTable[*key] == 1)
            return *key;
        key++;
    }
    return '\0';
}

int main(){
    char* string = "abaccdeff";
    cout<<firstNotRepeatingChar(string)<<endl;
}