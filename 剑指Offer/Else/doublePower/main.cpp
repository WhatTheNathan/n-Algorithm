/**
 * Description:
 * 实现函数double Power(double base, int exponent), 求base的exponent次方
 */

#include <iostream>

using namespace::std;

/*
 * 1. normal case   (2,3)
 * 3. 负指数方      (3,-2)
 * 4. 0的0次方
 */

bool invalidInput = false;

bool equal(double a, double b) {
    if( (a - b > -0.000000001) && (a - b < 0.000000001) )
        return true;
    return false;
}

double normalPower(double base, int exponent) {
    double result = 1.0;
    for(int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

double Power(double base, int exponent) {
    invalidInput = false;
    if(equal(base,0.0) && exponent <= 0) {
        invalidInput = true;
        return 0.0;
    }

    int tempExp = abs(exponent);
    double result = normalPower(base,tempExp);
    if (exponent < 0) {
        result = 1.0 / result;
    }
    return result;
}

int main(){
    cout<<Power(2,4)<<endl;
    cout<<Power(2,-4)<<endl;
    cout<<Power(-2,3)<<endl;
    cout<<Power(0,0)<<endl;
}