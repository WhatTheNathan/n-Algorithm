#include <iostream>

using namespace::std;

int main() {
    int N;
    string turn;
    cin>>N;
    cin>>turn;

    int direct = 0;
    char direction[] = {'N','E','S','W'};

    for(int i=0;i<N;i++){
        if(turn[i] == 'L') {
            direct = direct - 1;
            if(direct == -1)
                direct = 3;
        }
        else if(turn[i] == 'R') {
            direct = (direct + 1) % 4;
        }
    }

    cout<<direction[direct]<<endl;
    return 0;
}

