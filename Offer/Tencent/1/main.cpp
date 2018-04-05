#include <iostream>
#include <vector>
#include <cstring>

using namespace::std;


int main() {
    int N,M;
    scanf("%d%d",&N,&M);
    string value;
    vector<string> image;

    for(int i = 0; i < N; i++) {
        cin>>value;
        image.push_back(value);
    }

    vector<int> numOfY(N);
    vector<int> numOfB(N);

    int row = 0;
    for(auto str: image) {
        for(int i = 0; i < M; i++) {
            if(str[i] == 'Y')
                numOfY[row]++;
            else if(str[i] == 'B')
                numOfB[row]++;
            else if(str[i] == 'G'){
                numOfY[row]++;
                numOfB[row]++;
            }
        }
        row++;
    }

    int ans = 0;
    int maxNumOfY = 0,maxNumOfB = 0;
    for(int i = 0; i < N; i++) {
        if(numOfY[i] > maxNumOfY)
            maxNumOfY = numOfY[i];
        if(numOfB[i] > maxNumOfB)
            maxNumOfB = numOfB[i];
    }
    ans = (maxNumOfB + maxNumOfY);
    printf("%d",ans);

}

