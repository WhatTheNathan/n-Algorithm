/**
 * Description:
 * 我们把只包含因子2、3和5的数称为丑数。
 * 求按从小到大的顺序的第1500个丑数。
 */

#include <iostream>

using namespace::std;

int Min(int a, int b, int c) {
    int min = (a < b) ? a : b;
    min = (min < c) ? min : c;
    return min;
}

int getUglyNumber(int index) {
    if(index < 0)
        return 0;
    int *uglyNumbers = new int[index];
    uglyNumbers[0] = 1;
    int nextUglyIndex= 1;

    int *pMultiply2 = uglyNumbers;
    int *pMultiply3 = uglyNumbers;
    int *pMultiply5 = uglyNumbers;

    while(nextUglyIndex < index) {
        int min = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
        uglyNumbers[nextUglyIndex] = min;

        // 维持三个指针
        while(*pMultiply2 * 2 <= uglyNumbers[nextUglyIndex])
            pMultiply2++;
        while(*pMultiply3 * 3 <= uglyNumbers[nextUglyIndex])
            pMultiply3++;
        while(*pMultiply5 * 5 <= uglyNumbers[nextUglyIndex])
            pMultiply5++;

        nextUglyIndex++;
    }

    int ugly = uglyNumbers[nextUglyIndex - 1];
    delete[] uglyNumbers;
    return ugly;
}

int main() {
    cout<<getUglyNumber(1500)<<endl;
}
