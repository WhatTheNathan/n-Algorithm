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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head)
            return nullptr;
        if(m < n) {
            ListNode* p = head;
            ListNode* pp = nullptr;
            ListNode* previous = nullptr;
            int count = 1;

            // move to start point
            for( ; count < m; count++) {
                if(!p)
                    return head;
                previous = p;
                p = p->next;
            }
            ListNode* endPoint = p;

            while(count < (n + 1)) {
                if(!p)
                    return head;
                ListNode* temp = pp;
                pp = p;
                p = p->next;
                pp->next = temp;
                count++;
            }

            if(previous)
                previous->next = pp;
            else
                head = pp;
            endPoint->next = nullptr;
            if(p)
                endPoint->next = p;
        }
        return head;
    }
};

int main(){
    ListNode* node_1 = new ListNode(1);
    ListNode* node_2 = new ListNode(2);
    ListNode* node_3 = new ListNode(3);
    ListNode* node_4 = new ListNode(4);
    ListNode* node_5 = new ListNode(5);
//    ListNode* node_6 = new ListNode(4);
//    ListNode* node_7 = new ListNode(5);
    node_1->next = node_2;
//    node_2->next = node_3;
//    node_3->next = node_4;
//    node_4->next = node_5;
//    node_5->next = node_6;
//    node_6->next = node_7;

    Solution solution = Solution();
    ListNode* node = solution.reverseBetween(node_1,1,2);
//    solution.reorderList(node_1);
    while(node) {
        cout<<node->val<<endl;
        node = node->next;
    }
}