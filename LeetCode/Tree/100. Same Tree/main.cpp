#include <iostream>
#include <vector>
#include <stack>

using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if( (p && !q) || (!p && q) || p->val != q->val)
            return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    TreeNode* node_1 = new TreeNode(2);
    TreeNode* node_2 = new TreeNode(3);
    TreeNode* node_3 = new TreeNode(1);
    TreeNode* node_4 = new TreeNode(3);
//    TreeNode* node_5 = new TreeNode(0);
//    TreeNode* node_6 = new TreeNode(8);

    root->left = node_1;
    root->right = node_2;
    node_3->right = node_4;
//    node_1->left = node_3;
//    node_1->right = node_4;
//    node_2->left = node_5;
//    node_2->right = node_6;
    Solution solution = Solution();
    solution.isSameTree(root,node_3);

}