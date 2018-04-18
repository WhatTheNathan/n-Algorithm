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
    void reorderList(ListNode* head) {
        if(!head || !head->next) {
            return;
        }
        ListNode* pHead_1 = head;
        ListNode* pHead_2 = head;
        ListNode* temp = head->next;

        // find pHead_2 and divide
        while(temp && temp->next) {
            pHead_2 = pHead_2->next;
            temp = temp->next->next;
        }
        temp = pHead_2;
        pHead_2 = pHead_2->next;
        temp->next = nullptr;

        // reverse pList_2
        ListNode* pp = nullptr;
        while(pHead_2) {
            temp = pp;
            pp = pHead_2;
            pHead_2 = pHead_2->next;
            pp->next = temp;
        }
        pHead_2 = pp;

        //merge 2 lists
        while(pHead_1 && pHead_2) {
            temp = pHead_1->next;
            pHead_1->next = pHead_2;
            pHead_1 = temp;

            temp = pHead_2->next;
            pHead_2->next = pHead_1;
            pHead_2 = temp;
        }
    }
};

int main(){
    ListNode* node_1 = new ListNode(1);
    ListNode* node_2 = new ListNode(2);
    ListNode* node_3 = new ListNode(3);
    ListNode* node_4 = new ListNode(4);
//    ListNode* node_5 = new ListNode(4);
//    ListNode* node_6 = new ListNode(4);
//    ListNode* node_7 = new ListNode(5);
    node_1->next = node_2;
    node_2->next = node_3;
    node_3->next = node_4;
//    node_4->next = node_5;
//    node_5->next = node_6;
//    node_6->next = node_7;

    Solution solution = Solution();
    solution.reorderList(node_1);
    while(node_1) {
        cout<<node_1->val<<endl;
        node_1 = node_1->next;
    }
}