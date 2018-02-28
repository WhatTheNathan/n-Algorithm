#include <iostream>
#include "BinaryTree.h"

using namespace::std;
using Nathan::BinaryTreeNode;
using Nathan::BinaryTree;

int main(){
    BinaryTreeNode<int> *node_1 = new BinaryTreeNode<int>(4);
    BinaryTree<int> tree(node_1);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);

//    tree.inOrder();
//    tree.preOrder();
//    tree.postOrder();
//    tree.nonrecInOrder();
//    tree.nonrecPreOrder();
//    tree.nonrecPostOrder();
}