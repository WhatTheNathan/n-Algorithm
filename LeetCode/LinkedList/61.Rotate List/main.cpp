#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(nullptr) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        /* special case */
        if(head == nullptr || head->next == nullptr || k == 0)
            return head;
        ListNode* p = new ListNode(0);
        ListNode* pp = p;
        pp->next = head;

        int length = 0;
        int flag = 0;
        for(int i = 0; i < k; i++) {
            if(!p->next) {
                p = pp;
                flag = 1;
                break;
            }
            p = p->next;
            length++;
        }

        /* exceed the length of the list */
        if(flag){
            int times = k % length;
            for(int i = 0; i < times; i++) {
                p = p->next;
            }
        }

        while(p->next) {
            p = p->next;
            pp = pp->next;
        }
        if(pp->next == head)
            return head;
        /* reverse */
        p->next = head;
        head = pp->next;
        pp->next = nullptr;
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
    std::cout<<solution.rotateRight(node_1,7)->val<<std::endl;
}