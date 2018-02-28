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

      tree.inOrder();
//    tree.preOrder();
//    tree.postOrder();
//    tree.nonrecInOrder();
//    tree.nonrecPreOrder();
//    tree.nonrecPostOrder();
}