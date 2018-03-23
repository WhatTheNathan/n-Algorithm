/**
 * Description:
 * 输入n个整数，找出其中最小的k个数。
 * 例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1，2，3，4。
 */

#include <iostream>

using namespace::std;

int partion(int* numbers, int low ,int high) {
    int pivot = numbers[high];
    int smallP = low - 1;
    for(int i = low; i < high; i++) {
        if(numbers[i] < pivot) {
            smallP++;
            swap(numbers[smallP],numbers[i]);
        }
    }
    swap(numbers[high],numbers[++smallP]);
    return smallP;
}

void getLeastNumbers(int* numbers,int length, int k) {
    if(!numbers || length < 0 || k < 0 || k > length)
        return;
    int index = partion(numbers, 0, length - 1);
    while(index != k) {
        if(index > k)
            index = partion(numbers, 0, index - 1);
        else
            index = partion(numbers, index + 1, length - 1);
    }
    for(int i = 0; i < index; i++)
        cout<<numbers[i];
    cout<<endl;
}

int main() {
    const int length = 8;
    int numbers[length] = {4,5,1,6,2,7,3,8};
    getLeastNumbers(numbers,length,4);
}