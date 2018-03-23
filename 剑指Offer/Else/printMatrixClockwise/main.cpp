/**
 * Description:
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字
 */

#include <iostream>

using std::cout;
using std::endl;

void printMatrixInCircle(int** matrix, int rows, int columns, int start) {
    int endX = columns - start - 1;
    int endY = rows - start - 1;
    for(auto i = start; i <= endX; i++) {
        cout<<matrix[start][i]<<endl;
    }
    if(endY > start) {
        for(int i = start + 1; i <= endY; i++) {
            cout<<matrix[i][endX]<<endl;
        }
    }
    if(start < endX && start < endY) {
        for(int i = endX - 1; i >= start; i--) {
            cout<<matrix[endY][i]<<endl;
        }
    }
    if(start < endX && start < endY - 1) {
        for(int i = endY - 1;i >= start; i--) {
            cout<<matrix[i][start]<<endl;
        }
    }
}

void printMatrxiClockwiseRecursively(int** matrix, int rows, int columns) {
    if(!matrix || columns < 0 || rows < 0)
        return;

    int start = 0;
    while(rows > start * 2 && columns > start * 2) {
        printMatrixInCircle(matrix,rows,columns,start);
        start++;
    }
}

int main(){
    const int rows = 4;
    const int columns = 4;
    int matrix[rows][columns];
    int (*ip)[] = matrix;
    printMatrxiClockwiseRecursively(ip,rows,columns);
}