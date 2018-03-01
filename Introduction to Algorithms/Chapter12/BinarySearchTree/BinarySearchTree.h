#include <iostream>
#include <stack>
#include <queue>
#include "TreeNode.h"

#ifndef _BINARYSEARCHTREE_H
#define _BINARYSEARCHTREE_H

namespace Nathan {
    template <class T>
    class BinarySearchTree {
    public:
        BinarySearchTree(TreeNode<T> *root = nullptr);

        bool isEmpty() const;
        int getSize() const;
        TreeNode<T> *getRoot() const;

        void inOrder() const;
        void inOrder(TreeNode<T> *node) const;
        void preOrder() const;
        void preOrder(TreeNode<T> *node) const;
        void postOrder() const;
        void postOrder(TreeNode<T> *node) const;

        /* search */
        TreeNode<T>* search(TreeNode<T> *node,const T &data);
        TreeNode<T>* search(const T &data);
        TreeNode<T>* getMinimunNode(TreeNode<T> *node) const;
        TreeNode<T>* getMaximumNode(TreeNode<T> *node) const;
        TreeNode<T>* getSuccessor(TreeNode<T> *node) const;
        TreeNode<T>* getPredecessor(TreeNode<T> *node) const;

        /* insert */
        bool insert(const T &data);
        void insert(const T &data, TreeNode<T> *node);

        /* delete */
        void transplant(TreeNode<T> *newTreeRoot, TreeNode<T> *oldTreeRoot);
        void deleteNode(TreeNode<T>* node);

    private:
        TreeNode<T> *_root;
        int _size = 0;
    };

    template <class T>
    BinarySearchTree<T>::BinarySearchTree(TreeNode<T> *root) {
        _root = root;
        if (_root)
            _size = 1;
    }

    template <class T>
    bool BinarySearchTree<T>::isEmpty() const {
        return _size == 0;
    }

    template <class T>
    int BinarySearchTree<T>::getSize() const {
        return _size;
    }

    template <class T>
    TreeNode<T>* BinarySearchTree<T>::getRoot() const {
        return _root;
    }

    template <class T>
    void BinarySearchTree<T>::inOrder() const {
        inOrder(_root);
    }

    template <class T>
    void BinarySearchTree<T>::inOrder(TreeNode<T> *node) const {
        if (node) {
            inOrder(node->_leftChild);
            std::cout<<node->_data<<std::endl;
            inOrder(node->_rightChild);
        }
    }

    template <class T>
    void BinarySearchTree<T>::preOrder() const {
        preOrder(_root);
    }

    template <class T>
    void BinarySearchTree<T>::preOrder(TreeNode<T> *node) const {
        if (node) {
            std::cout<<node->_data<<std::endl;
            preOrder(node->_leftChild);
            preOrder(node->_rightChild);
        }
    }

    template <class T>
    void BinarySearchTree<T>::postOrder() const {
        postOrder(_root);
    }

    template <class T>
    void BinarySearchTree<T>::postOrder(TreeNode<T> *node) const {
        if (node) {
            postOrder(node->_leftChild);
            postOrder(node->_rightChild);
            std::cout<<node->_data<<std::endl;
        }
    }

    template <class T>
    bool BinarySearchTree<T>::insert(const T &data) {
        TreeNode<T> *newNode =  new TreeNode<T>(data);
        if(!_root)
            _root = newNode;
        TreeNode<T> *tempRoot = _root;
        TreeNode<T> *p = nullptr;
        while(tempRoot) {
            p = tempRoot;
            if(newNode->_data < tempRoot->_data)
                tempRoot = tempRoot->_leftChild;
            else tempRoot = tempRoot->_rightChild;
        }
        newNode->_parent = p;
        if(p->_data < newNode->_data)
            p->_rightChild = newNode;
        else p->_leftChild = newNode;
        _size++;
    }

    template <class T>
    TreeNode<T>* BinarySearchTree<T>::search(TreeNode<T> *node, const T &data) {
        if (node == nullptr || node->_data == data)
            return node;
        if(data < _root->_data)
            return search(node->_leftChild,data);
        else return search(node->_rightChild,data);
    }

    template <class T>
    TreeNode<T>* BinarySearchTree<T>::search(const T &data) {
        TreeNode<T> *currentNode = _root;
        while (currentNode && currentNode->_data != data) {
            if (currentNode->_data < data)
                currentNode = currentNode->_rightChild;
            else currentNode = currentNode->_leftChild;
        }
        return currentNode;
    }

    template <class T>
    TreeNode<T>* BinarySearchTree<T>::getMinimunNode(TreeNode<T> *node) const {
        TreeNode<T> *currentNode = node;
        while(currentNode->_leftChild) {
            currentNode = currentNode->_leftChild;
        }
        return currentNode;
    }

    template <class T>
    TreeNode<T>* BinarySearchTree<T>::getMaximumNode(TreeNode<T> *node) const {
        TreeNode<T> *currentNode = node;
        while(currentNode->_rightChild) {
            currentNode = currentNode->_rightChild;
        }
        return currentNode;
    }

    template <class T>
    TreeNode<T>* BinarySearchTree<T>::getSuccessor(TreeNode<T> *node) const {
        TreeNode<T> *currentNode = node;
        if(currentNode->_rightChild)
            return getMinimunNode(currentNode->_rightChild);
        TreeNode<T> *p = currentNode->_parent;
        while(p && p->_rightChild == currentNode) {
            currentNode = p;
            p = p->_parent;
        }
        return p;
    }

    template <class T>
    TreeNode<T>* BinarySearchTree<T>::getPredecessor(TreeNode<T> *node) const {
        TreeNode<T> *currentNode = node;
        if(currentNode->_leftChild)
            return getMaximumNode(currentNode->_leftChild);
        return currentNode->_parent->_parent;
    }

    template <class T>
    void BinarySearchTree<T>::transplant(TreeNode<T> *newTreeRoot, TreeNode<T> *oldTreeRoot) {
        if(oldTreeRoot->_parent == nullptr)
            this->_root = newTreeRoot;
        else if(oldTreeRoot == oldTreeRoot->_parent->_leftChild)
            oldTreeRoot->_parent->_leftChild = newTreeRoot;
        else oldTreeRoot->_parent->_rightChild = newTreeRoot;
        if(newTreeRoot)
            newTreeRoot->_parent = oldTreeRoot->_parent;
    }

    template <class T>
    void BinarySearchTree<T>::deleteNode(TreeNode<T> *node) {
        /* 1 && 2 所删除节点没有左孩子或者没有右孩子 */
        if(!node->_leftChild)
            transplant(node,node->_rightChild);
        else if(!node->_rightChild)
            transplant(node,node->_leftChild);

        /* 3 && 4 所删除节点既有左孩子也有右孩子,先找到其后继 */
        else {
            TreeNode<T> *successor = getSuccessor(node);
            /* 3. 若后继不是所删除节点的右孩子 */
            if(successor->_parent != node) {
                transplant(successor->_rightChild,successor);
                successor->_rightChild = node->_rightChild;
                successor->_rightChild->_parent = successor;
            }
            /* 4. 若后继是所删除节点的右孩子，同时覆盖了第三种情况的后续操作 */
            transplant(successor,node);
            successor->_leftChild = node->_leftChild;
            successor->_leftChild->_parent = successor;
        }
        _size--;
    }
}
#endif