#include <iostream>

using namespace::std;

int main() {
    int n = 0;
    int x_1,x_2,x_3,x_4,y_1,y_2,y_3,y_4;
    cin >> n;
    while(cin>>x_1>>x_2>>x_3>>x_4>>y_1>>y_2>>y_3>>y_4) {
        isRect(x_1,x_2,x_3,x_4,y_1,y_2,y_3,y_4);
    }
}

