/**
 * Description:
 * 写一个函数，求两个证书之和，要求在函数体内不得使用+、-、x、\四则运算符号
 */

#include <iostream>

using namespace::std;

int add(int num_1, int num_2) {
    int sum, carry;
    do {
        sum = num_1 ^ num_2;
        carry = (num_1 & num_2) << 1;

        num_1 = sum;
        num_2 = carry;
    }while(num_2 != 0);
    return num_1;
}

int main() {
    int num_1,num_2;
    scanf("%d%d",&num_1,&num_2);
    printf("%d",add(num_1,num_2));
}
