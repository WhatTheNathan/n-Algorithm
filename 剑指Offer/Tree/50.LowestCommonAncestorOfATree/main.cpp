/*
 * 树中两个结点的最低公共祖先
 * 分为三种情况
 * 1. 二叉搜索树
 * 2. 不是二叉树，但存在指向父亲的指针
 * 3. 没有指向父亲的指针,以二叉树为例子吧
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
//    TreeNode *parent;
//    TreeNode(int x) : val(x), left(NULL), right(NULL),parent(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* node_1, TreeNode* node_2) {
//        if(!root || !node_1 || !node_2){
//            return nullptr;
//        }
//        TreeNode* currentNode = root;
//        if(node_1->val > node_2->val) {
//            swap(node_1,node_2);
//        }
//        while(currentNode) {
//            if(node_1->val <= currentNode->val && currentNode->val <= node_2->val) {
//                return currentNode;
//            }
//            else if (node_2->val < currentNode->val) {
//                currentNode = currentNode->left;
//            }
//            else if (currentNode->val < node_1->val) {
//                currentNode = currentNode->right;
//            }
//        }
//        return nullptr;
//    }

//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* node_1, TreeNode* node_2) {
//        if(!root || !node_1 || !node_2){
//            return nullptr;
//        }
//        int length_1 = getLength(node_1);
//        int length_2 = getLength(node_2);
//        int diff = abs(length_1 - length_2);
//        if(length_1 > length_2) {
//            swap(node_1,node_2);
//            swap(length_1,length_2);
//        }
//        for(;diff > 0;diff--) {
//            node_2 = node_2->parent;
//        }
//        while(node_1 && node_2) {
//            if(node_1 == node_2) {
//                return node_1;
//            }
//            node_1 = node_1->parent;
//            node_2 = node_2->parent;
//        }
//        return nullptr;
//    }
//
//    int getLength(TreeNode* first) {
//        TreeNode *temp = first;
//        int length = 0;
//        while(temp) {
//            length++;
//            temp = temp->parent;
//        }
//        return length;
//    }

    bool getNodePath(TreeNode* root, TreeNode* searchingNode, vector<TreeNode*>& list) {
        if(root == searchingNode) {
            return true;
        }
        bool found = false;
        list.push_back(root);
        vector<TreeNode*> range;
        if(root->left) {range.push_back(root->left);}
        if(root->right) {range.push_back(root->right);}
        for(auto currentNode: range) {
            found = getNodePath(currentNode,searchingNode, list);
            if(found)
                return true;
        }
        if(!found)
            list.pop_back();
        return false;
    }

    TreeNode* getLastCommonNode(vector<TreeNode*> list_1, vector<TreeNode*> list_2) {
        TreeNode* last = nullptr;
        vector<TreeNode*>::iterator iterator1 = list_1.begin();
        vector<TreeNode*>::iterator iterator2 = list_2.begin();
        while(iterator1 != list_1.end() && iterator2 != list_2.end()) {
            if(*iterator1 == *iterator2) {
                last = *iterator1;
            }
            iterator1++;
            iterator2++;
        }
        return last;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* node_1, TreeNode* node_2) {
        if (!root || !node_1 || !node_2) {
            return nullptr;
        }
        vector<TreeNode*> list_1;
        vector<TreeNode*> list_2;
        getNodePath(root,node_1,list_1);
        getNodePath(root,node_2,list_2);

        return getLastCommonNode(list_1,list_2);
    }
};

int main(){
    TreeNode* root = new TreeNode(10);
    TreeNode* node_1 = new TreeNode(4);
    TreeNode* node_2 = new TreeNode(14);
    TreeNode* node_3 = new TreeNode(2);
    TreeNode* node_4 = new TreeNode(6);
    TreeNode* node_5 = new TreeNode(13);
    TreeNode* node_6 = new TreeNode(17);
    TreeNode* node_7 = new TreeNode(3);
    TreeNode* node_8 = new TreeNode(8);

    root->left = node_1;
    root->right = node_2;
//    node_1->parent = root;
//    node_2->parent = root;

    node_1->left = node_3;
    node_1->right = node_4;
//    node_3->parent = node_1;
//    node_4->parent = node_1;

    node_2->left = node_5;
    node_2->right = node_6;
//    node_5->parent = node_2;
//    node_6->parent = node_2;

    node_4->left = node_7;
    node_4->right = node_8;
//    node_7->parent = node_4;
//    node_8->parent = node_4;

    Solution solution = Solution();
    cout<<solution.lowestCommonAncestor(root, node_7, node_8)->val<<endl;
}