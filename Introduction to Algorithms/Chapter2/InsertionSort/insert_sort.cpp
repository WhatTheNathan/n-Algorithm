#include <iostream>
#include <vector>
using namespace::std;

void insert_sort(vector<int> &A){
    for(int j=1; j<A.size(); j++){
        int key = A[j];
        // insert A[j] into the sorted sequence A[0..j-1]
        int i = j - 1;
        while(i >= 0 and A[i] > key){
            A[i+1] = A[i];
            i--;
        } 
        A[i+1] = key;
    }
}

int main(){
    vector<int> instance = {5,2,4,6,1,3};
    insert_sort(instance);
    for(auto num: instance){
        cout<<num<<".";
    }
    cout<<endl;
}

