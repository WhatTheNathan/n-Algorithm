#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stack>

/*
 * 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印
 * 第二层按照从右到左的顺序打印，以此类推。
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
    void printZhi(TreeNode* root) {
        if(!root)
            return;
        int current = 0;
        int next = 1;
        stack<TreeNode*> stacks[2];
        stacks[current].push(root);
        while(!stacks[0].empty() || !stacks[1].empty()) {
            TreeNode* node = stacks[current].top();
            stacks[current].pop();

            cout<<node->val<<" ";

            if(current == 0) {
                if(node->left)
                    stacks[next].push(node->left);
                if(node->right)
                    stacks[next].push(node->right);
            }else {
                if(node->right)
                    stacks[next].push(node->right);
                if(node->left)
                    stacks[next].push(node->left);
            }

            if(stacks[current].empty()) {
                cout<<endl;
                current = 1 - current;
                next = 1 - next;
            }
        }
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
//    cout<<solution.getNext(node_3)->val<<endl;
    solution.printZhi(root);
}