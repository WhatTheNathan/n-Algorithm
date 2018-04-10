#include <iostream>
#include <queue>
#include <map>

using namespace::std;

int main() {
    string str;
    string ans;
    map<char,int> mapp;
    cin>>str;
    for(int i = 0; i < str.size(); i++) {
        mapp[str[i]] += 1;
    }
    while(!mapp.empty()) {
        map<char,int>::iterator iter = mapp.begin();
        while(iter != mapp.end()) {
            ans += iter->first;
            iter->second--;
            map<char,int>::iterator temp = iter;
            iter++;
            if(temp->second == 0) {
                mapp.erase(temp);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

