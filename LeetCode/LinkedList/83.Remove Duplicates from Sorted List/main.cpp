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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) {
            return nullptr;
        }
        ListNode* currentNode = head;
        while(currentNode && currentNode->next) {
            ListNode* next = currentNode->next;
            while(next && next->val == currentNode->val) {
                ListNode* deleteNode = next;
                next = next->next;
                currentNode->next = next;
                delete deleteNode;
            }
            currentNode = currentNode->next;
        }
        return head;
    }
};

int main(){
    ListNode* node_1 = new ListNode(1);
    ListNode* node_2 = new ListNode(1);
    ListNode* node_3 = new ListNode(2);
    ListNode* node_4 = new ListNode(2);
    ListNode* node_5 = new ListNode(5);
    ListNode* node_6 = new ListNode(6);
    node_1->next = node_2;
//    node_2->next = node_3;
//    node_3->next = node_4;
//    node_4->next = node_5;
//    node_5->next = node_6;

    Solution solution = Solution();
    ListNode* head = solution.deleteDuplicates(node_1);
    cout<<head->val<<endl;

}