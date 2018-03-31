/**
 * Description:
 * 输入一个英文句子，翻转句子中单词的顺序，但单词内字符顺序不变，标点符号和普通字母一样处理。
 * 例如输入字符串"I am a student."，则输出"student. a am I"。
 * 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
 * 请定义一个函数实现字符串左旋转操作的功能。
 * 比如输入字符串"abcdefg"和数字2，该函数返回左旋转2位得到的结果"cdefgab"。
 */

#include <iostream>

using namespace::std;

void reverseStr(string &str, int low, int high) {
    if(low >= high) {
        return;
    }
    while(low < high) {
        swap(str[low++],str[high--]);
    }
}

void leftRotateString(string &str, int n) {
    int length = str.size();
    if(n < 1 || n > length)
        return;
    reverseStr(str,0,length-1);
    reverseStr(str,0,length-1-n);
    reverseStr(str,length-n,length-1);
}

int main(){
//    string str = "I am a student.";
//    reverseStr(str, 0, str.size()-1);
//
//    int start = 0, end = 0;
//    while(str[start] != '\0') {
//        if(str[start] == ' ') {
//            start++;
//            end++;
//        }
//        else if(str[end] == ' ' || str[end] == '\0') {
//            reverseStr(str,start,end-1);
//            start = end;
//        } else {
//            end++;
//        }
//    }
//
//    cout<<str<<endl;

    string str = "abcdefg";
    leftRotateString(str,6);
    cout<<str<<endl;
}