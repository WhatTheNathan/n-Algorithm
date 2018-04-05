/**
 * Description:
 * 请事先一个函数用来判断字符串是否表示数值(包括整数和小数)。
 */

#include <iostream>

using namespace::std;

void scanDigits(char** str) {
    while(**str != '\0' && **str >= '0' && **str <= '9') {
        (*str)++;
    }
}

bool isExponential(char** str) {
    if(**str != 'e' && **str != 'E') {
        return false;
    }
    (*str)++;
    if(**str == '+' || **str == '-') {
        (*str)++;
    }

    if(**str == '\0')
        return false;

    scanDigits(str);
    return **str == '\0' ? true : false;
}

bool isNumberic(char* str) {
    if(!str) {
        return false;
    }
    bool numberic = true;
    // 首先看+-
    if(*str == '+' || *str == '-') {
        str++;
    }
    // 为空或还有+-
    if(*str == '\0') {
        return false;
    }
    // 看数字
    scanDigits(&str);

    // 还未结束
    if(*str != '\0') {
        if(*str == 'e' || *str == 'E') {
            numberic = isExponential(&str);
        } else if(*str == '.') {
            str++;
            scanDigits(&str);
            if(*str == 'e' || *str == 'E') {
                numberic = isExponential(&str);
            }
        } else {
            numberic = false;
        }
    }
    return numberic && *str == '\0';
}

int main(){
    char* test_1 = "++100";
    char* test_2 = "1.234";
    char* test_3 = "1e-16";
    char* test_4 = "34.E2";
    cout<<isNumberic(test_1)<<endl;
    cout<<isNumberic(test_2)<<endl;
    cout<<isNumberic(test_3)<<endl;
    cout<<isNumberic(test_4)<<endl;
}