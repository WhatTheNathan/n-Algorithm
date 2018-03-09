/**
 * Description:
 * 请完成一个函数，输入一个二叉树，该函数输出它的镜像
 */

#include <iostream>

using namespace::std;

struct BinaryTreeNode {
    int val;
    BinaryTreeNode* leftChild;
    BinaryTreeNode* rightChild;
    BinaryTreeNode(int x) : val(x),leftChild(nullptr),rightChild(nullptr) {}
};

void mirror(BinaryTreeNode* root) {
    if(!root)
        return;
    BinaryTreeNode* temp = root->leftChild;
    root->leftChild = root->rightChild;
    root->rightChild = temp;
    mirror(root->leftChild);
    mirror(root->rightChild);
}


int main(){
    BinaryTreeNode* treeNode_1 = new BinaryTreeNode(8);
    BinaryTreeNode* treeNode_2 = new BinaryTreeNode(6);
    BinaryTreeNode* treeNode_3 = new BinaryTreeNode(10);
    BinaryTreeNode* treeNode_4 = new BinaryTreeNode(5);
    BinaryTreeNode* treeNode_5 = new BinaryTreeNode(7);
    BinaryTreeNode* treeNode_6 = new BinaryTreeNode(9);
    BinaryTreeNode* treeNode_7 = new BinaryTreeNode(11);

    treeNode_1->leftChild = treeNode_2;
//    treeNode_1->rightChild = treeNode_3;
    treeNode_2->leftChild = treeNode_4;
    treeNode_2->rightChild = treeNode_5;
//    treeNode_3->leftChild = treeNode_6;
//    treeNode_3->rightChild = treeNode_7;

    mirror(treeNode_1);
    cout<<treeNode_1->rightChild->rightChild->val<<endl;
}