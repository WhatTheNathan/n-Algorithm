/**
 * Description:
 * 从上往下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印。
 */

#include <iostream>
#include <queue>

using namespace::std;

struct BinaryTreeNode {
    int val;
    BinaryTreeNode* leftChild;
    BinaryTreeNode* rightChild;
    BinaryTreeNode(int x) : val(x),leftChild(nullptr),rightChild(nullptr) {}
};

void printFromTop2Bottom(BinaryTreeNode* root) {
    queue<BinaryTreeNode*> queue;
    queue.push(root);
    while(!queue.empty()) {
        BinaryTreeNode* node = queue.front();
        queue.pop();
        if(node->leftChild)
            queue.push(node->leftChild);
        if(node->leftChild)
            queue.push(node->rightChild);
        cout<<node->val<<endl;
    }
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
    treeNode_1->rightChild = treeNode_3;
    treeNode_2->leftChild = treeNode_4;
    treeNode_2->rightChild = treeNode_5;
    treeNode_3->leftChild = treeNode_6;
    treeNode_3->rightChild = treeNode_7;

    printFromTop2Bottom(treeNode_1);
}