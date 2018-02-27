#include <iostream>
#include "BinaryTree.h"

using namespace::std;
using Nathan::BinaryTreeNode;
using Nathan::BinaryTree;

int main(){
    BinaryTreeNode<int> *node_1 = new BinaryTreeNode<int>(3);
    BinaryTree<int> tree(node_1);
    tree.insert(2);
    tree.insert(4);
    tree.insert(1);
    tree.insert(5);
    tree.inOrder();
}