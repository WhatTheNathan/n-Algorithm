#include <iostream>
#include <vector>
#include <queue>
#include <map>

/*
 * 从上到下按层打印二叉树，同一层的结点按从左到右的顺序打印，每一层打印一行
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
    typedef pair<TreeNode*,int> pairr;
    void printLevel(TreeNode* root) {
        if(!root)
            return;
        int currentLevel = 0;
        queue<pairr> q;
        q.push({root,currentLevel});
        while(!q.empty()) {
            pairr currentNode = q.front();
            q.pop();
            if(currentNode.second > currentLevel) {
                cout<<endl;
                currentLevel = currentNode.second;
            }
            cout<<currentNode.first->val<<" ";
            if(currentNode.first->left)
                q.push({currentNode.first->left,currentNode.second+1});
            if(currentNode.first->right)
                q.push({currentNode.first->right,currentNode.second+1});
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
    solution.printLevel(root);
}