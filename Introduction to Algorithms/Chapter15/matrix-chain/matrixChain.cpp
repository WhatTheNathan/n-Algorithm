#include <iostream>
#include <vector>

using namespace::std;

/*
 * 1.刻画一个最优解的结构特征
 * 2.递归地定义最优解的值
 * 3.计算最优解的值，通常采用自底向上的方法
 * 4.利用计算出的信息构造一个最优解
 */

void printOptimal(vector<vector<int>> s,int i,int j) {
    if (i == j)
        cout<<"A";
    else{
        cout<<"(";
        printOptimal(s,i,s[i][j]);
        printOptimal(s,s[i][j]+1,j);
        cout<<")";
    }
}

void matrixChainOrder(vector<int> p){
    int n = p.size() - 1;
    vector<vector<int>> m = vector<vector<int>>(n+1);
    vector<vector<int>> s = vector<vector<int>>(n);
    for(int i = 0; i <= n; i++) {
        m[i] = vector<int>(n+1);
        s[i] = vector<int>(n+1);
    }
    for(int i = 1;i <= n; i++)
        m[i][i] = 0;

    for(int l = 2; l <= n; l++){  // l is the chain length
        for(int i = 1; i <= (n - l + 1); i++) {
            int j = i + l - 1;
            /* 对于每个m[i][j]为单独的子问题 */
            m[i][j] = -1;
            for(int k = i; k <= j-1; k++){

                int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if(q < m[i][j] || m[i][j] <= 0){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    printOptimal(s,1,n);
}

int main(){
    vector<int> order = {30,35,15,5,10,20,25};
    matrixChainOrder(order);
}