#include <iostream>
#include "BinarySearchTree.h"

using namespace::std;
using Nathan::TreeNode;
using Nathan::BinarySearchTree;

int main(){
     TreeNode<int> *node_1 = new TreeNode<int>(12);
     BinarySearchTree<int> tree(node_1);
     tree.insert(5);
     tree.insert(18);
     tree.insert(2);
     tree.insert(9);
     tree.insert(15);
     tree.insert(19);
     tree.insert(17);

//    tree.inOrder();
//    tree.preOrder();
//    tree.postOrder();
//    tree.nonrecInOrder();
//    tree.nonrecPreOrder();
//    tree.nonrecPostOrder();

//    TreeNode<int> *minNode = tree.getMinimunNode(tree.getRoot());
//    cout<<minNode->value()<<endl;
//
//    TreeNode<int> *maxNode = tree.getMaximumNode(tree.getRoot());
//    cout<<maxNode->value()<<endl;

//    TreeNode<int> *successor = tree.getSuccessor(tree.getRoot());
//    cout<<successor->value()<<endl;

//    TreeNode<int> *predecessor = tree.getPredecessor(tree.getRoot());
//    cout<<predecessor->value()<<endl;

//    TreeNode<int> *node18 = tree.search(18);
//    cout<<node18->value()<<endl;

//    tree.transplant(node18,tree.getRoot());
//    tree.inOrder();

//    tree.deleteNode(tree.getRoot());
//    tree.inOrder();
}