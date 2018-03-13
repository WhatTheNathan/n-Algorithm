#include <iostream>

/*
 * Description:
 * 输入一颗二叉搜索树，将该二叉搜索树转换成一个排序的双向链表
 * 要求不能创建任何新的结点，只能调整树中结点指针的指向。
 */

using namespace::std;

struct BinaryTreeNode {
    int value;
    BinaryTreeNode* leftChild;
    BinaryTreeNode* rightChild;
    BinaryTreeNode(int x) : value(x), leftChild(nullptr), rightChild(nullptr) {}
};

BinaryTreeNode* subLeftConvert(BinaryTreeNode* node) {
    if(!node)
        return nullptr;
    if(node->leftChild)
        node->leftChild->rightChild = node;
    if(node->rightChild) {
        node->rightChild->leftChild = node;
        return subLeftConvert(node->rightChild);
    }
    return node;
}

BinaryTreeNode* subRightConvert(BinaryTreeNode* node) {
    if(!node)
        return nullptr;
    if(node->rightChild)
        node->rightChild->leftChild = node;
    if(node->leftChild) {
        node->leftChild->rightChild = node;
        return subRightConvert(node->leftChild);
    }
    return node;
}

BinaryTreeNode* convert2doubleLinkedList(BinaryTreeNode* root) {
    if(!root)
        return nullptr;
    BinaryTreeNode* leftChild = subLeftConvert(root->leftChild);
    if(leftChild) {
        leftChild->rightChild = root;
        root->leftChild = leftChild;
    }
    BinaryTreeNode* rightChild = subRightConvert(root->rightChild);
    if(rightChild) {
        rightChild->leftChild = root;
        root->rightChild = rightChild;
    }

    while(root->leftChild)
        root = root->leftChild;
    return root;
}

int main(){
    BinaryTreeNode* root = new BinaryTreeNode(10);
    BinaryTreeNode* treeNode_1 = new BinaryTreeNode(6);
    BinaryTreeNode* treeNode_2 = new BinaryTreeNode(14);
    BinaryTreeNode* treeNode_3 = new BinaryTreeNode(4);
    BinaryTreeNode* treeNode_4 = new BinaryTreeNode(8);
    BinaryTreeNode* treeNode_5 = new BinaryTreeNode(12);
    BinaryTreeNode* treeNode_6 = new BinaryTreeNode(16);

    root->leftChild = treeNode_1;
    root->rightChild = treeNode_2;
    treeNode_1->leftChild = treeNode_3;
    treeNode_1->rightChild = treeNode_4;
    treeNode_2->leftChild = treeNode_5;
    treeNode_2->rightChild = treeNode_6;

    BinaryTreeNode* head = convert2doubleLinkedList(root);
    cout<<head->value<<endl;
}