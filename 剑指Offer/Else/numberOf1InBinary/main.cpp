/**
 * Description:
 * 实现一个函数，输入一个整数，输出该数二进制表示中1的个数
 * 例如把9表示成二进制是1001，有2位是1，因此如果输入9，该函数输出2
 */

#include <iostream>

using namespace::std;

//int NumberOf1(int n) {
//    int count = 0;
//    unsigned int flag = 1;
//    while(flag) {
//        if(n & flag)
//            count++;
//        flag = flag << 1;
//    }
//    return count;
//}

/**
 * 把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0。
 * 那么一个整数的二进制表示中有多少个1，就可以进行这样的操作。
 */

int NumberOf1(int n) {
    int count = 0;
    while(n) {
        count ++;
        n = (n - 1) & n;
    }
    return count;
}

int main(){
    cout<<NumberOf1(9)<<endl;
}