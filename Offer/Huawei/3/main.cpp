#include <iostream>
#include <string>
#include <cstring>
#include <wchar.h>

using namespace::std;

int main() {
    string str1 = "";
    string str2 = "";
    cin>>str1;
    cin>>str2;

    long long int num1 = stoll(str1);
    long long int num2 = stoll(str2);
    cout<<num1*num2<<endl;

    return 0;
}

