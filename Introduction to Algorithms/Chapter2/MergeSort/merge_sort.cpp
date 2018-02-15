#include <iostream>
#include <vector>
#include <cmath>
using namespace::std;

void merge(vector<int> &A,int p,int q,int r){
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<int> L;
    vector<int> R;
    for(int i=1; i<=n1; i++)
        L.push_back(A[p+i-1]);
    for(int j=1; j<=n2; j++)
        R.push_back(A[q+j]);
    /* sentinel */
    L.push_back(-1);
    R.push_back(-1);

    int i = 0;
    int j = 0;
    int k=p;
    for( ; k<=r; k++){
        if( L[i] <= R[j]){
            if(L[i] == -1){
                A[k] = R[j];
                j++;
            }else{
                A[k] = L[i];
                i++;
            }
        }else {
            if(R[j] == -1){
                A[k] = L[i];
                i++;
            }else {
                A[k] = R[j];
                j++;
            }
        }
    }
}

void merge_sort(vector<int> &A,int p,int r){
    if(p<r){
        int q = floor((p+r)/2);
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);
    }
}

int main(){
    vector<int> instance = {2,4,5,7,1,2,3,6};
    merge_sort(instance,0,instance.size()-1);
    for(auto num: instance){
        cout<<num<<" ";
    }
    cout<<endl;
}