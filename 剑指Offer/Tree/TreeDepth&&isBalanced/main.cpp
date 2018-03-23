#include <iostream>

/*
 * Description:
 * 输入一颗二叉树的根结点，求该树的深度。
 * 从根节点到叶结点一次经过的结点形成树的一条路径，最长路径的长度为树的深度。
 * 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。
 * 如果某二叉树中任意结点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
 */

using namespace::std;

struct BinaryTreeNode {
    int value;
    BinaryTreeNode* leftChild;
    BinaryTreeNode* rightChild;
    BinaryTreeNode(int x) : value(x), leftChild(nullptr), rightChild(nullptr) {}
};

int TreeDepth(BinaryTreeNode* root) {
    if(!root)
        return 0;
    return max(TreeDepth(root->leftChild), TreeDepth(root->rightChild)) + 1;
}

bool isBalanced(BinaryTreeNode* root) {
    if(!root)
        return true;
    int leftDepth = TreeDepth(root->leftChild);
    int rightDepth = TreeDepth(root->rightChild);

    return ( (abs(leftDepth - rightDepth) <= 1) && isBalanced(root->leftChild) && isBalanced(root->rightChild));
}

int main(){
    BinaryTreeNode* root = new BinaryTreeNode(10);
    BinaryTreeNode* treeNode_1 = new BinaryTreeNode(6);
    BinaryTreeNode* treeNode_2 = new BinaryTreeNode(14);
    BinaryTreeNode* treeNode_3 = new BinaryTreeNode(4);
    BinaryTreeNode* treeNode_4 = new BinaryTreeNode(8);
    BinaryTreeNode* treeNode_5 = new BinaryTreeNode(12);
    BinaryTreeNode* treeNode_6 = new BinaryTreeNode(16);
    BinaryTreeNode* treeNode_7 = new BinaryTreeNode(16);

    root->leftChild = treeNode_1;
    root->rightChild = treeNode_2;
    treeNode_1->leftChild = treeNode_3;
    treeNode_1->rightChild = treeNode_4;
    treeNode_2->leftChild = treeNode_5;
    treeNode_2->rightChild = treeNode_6;
    treeNode_3->leftChild = treeNode_7;

    cout<<TreeDepth(root)<<endl;
    cout<<isBalanced(root->leftChild)<<endl;
}