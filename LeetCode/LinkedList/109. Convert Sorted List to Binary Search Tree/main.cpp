#include <iostream>
#include <map>

using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x),next(nullptr) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev = nullptr;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        TreeNode *root = new TreeNode(slow->val);
        if (prev) {
            prev->next = nullptr;
        } else {
            head = prev;
        }

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};
int main(){
    ListNode* node_1 = new ListNode(-10);
    ListNode* node_2 = new ListNode(-3);
    ListNode* node_3 = new ListNode(0);
    ListNode* node_4 = new ListNode(5);
    ListNode* node_5 = new ListNode(9);
    node_1->next = node_2;
    node_2->next = node_3;
    node_3->next = node_4;
    node_4->next = node_5;

    Solution solution = Solution();
    TreeNode *root = solution.sortedListToBST(node_1);
}