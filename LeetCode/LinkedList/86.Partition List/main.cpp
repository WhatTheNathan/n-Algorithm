#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(nullptr) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) {
            return nullptr;
        }

        ListNode* currentNode = head;
        ListNode* smallP;
        smallP->next = head;

        while(currentNode) {
            if(currentNode->val < x) {
                smallP = smallP->next;
                if(smallP != currentNode) {
                    int temp = smallP->val;
                    smallP->val = currentNode->val;
                    currentNode->val = temp;
                }
            }
            currentNode = currentNode->next;
        }
        return head;
    }
};

int main(){
    ListNode* node_1 = new ListNode(2);
    ListNode* node_2 = new ListNode(3);
    ListNode* node_3 = new ListNode(1);
    ListNode* node_4 = new ListNode(2);
    ListNode* node_5 = new ListNode(5);
    ListNode* node_6 = new ListNode(2);
    node_1->next = node_2;
    node_2->next = node_3;
//    node_3->next = node_4;
//    node_4->next = node_5;
//    node_5->next = node_6;

    Solution solution = Solution();
    ListNode* head = solution.partition(node_1,2);

    ListNode* node = head;
    while(node) {
        std::cout<<node->val<<std::endl;
        node = node->next;
    }
}