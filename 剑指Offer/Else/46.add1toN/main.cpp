/**
 * Description:
 * 求1+2+...+n,要求不能使用乘除法、for、while、if、else、switch、case等关键字以及条件判断语句(A?B:C)
 */

#include <iostream>

using namespace::std;

unsigned int add1toN(unsigned int n) {
    if(n < 1)
        return -1;
    if(n == 1)
        return 1;
    else if(n == 2) {
        return 3;
    }else {
        return (n + add1toN(n-1));
    }
}

class Temp {
public:
    Temp() {
        n++;
        ans += n;
    }
    static void Reset() {
        n = 0;
        ans = 0;
    }
    static unsigned int getAns() {
        return ans;
    }

private:
    static unsigned int n;
    static unsigned int ans;
};

unsigned int Temp::n = 0;
unsigned int Temp::ans = 0;

unsigned int solution(unsigned int n) {
    Temp::Reset();

    Temp *a = new Temp[n];
    delete []a;
    a = nullptr;

    return Temp::getAns();
}

int main() {
    unsigned int n;
    scanf("%d",&n);
//
//    unsigned int ans = add1toN(n);
//    printf("%d",ans);
}
