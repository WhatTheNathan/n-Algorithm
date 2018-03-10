/**
 * Description:
 * 输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
 */

#include <iostream>
#include <vector>

using namespace::std;

struct BinaryTreeNode {
    int val;
    BinaryTreeNode* leftChild;
    BinaryTreeNode* rightChild;
    BinaryTreeNode(int x) : val(x),leftChild(nullptr),rightChild(nullptr) {}
};


void subFindPath(BinaryTreeNode* node, int expectSum, vector<int> &path, int currentSum) {
    if(!node || currentSum + node->val > expectSum) {
        return;
    }
    currentSum += node->val;
    path.push_back(node->val);

    if(expectSum == currentSum && !node->rightChild && !node->leftChild) {
        cout<<"======="<<endl;
        for(int element: path) {
            cout<<element<<endl;
        }
        cout<<"======="<<endl;
    }

    if(node->leftChild) {
        subFindPath(node->leftChild,expectSum,path,currentSum);
    }
    if(node->rightChild) {
        subFindPath(node->rightChild,expectSum,path,currentSum);
    }
    currentSum -= node->val;
    path.pop_back();
}

void findPath(BinaryTreeNode* node, int sum) {
    vector<int> path;
    subFindPath(node,sum,path,0);
}

int main(){
    BinaryTreeNode* treeNode_1 = new BinaryTreeNode(10);
    BinaryTreeNode* treeNode_2 = new BinaryTreeNode(5);
    BinaryTreeNode* treeNode_3 = new BinaryTreeNode(12);
    BinaryTreeNode* treeNode_4 = new BinaryTreeNode(4);
    BinaryTreeNode* treeNode_5 = new BinaryTreeNode(7);
    BinaryTreeNode* treeNode_6 = new BinaryTreeNode(9);
    BinaryTreeNode* treeNode_7 = new BinaryTreeNode(11);

    treeNode_1->leftChild = treeNode_2;
    treeNode_1->rightChild = treeNode_3;
    treeNode_2->leftChild = treeNode_4;
    treeNode_2->rightChild = treeNode_5;
//    treeNode_3->leftChild = treeNode_6;
//    treeNode_3->rightChild = treeNode_7;

    findPath(treeNode_1,22);
}