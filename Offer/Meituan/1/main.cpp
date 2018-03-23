#include <iostream>
#include <vector>
#include <string>

using namespace::std;

int getDistance(string S, string T) {
    int count = 0;
    for(int i = 0; S[i] != '\0'; i++) {
        if(S[i] != T[i])
            count++;
    }
    return count;
}

vector<string> subString(string S, int lengthS, int lengthT) {
    vector<string> subStrings;
    if ( lengthS == lengthT ){
        subStrings.push_back(S);
    } else {
        for(int i = 0; i < (lengthS - lengthT + 1); i++) {
            string temp = "";
            cout<<"here"<<endl;
            for(int j = 0; j < lengthT; j++) {
                cout<<j<<endl;
                cout<<i+j<<endl;
                temp[j] = S[i + j];
            }
            subStrings.push_back(temp);
        }
    }
    return subStrings;
}

int totalDistance(string S, string T) {
    int lengthS = S.size();
    int lengthT = T.size();
    int distance = 0;

    vector<string> subStrings = subString(S,lengthS,lengthT);
    if(!subStrings.empty()) {
        for(auto subString: subStrings) {
            int temp = getDistance(subString,T);
            distance += temp;
        }
    }
    return distance;
}

int main() {
    string S = "bababababababbababababababababababababbabababa";
    string T = "bababababababbababababababababababababbababab";
//    while(cin>> S >> T)
        cout << totalDistance(S,T) << endl;
//    return 0;
}