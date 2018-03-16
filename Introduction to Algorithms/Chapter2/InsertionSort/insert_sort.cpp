#include <iostream>
using namespace::std;

void insert_sort(int* number, int length){
    if(!number || length <= 1)
        return;
    for(int j = 1; j < length; j++){
        // 做判断，可减少比较
        if(number[j-1] > number[j]) {
            int key = number[j];
            // insert number[j] into the sorted sequence number[0..j-1]
            int i = j - 1;
            while(i >= 0 && number[i] > key){
                number[i+1] = number[i];
                i--;
            }
            number[i+1] = key;
        }
    }
}

int main(){
    const int length = 6;
    int instance[] = {5,2,4,6,1,3};
    insert_sort(instance, length);
    for(int i = 0; i < length; i++)
        cout<<instance[i]<<" ";
    cout<<endl;
}

