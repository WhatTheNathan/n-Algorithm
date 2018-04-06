#include <iostream>
#include <map>

using namespace::std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* first) {
    if(!first) {
        return false;
    }
    ListNode* slow = first->next;
    if(!slow){
        return false;
    }
    ListNode* fast = slow->next;
    while(slow && fast) {
        if(slow == fast) {
            return true;
        }
        slow = slow->next;
        fast = fast->next;
        if(fast)
            fast = fast->next;
    }
    return false;
};

int main(){
    ListNode* node_1 = new ListNode(1);
    ListNode* node_2 = new ListNode(2);
    ListNode* node_3 = new ListNode(3);
    ListNode* node_4 = new ListNode(4);
    ListNode* node_5 = new ListNode(5);
    ListNode* node_6 = new ListNode(6);
    node_1->next = node_2;
    node_2->next = node_3;
    node_3->next = node_4;
    node_4->next = node_5;
    node_5->next = node_6;
    node_6->next = node_2;

    Solution solution = Solution();
    cout<<solution.detectCycle(node_1)->val<<endl;

}