#include <iostream>
#include <vector>

using namespace::std;

int theLeastNumber(string s){
    int min = 0;
    vector<int> count(10);
    for(auto num: count)
        num = 0;

    for(auto _char: s){
        if(_char != '\0') {
            count[ (_char - 48) ]++;
        }
    }

    int index = 1;
    while(1) {
        for(int i = 0; i < 10; i++) {
            int current = 0;
            string num = "";
            for(int j = 0; j < 10; j++) {
                current =
            }
        }
    }

    return min;
}

int main() {
    string s;
    while(cin>> s)
        cout << theLeastNumber(s) << endl;
    return 0;
}