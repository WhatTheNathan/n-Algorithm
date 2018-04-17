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
        ListNode* next = currentNode->next;
        ListNode* previous = nullptr;
        while(currentNode && next) {
            if(next->val == currentNode->val) {
                int value = currentNode->val;
                ListNode* deleteNode = nullptr;
                while(currentNode && currentNode->val == value) {
                    deleteNode = currentNode;
                    currentNode = currentNode->next;
                    delete deleteNode;
                }
                if(!previous)
                    head = currentNode;
                else
                    previous->next = currentNode;
            } else {
                previous = currentNode;
                currentNode = currentNode->next;
            }
            if(currentNode)
                next = currentNode->next;
        }
        return head;
    }
};

int main(){
    ListNode* node_1 = new ListNode(1);
    ListNode* node_2 = new ListNode(2);
    ListNode* node_3 = new ListNode(3);
    ListNode* node_4 = new ListNode(3);
    ListNode* node_5 = new ListNode(4);
    ListNode* node_6 = new ListNode(4);
    ListNode* node_7 = new ListNode(5);
    node_1->next = node_2;
    node_2->next = node_3;
    node_3->next = node_4;
    node_4->next = node_5;
    node_5->next = node_6;
    node_6->next = node_7;

    Solution solution = Solution();
    ListNode* head = solution.deleteDuplicates(node_1);
    while(head){
        cout<<head->val<<endl;
        head = head->next;
    }

}