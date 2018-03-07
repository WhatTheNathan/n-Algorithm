#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /* special case */
        if(n == 1 && head->next == nullptr) {
            delete head;
            head = nullptr;
            return nullptr;
        }
        ListNode* p = head;
        ListNode* iter = head;
        ListNode* pp = nullptr;
        /* find */
        for(int i = 1; i < n; i++)
            iter = iter->next;
        while(iter->next != nullptr) {
            iter = iter->next;
            pp = p;
            p = p->next;
        }
        /* remove */
        if (pp == nullptr)
            return p->next;
        pp->next = p->next;
        delete p;
        p = nullptr;
        return head;
    }
};

int main(){
    ListNode* node_1 = new ListNode(1);
    ListNode* node_2 = new ListNode(2);
    ListNode* node_3 = new ListNode(3);
    ListNode* node_4 = new ListNode(4);
    ListNode* node_5 = new ListNode(5);
    node_1->next = node_2;
    node_2->next = node_3;
    node_3->next = node_4;
    node_4->next = node_5;

    Solution solution = Solution();
    std::cout<<solution.removeNthFromEnd(node_1,1)->next->val<<std::endl;
}