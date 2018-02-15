/**
 * Description:
 * 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
 * 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 */

#include <iostream>

using namespace::std;

bool find(int *matrix, int rows, int columns, int number) {
    if (matrix != nullptr && rows > 0 && columns > 0) {
        int row = 0;
        int column = columns - 1;
        while(row < rows && column >= 0) {
            if (matrix[row * columns + column] == number) {
                return true;
            } else if (matrix[row * columns + column] > number) {
                column--;
            } else {
                row++;
            }
        }
    }
    return false;
}

int main(){
    int matrix[] = {1,2,8,9,
                    2,4,9,12,
                    4,7,10,13,
                    6,8,11,15};
    cout<<find(matrix,4,4,7)<<endl;
    cout<<find(matrix,4,4,20)<<endl;
    cout<<find(nullptr,4,4,20)<<endl;
}