/**
 * Description:
 * 一个整形数组里除了两个数字之外，其他数字都出现了两次。
 * 请写出程序找到这两个只出现一次的数字，时间复杂度为O(n),空间复杂度为O(1)。
 */

#include <iostream>

using namespace::std;

unsigned int findFirstBitIs1(int num) {
    int indexBit = 0;
    while((num & 1) == 0 && (indexBit < 8 * sizeof(int))) {
        num = num >> 1;
        indexBit++;
    }
    return indexBit;
}

bool isBit1(int num, unsigned  int index) {
    num = num >> index;
    return (num & 1);
}

void findNumsAppearOnce(int* nums, int length) {
    if(!nums || length < 2) {
        return;
    }
    int result = 0;
    for(int i = 0; i < length; i++) {
        result = result ^ nums[i];
    }
    unsigned int indexOf1 = findFirstBitIs1(result);

    int num_1 = 0, num_2 = 0;
    for(int i = 0; i < length; i++) {
        if(isBit1(nums[i],indexOf1)) {
            num_1 ^= nums[i];
        }else {
            num_2 ^= nums[i];
        }
    }
    printf("%d %d\n",num_1,num_2);
}

int main(){
    const int length = 8;
    int nums[length] = {2,4,3,6,3,2,5,5};
    findNumsAppearOnce(nums,length);
}