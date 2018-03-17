/**
 * Description:
 * 输入一个字符串，打印出该字符串中字符的所有排列。
 * 例如输入字符串abc，则打印出由字符a,b,c所能排列出来的所有的字符串abc,acb,bac,bca,cab和cba。
 */

#include <iostream>

using namespace::std;

//template <typename T>
//void swap(T &a, T &b) {
//    T temp = b;
//    b = a;
//    a = temp;
//}

void permutation(char* str, int low, int high) {
    if(!str)
        return;
    if(low == high) {
        for(int i = 0 ; i <= high; i++)
            cout<<str[i];
        cout<<endl;
    } else {
        for(int i = low; i <= high; i++) {
            swap(str[low],str[i]);
            permutation(str,low + 1,high);
            swap(str[low],str[i]);
        }
    }
}

int main() {
    char str[] = {'a','b','c'};
    permutation(str,0,2);
}