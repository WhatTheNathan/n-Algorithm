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
    bool findPath(TreeNode* root, TreeNode* node, vector<TreeNode*> &path) {
        if(!root || !node)
            return false;
        if(root == node) {
            path.push_back(node);
            return true;
        } else {
            path.push_back(root);
            if(findPath(root->left,node,path) || findPath(root->right,node,path)) {
                return true;
            }
            path.pop_back();
            return false;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> list_1, list_2;
        findPath(root, p, list_1);
        findPath(root, q, list_2);
        int length_1 = list_1.size();
        int length_2 = list_2.size();
        int diff = abs(length_1 - length_2);
        int i = length_1 - 1;
        int j = length_2 - 1;
        if(length_1 > length_2) {
            i -= diff;
        } else {
            j -= diff;
        }
        for( ; i >= 0; i--,j--) {
            if(list_1[i] == list_2[j]) {
                return list_1[i];
            }
        }
        return nullptr;
    }
};

int main(){
    TreeNode* root = new TreeNode(3);
    TreeNode* node_1 = new TreeNode(5);
    TreeNode* node_2 = new TreeNode(1);
    TreeNode* node_3 = new TreeNode(6);
    TreeNode* node_4 = new TreeNode(2);
    TreeNode* node_5 = new TreeNode(0);
    TreeNode* node_6 = new TreeNode(8);

    root->left = node_1;
    root->right = node_2;
    node_1->left = node_3;
    node_1->right = node_4;
    node_2->left = node_5;
    node_2->right = node_6;

    Solution solution = Solution();
    cout<<solution.lowestCommonAncestor(root,node_4,node_2)->val<<endl;
}