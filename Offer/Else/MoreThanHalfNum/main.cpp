/**
 * Description:
 * 数组有一个数字出现的次数超过数组长度的一半，请找出这个数。
 * 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}，2出现了5次，超过数组长度的一半，输出2。
 */

#include <iostream>

using namespace::std;

int partionNum(int* numbers, int low ,int high) {
    int pivot = numbers[high];
    int smallP = low - 1;
    for(int i = low; i < high; i++) {
        if(numbers[i] <= pivot) {
            smallP++;
            swap(numbers[smallP],numbers[i]);
        }
    }
    swap(numbers[high],numbers[++smallP]);
    return smallP;
}

bool checkMoreThanHalf(int* numbers, int length, int result) {
    int count = 0;
    for(int i = 0; i < length; i ++) {
        if(numbers[i] == result)
            count++;
    }
    if(count >= length / 2)
        return true;
    return false;
}

int moreThanHalfNum(int* numbers, int length) {
    if(!numbers)
        return 0;
    int partion = partionNum(numbers,0,length-1);
    int middle = length / 2;
    while(partion != middle) {
        if(partion > middle) {
            partion = partionNum(numbers,0,partion - 1);
        } else {
            partion = partionNum(numbers,partion + 1, length);
        }
    }
    int result = numbers[middle];
    if(!checkMoreThanHalf(numbers, length, result))
        result = 0;
    return result;
}

int main() {
    const int length = 9;
    int numbers[length] = {1,2,3,2,2,2,5,4,2};
    cout<<moreThanHalfNum(numbers,length)<<endl;
}