#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>

/*
 *
 */
using namespace::std;

double length(int x_1,int x_2, int y_1, int y_2) {
    unsigned int width = abs(x_2 - x_1);
    unsigned int height = abs(y_2 - y_1);

    return sqrt(width*width + height*height);
}

bool equal(double a , double b) {
    if(a - b < 0.001 || b - a < 0.001)
        return true;
    else return false;
}

bool isRect(set<double> lengths) {
    if(lengths.size() == 2) {
        auto it = lengths.begin();
        int length_1 = *it;
        int length_2 = *it++;
        if( equal(sqrt(length_1),length_2) || equal(length_1,sqrt(length_2) ))
            return true;
    }
    return false;
}

void isRect(int x_1,int x_2,int x_3,int x_4, int y_1, int y_2, int y_3,int y_4) {
    double length_1 = length(x_1,x_2,y_1,y_2);
    double length_2 = length(x_1,x_3,y_1,y_3);
    double length_3 = length(x_1,x_4,y_1,y_4);
    double length_4 = length(x_2,x_3,y_2,y_3);
    double length_5 = length(x_2,x_4,y_2,y_4);
    double length_6 = length(x_3,x_4,y_3,y_4);

    set<double> lengths;
    lengths.insert(length_1);
    lengths.insert(length_2);
    lengths.insert(length_3);
    lengths.insert(length_4);
    lengths.insert(length_5);
    lengths.insert(length_6);

    if(isRect(lengths))
        cout<<"YES"<<endl;
    else
        cout<<"No"<<endl;
}

int main() {
    int n = 0;
    int x_1,x_2,x_3,x_4,y_1,y_2,y_3,y_4;
    cin >> n;
    while(cin>>x_1>>x_2>>x_3>>x_4>>y_1>>y_2>>y_3>>y_4) {
        isRect(x_1,x_2,x_3,x_4,y_1,y_2,y_3,y_4);
    }

}

