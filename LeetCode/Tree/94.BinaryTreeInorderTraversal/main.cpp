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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder = {};
        stack<TreeNode*> stack;
        TreeNode* currentNode = root;
        while(1) {
            while(currentNode){
                stack.push(currentNode);
                currentNode = currentNode->left;
            }
            if(!stack.empty()) {
                currentNode = stack.top();
                stack.pop();
                inorder.push_back(currentNode->val);
                currentNode = currentNode->right;
            } else {
                break;
            }
        }
        return inorder;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    TreeNode* node_1 = new TreeNode(2);
    TreeNode* node_2 = new TreeNode(3);
    TreeNode* node_3 = new TreeNode(4);
    TreeNode* node_4 = new TreeNode(5);
    TreeNode* node_5 = new TreeNode(6);
    TreeNode* node_6 = new TreeNode(7);

//    root->left = node_1;
//    root->right = node_2;
//    node_1->left = node_3;
//    node_1->right = node_4;
//    node_2->left = node_5;
//    node_2->right = node_6;

    Solution solution = Solution();
    vector<int> inorder = solution.inorderTraversal(root);
    for(auto num: inorder) {
        cout<<num<<" ";
    }
    cout<<endl;
}