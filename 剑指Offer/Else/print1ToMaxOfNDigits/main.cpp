/**
 * Description:
 * 输入数字n，按顺序打印出从1到最大的n位十进制数
 * 输入3，则打印1、2、3一直到最大的3位数即999
 */

#include <iostream>

using namespace::std;

bool Increment(char* number) {
    bool isOverflow = false;
    int nTakeover = 0;
    int nLength = strlen(number);
    /* 模拟整数加法 */
    for(int i = nLength - 1; i >= 0; i--) {
        int nSum = number[i] - '0' + nTakeover;
        /* 加一 */
        if(i == nLength - 1)
            nSum++;
        if(nSum >= 10){
            //最高位进1
            if(i == 0)
                isOverflow = true;
            else {
                nSum -= 10;
                nTakeover = 1;
                number[i] = '0' + nSum;
            }
        }
        else {
            number[i] = '0' + nSum;
            break;
        }
    }
    return isOverflow;
}

void printNumber(char* number) {
    bool isBegin = false;
    int nLength = strlen(number);
    for(int i = 0; i < nLength; i++) {
        if(!isBegin && number[i] != '0')
            isBegin = true;
        if(isBegin)
            cout<<number[i];
    }
    cout<<endl;
}

/* 大数陷阱 */
void print1ToMaxOfNDigits(int n) {
    if(n <= 0)
        return;
    char *number = new char[n + 1];
    memset(number,'0',n);
    number[n] = '\0';

    while(!Increment(number)) {
        printNumber(number);
    }
    delete []number;
}

void subRecursion(char* number, int length, int index) {
    if(index == length - 1) {
        printNumber(number);
        return;
    }

    for(int i = 0; i < 10; i++) {
        number[index + 1] = i + '0';
        subRecursion(number,length,index + 1);
    }
}

void recursionPrint1ToMaxOfNDigits(int n) {
    if(n <= 0)
        return;
    char *number = new char[n + 1];
    number[n] = '\0';

    /* 每位的1到9的全排列 */
    for(int i = 0; i < 10; i++) {
        number[0] = i + '0';
        subRecursion(number,n,0);
    }
}

int main(){
//    print1ToMaxOfNDigits(3);
    recursionPrint1ToMaxOfNDigits(3);
}