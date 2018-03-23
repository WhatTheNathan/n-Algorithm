/**
 * Description:
 * 输入某二叉树的前序遍历和中序遍历的结果，重建出该二叉树
 */

#include <iostream>

using namespace::std;

template <class T>
class TreeNode {
public:
    TreeNode(T data) {
        _data = data;
        leftChild = nullptr;
        rightChild = nullptr;
    }

    TreeNode<int> *createTree(T *inOrder, T *preOrder, int length) {
        if(length == 0)
            return nullptr;
        int k = 0;
        while(preOrder[0] != inOrder[k])
            k++;
        TreeNode<T> *root = new TreeNode<T>(preOrder[0]);
        root->leftChild = createTree(inOrder,preOrder + 1, k);
        root->rightChild = createTree(inOrder + k +1, preOrder + k + 1, length - k - 1);
        return root;
    }

    T value() const {
        return _data;
    }

    TreeNode<T> *getLeft() const {
        return leftChild;
    }

    TreeNode<T> *getRight() const {
        return rightChild;
    }

private:
    T _data;
    TreeNode<T> *leftChild;
    TreeNode<T> *rightChild;
};

int main(){
    int inOrder[] = {4,7,2,1,5,3,8,6};
    int preOrder[] = {1,2,4,7,3,5,6,8};
    TreeNode<int> *root = new TreeNode<int>(0);
    root = root->createTree(inOrder,preOrder,8);
    cout<<root->getRight()->getRight()->getLeft()->value()<<endl;
}