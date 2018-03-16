#include <iostream>

using namespace::std;

void bubbleSort(int* number, int length) {
    if(!number)
        return;
    bool flag = false;
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length - i -1; j++) {
            if(number[j] > number[j + 1]) {
                int temp = number[j];
                number[j] = number[j + 1];
                number[j + 1] = temp;
                flag = true;
            }
        }
        if(!flag)
            return;
    }
}

int main(){
    const int length = 9;
    int number[length] = {9,8,7,6,5,4,3,2,1};
    bubbleSort(number,length);
    for(int i = 0; i < length; i++)
        cout<<number[i]<<" ";
    cout<<endl;
}

