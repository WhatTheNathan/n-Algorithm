#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
using namespace::std;

int max(int a,int b,int c){
    int d = b > c ? b : c;
    return a > d ? a : d;
}

tuple<int,int,int> findMaxCrossingSubArray(vector<int> A,int low,int mid,int high) {
    int left_sum = INT_MIN;
    int max_left = mid;
    int sum = 0;
    for(int i = mid; i >= low; i--){
        sum = sum + A[i];
        if(sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = INT_MIN;
    int max_right = mid + 1;
    sum = 0;
    for(int i = mid + 1; i <= high; i++){
        sum = sum + A[i];
        if(sum > right_sum) {
            right_sum = sum;
            max_right = i;
        }
    }
    tuple<int,int,int> re_tuple = make_tuple(max_left,max_right,left_sum + right_sum);
    return re_tuple;
}

tuple<int,int,int> findMaximumSubArray(vector<int> A,int low,int high){
    /* Base case: only one element */
    if(high == low)
        return make_tuple(low,high,A[low]);
    else {
        int mid = floor((low + high) / 2);
        tuple<int,int,int> left_maximum_subArray = findMaximumSubArray(A,low,mid);
        tuple<int,int,int> right_maximum_subArray = findMaximumSubArray(A,mid+1,high);
        tuple<int,int,int> cross_maximum_subArray = findMaxCrossingSubArray(A,low,mid,high);

        int left_sum,right_sum,cross_sum;
        tie(ignore,ignore,left_sum) = left_maximum_subArray;
        tie(ignore,ignore,right_sum) = right_maximum_subArray;
        tie(ignore,ignore,cross_sum) = cross_maximum_subArray;

        int max_sum = max(left_sum,right_sum,cross_sum);
        if(max_sum == left_sum)
            return left_maximum_subArray;
        if(max_sum == right_sum)
            return right_maximum_subArray;
        else return cross_maximum_subArray;
    }
}

int main(){
    vector<int> array = {0,13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    tuple<int,int,int> maximum_subArray = findMaximumSubArray(array,1,array.size()+1);
    int left_index,right_index,sum;
    tie(left_index,right_index,sum) = maximum_subArray;

    cout<<"left_index: "<<left_index<<endl;
    cout<<"right_index: "<<right_index<<endl;
    cout<<"sum: "<<sum<<endl;
}