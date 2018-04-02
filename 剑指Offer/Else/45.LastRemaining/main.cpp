/**
 * Description:
 * 0,1,...,n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里删除第m个数字。
 * 求出这个圆圈里剩下的最后一个数字。
 */

#include <iostream>
#include <iomanip>
#include <list>

using namespace::std;

struct ListNode {
    int val;
    int* link;
    int* pre;
    ListNode(int x) : val(x),link(nullptr),pre(nullptr) {}
};

void remainNumber(list<int> &nums, int m) {
    list<int>::iterator current = nums.begin();
    while(nums.size() > 1) {
        for(int i = 1; i < m; i++) {
            current++;
            if(current == nums.end())
                current = nums.begin();
        }
        list<int>::iterator next = ++current;
        if(next == nums.end())
            next = nums.begin();

        current--;
        nums.erase(current);
        current = next;
    }
    cout<<*current<<endl;
}

int remianNumber(unsigned int n, unsigned int m) {
    if(n < 1 || m < 1) {
        return -1;
    }
    int last = 0;
    for(int i = 2; i <= n; i++) {
        last = (last + m) %i;
        cout<<last<<endl;
    }
    return last;
}

int main() {
    const int length = 5;
//    int nums[length] = {0,1,2,3,4};
//    list<int> numbers;
//    for(int i = 0; i < length; i++) {
//        numbers.push_back(i);
//    }
    int m = 3;
//    remainNumber(numbers, m);
    cout<<remianNumber(length,m)<<endl;
}
