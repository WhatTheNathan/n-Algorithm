#include <iostream>
#include <cmath>

using namespace::std;

bool isMatrix(int N) {
    double M = double(N);
    int ans = sqrt(M);
    if(ans*ans == M) {
        return true;
    }
    return false;
}

void spinMatrix(int *matrix,int num) {
    for(int j=0; j < num; j++) {
        for(int i = num-1; i>=0; i--) {
            if(i!=0){
                cout<<matrix[i * num + j]<<" ";
            }else {
                cout<<matrix[i * num + j];
            }
        }
        cout<<endl;
    }
}

int main() {
    int *matrix = new int[1000000000];
    int N = 0;
    int num;
    while(cin >> num) {
        matrix[N] = num;
        N++;
        if(isMatrix(N)) {
            double M = double(N);
            spinMatrix(matrix,sqrt(M));
        }
    }

    return 0;
}

