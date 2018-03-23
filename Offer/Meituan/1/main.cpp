#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>

/*
 * 给出两个相同长度的由字符a和b构成的字符串，定义它们的距离为对应位置不同的字符的数量。
 * 如串"aab"与串"aba"的距离为2; 下面给出两个字符串S与T，其中S的长度不小于T的长度。
 * 我们用|S|代表S的长度，|T|代表T的长度，那么在S中一共有|S|-|T|+1个与T长度相同的子串，现在你需要计算T串与这些|S|-|T|+1个子串的距离的和。
 */
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
        for(unsigned int i = 0; i < (lengthS - lengthT + 1); i++) {
            string temp = "";
            for(int j = 0; j < lengthT; j++) {
                temp += S[i+j];
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
    string S = "";
    string T = "";
    while(cin>> S >> T)
        cout << totalDistance(S,T) << endl;
    return 0;
}