#include <iostream>
#include <vector>
#include <stack>

/*
 * 请实现一个函数，用来判断一棵二叉树是不是对称的。
 * 如果一棵二叉树和它的镜像一样，那么它是对称的。
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
    bool isSubSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2) {
        if(!pRoot1 && pRoot2) {
            return true;
        }
        if(!pRoot1 || !pRoot2) {
            return false;
        }
        if(pRoot1->val != pRoot2->val) {
            return false;
        }
        return isSubSymmetrical(pRoot1->left,pRoot2->right) && isSubSymmetrical(pRoot1->right,pRoot2->left);
    }

    bool isSymmetrical(TreeNode* root) {
        return isSubSymmetrical(root,root);
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
    TreeNode* node_7 = new TreeNode(8);
    TreeNode* node_8 = new TreeNode(9);

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

    node_4->left = node_7;
    node_4->right = node_8;
    node_7->parent = node_4;
    node_8->parent = node_4;

    Solution solution = Solution();
//    cout<<solution.getNext(root)->val<<endl;
//    cout<<solution.getNext(node_1)->val<<endl;
//    cout<<solution.getNext(node_2)->val<<endl;
//    cout<<solution.getNext(node_3)->val<<endl;
//    cout<<solution.getNext(node_4)->val<<endl;
//    cout<<solution.getNext(node_5)->val<<endl;
//    cout<<solution.getNext(node_6)->val<<endl;
//    cout<<solution.getNext(node_7)->val<<endl;
    cout<<solution.getNext(node_3)->val<<endl;
}