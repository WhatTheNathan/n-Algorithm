#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <string>
/*
 * 给定一棵二叉搜索树，请找出其中的第k大的结点。
 */
using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x) : val(x), left(NULL), right(NULL),parent(NULL) {}
};

class Solution {
public:
    void inOrder(TreeNode* node, vector<TreeNode*> &array) {
        if(node) {
            inOrder(node->left,array);
            array.push_back(node);
            inOrder(node->right,array);
        }
    }

    TreeNode* KthNode(TreeNode* root, unsigned int k) {
        if(!root || k == 0) {
            return nullptr;
        }
        vector<TreeNode*> array;
        inOrder(root,array);
        return array[array.size() - k];
    }
};

int main(){
    TreeNode* root = new TreeNode(5);
    TreeNode* node_1 = new TreeNode(3);
    TreeNode* node_2 = new TreeNode(7);
    TreeNode* node_3 = new TreeNode(2);
    TreeNode* node_4 = new TreeNode(4);
    TreeNode* node_5 = new TreeNode(6);
    TreeNode* node_6 = new TreeNode(8);
//    TreeNode* node_7 = new TreeNode(8);
//    TreeNode* node_8 = new TreeNode(9);

    root->left = node_1;
    root->right = node_2;
    node_1->parent = root;
    node_2->parent = root;

    node_1->left = node_3;
    node_1->right = node_4;
    node_3->parent = node_1;
    node_4->parent = node_1;

    node_2->left = node_5;
    node_2->right = node_6;
    node_5->parent = node_2;
    node_6->parent = node_2;

//    node_4->left = node_7;
//    node_4->right = node_8;
//    node_7->parent = node_4;
//    node_8->parent = node_4;

    Solution solution = Solution();
    cout<<solution.KthNode(root, 3)->val<<endl;

}