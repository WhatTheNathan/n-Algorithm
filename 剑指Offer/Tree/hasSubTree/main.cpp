/**
 * Description:
 * 输入某二叉树的前序遍历和中序遍历的结果，重建出该二叉树
 */

#include <iostream>

using namespace::std;

struct BinaryTreeNode {
    int val;
    BinaryTreeNode* leftChild;
    BinaryTreeNode* rightChild;
    BinaryTreeNode(int x) : val(x),leftChild(nullptr),rightChild(nullptr) {}
};

bool doesTree1HasTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
    /* 必须要先判断pRoot2是否穷尽 */
    if(!pRoot2)
        return true;
    if(!pRoot1)
        return false;
    if(pRoot1->val != pRoot2->val)
        return false;

    return doesTree1HasTree2(pRoot1->leftChild,pRoot2->leftChild) && doesTree1HasTree2(pRoot1->rightChild,pRoot2->rightChild);
}

bool hasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
    bool result = false;
    if(pRoot1 && pRoot2) {
        if(pRoot1->val == pRoot2->val)
            result = doesTree1HasTree2(pRoot1,pRoot2);
        if(!result)
            result = hasSubTree(pRoot1->leftChild,pRoot2);
        if(!result)
            result = hasSubTree(pRoot1->rightChild,pRoot2);
    }
    return result;
}

int main(){
    BinaryTreeNode* treeNode_1 = new BinaryTreeNode(8);
    BinaryTreeNode* treeNode_2 = new BinaryTreeNode(8);
    BinaryTreeNode* treeNode_3 = new BinaryTreeNode(7);
    BinaryTreeNode* treeNode_4 = new BinaryTreeNode(9);
    BinaryTreeNode* treeNode_5 = new BinaryTreeNode(2);

    treeNode_1->leftChild = treeNode_2;
    treeNode_1->rightChild = treeNode_3;
    treeNode_2->leftChild = treeNode_4;
    treeNode_2->rightChild = treeNode_5;

    BinaryTreeNode* treeNode_6 = new BinaryTreeNode(8);
    BinaryTreeNode* treeNode_7 = new BinaryTreeNode(9);
    BinaryTreeNode* treeNode_8 = new BinaryTreeNode(2);

    treeNode_6->leftChild = treeNode_7;
    treeNode_6->rightChild = treeNode_8;

    cout<<hasSubTree(treeNode_1,treeNode_6)<<endl;
}