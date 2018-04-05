#include <iostream>
#include <algorithm>

using namespace::std;


int main() {
    int n,value;
    int* card;

    scanf("%d",&n);
    card = new int[n];

    for(int i = 0; i < n; i++) {
        scanf("%d",&value);
        card[i] = value;
    }

    int ans = 0;
    sort(card,card+n);
    int sign = 1;
    for(int i = n-1; i >= 0; i--) {
        if(sign == 1) {
            ans += card[i];
            sign = -1;
        }
        else {
            ans -= card[i];
            sign = 1;
        }
    }

    printf("%d",ans);

}

