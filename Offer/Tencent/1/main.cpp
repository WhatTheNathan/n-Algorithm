#include <iostream>
#include <cmath>
#include <vector>
#include <map>

/*
 *
 */
using namespace::std;

unsigned int length(int x_1,int x_2, int y_1, int y_2) {
    unsigned int width = abs(x_2 - x_1);
    unsigned int height = abs(y_2 - y_1);

    return sqrt(width*width + height*height);
}

bool isLength(vector<unsigned int> lengths) {
    map<unsigned int, int> map;
    for (auto length: lengths) {
        map[length] = 0;
    }
    for (auto length: lengths) {
        map[length] += 1;
    }
    if (map.size() == 2) {
        int count = 0;
        for (auto what: map) {
            if (what.second == 4 || what.second == 2)
                count++;
        }
        if (count == 2)
            return true;
    }
    return false;
}

bool calVertical(int x_1,int x_2,int x_3,int y_1, int y_2,int y_3) {
    int vx_1 = x_2 - x_1;
    int vy_1 = y_2 - y_1;
    int vx_2 = x_3 - x_1;
    int vy_2=  y_3 - y_1;
    if((vx_2 * vx_1 + vy_1 * vy_2) == 0 )
        return true;
    return false;
}

bool isVertical(int x_1,int x_2,int x_3,int x_4, int y_1, int y_2, int y_3,int y_4) {
    if(calVertical(x_1,x_2,x_3,y_1,y_2,y_3)||
       calVertical(x_1,x_2,x_4,y_1,y_2,y_4)||
       calVertical(x_1,x_3,x_4,y_1,y_3,y_4)||
       calVertical(x_2,x_1,x_3,y_2,y_1,y_3)||
       calVertical(x_2,x_3,x_4,y_2,y_3,y_4)||
       calVertical(x_2,x_1,x_4,y_2,y_1,y_4)||
            calVertical(x_3,x_1,x_4,y_3,y_1,y_4)||
            calVertical(x_3,x_2,x_4,y_3,y_2,y_4)||
            calVertical(x_3,x_2,x_1,y_3,y_2,y_1)||
            calVertical(x_4,x_1,x_2,y_4,y_1,y_2)||
            calVertical(x_4,x_1,x_3,y_4,y_1,y_3)||
            calVertical(x_4,x_2,x_3,y_4,y_2,y_3))
        return true;
    return false;
}

void isRect(int x_1,int x_2,int x_3,int x_4, int y_1, int y_2, int y_3,int y_4) {
    unsigned int length_1 = length(x_1,x_2,y_1,y_2);
    unsigned int length_2 = length(x_1,x_3,y_1,y_3);
    unsigned int length_3 = length(x_1,x_4,y_1,y_4);
    unsigned int length_4 = length(x_2,x_3,y_2,y_3);
    unsigned int length_5 = length(x_2,x_4,y_2,y_4);
    unsigned int length_6 = length(x_3,x_4,y_3,y_4);

    vector<unsigned int> lengths = {length_1,length_2,length_3,length_4,length_5,length_6};

    if(isLength(lengths) && isVertical(x_1,x_2,x_3,x_4,y_1,y_2,y_3,y_4))
        cout<<"YES"<<endl;
    else
        cout<<"No"<<endl;
}


int cases(int n) {

}

int main() {
    int n = 0;
    while(cin>>n) {
        cout<<cases(n)<<endl;
    }

}

