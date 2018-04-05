#include <iostream>
#include <cmath>

using namespace::std;

bool isAfford(double firstChoco, int totalChoco, int N) {
    int comsume = 0;
    for(int i = 0; i < N; i++) {
        comsume += firstChoco;
        firstChoco = ceil(firstChoco / 2);
        if(comsume > totalChoco)
            return false;
    }
    return true;
}

int main() {
    int N,M;
    scanf("%d%d",&N,&M);

    if(N < 1) {
        return 0;
    }
    if(N == 1) {
        printf("%d",M);
    }

    int minChoco = 0;
    int minfirstChoco = 1;
    for(int i = 0 ;i < N; i++) {
        minChoco += minfirstChoco;
        if(i != N-1)
            minfirstChoco *= 2;
    }
    if(minChoco > M) {
        exit(1);
    }

    int ans = minfirstChoco;

    for(int i = minfirstChoco + 1; i < M; i++) {
        if(isAfford(i,M,N)) {
            ans = i;
        }else break;
    }

    printf("%d",ans);
}

