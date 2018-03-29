#include <iostream>

using namespace::std;

int main() {
    int N;
    int *nums;
    int *is0;
    int *isnt0;
    scanf("%d",&N);

    nums = new int[N];
    is0 = new int[N];
    isnt0 = new int[N];

    for(int i=0;i<N;i++) {
        scanf("%d",&nums[i]);
    }

    int is0Count = 0;
    int isnt0Count = 0;

    for(int i=0;i<N;i++) {
        if(nums[i] == 0){
            is0[is0Count++] = 0;
        }else {
            isnt0[isnt0Count++] = nums[i];
        }
    }

    int count =0;
    for(;count<isnt0Count;count++) {
        nums[count] = isnt0[count];
    }

    for(int i=0;i<is0Count;i++) {
        nums[count++] = is0[i];
    }

    for(int i=0;i<N;i++){
        printf("%d\n",nums[i]);
    }
    return 0;
}

