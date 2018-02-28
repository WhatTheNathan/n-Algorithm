#include <iostream>
#include <vector>
using namespace::std;

int BinarySearch(vector<int> a, const int x,const int left,const int right) {
    if (left <= right) {
        int middle = (left + right) / 2;
        if(x < a[middle]) return BinarySearch(a,x,left,middle-1);
        else if (x > a[middle]) return BinarySearch(a,x,middle+1,right);
        return middle; 
    }
}

int main(){
    vector<int> instance = {1,2,3,4,5,6,7};
    cout<<BinarySearch(instance,7,0,6)<<endl;
}

