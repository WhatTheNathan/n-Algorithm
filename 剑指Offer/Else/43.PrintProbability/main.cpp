/**
 * Description:
 * 把n个骰子扔在地上，所有骰子朝上一面的点数之和为s，输入n，打印出s的所有可能的值出现的概率
 */

#include <iostream>
#include <iomanip>

using namespace::std;


double printProbability(int n, int s) {
    if(n == 1) {
        if(s > 6 || s < 1)
            return 0;
        else return (1.0/6.0);
    }
    return (1.0/6.0) * (printProbability(n-1,s-1) + printProbability(n-1,s-2) + printProbability(n-1,s-3) + printProbability(n-1,s-4)
            + printProbability(n-1,s-5) + printProbability(n-1,s-6));
}

void printAllProbality(int n) {
    if(n < 1) {
        return;
    }
    int minSum = n;
    int maxSum = 6 * n;
    for(int i = minSum; i <= maxSum; i++) {
        cout<<i<<" "<<printProbability(n,i)<<endl;
    }
}

int main() {
    printAllProbality(11);
}
