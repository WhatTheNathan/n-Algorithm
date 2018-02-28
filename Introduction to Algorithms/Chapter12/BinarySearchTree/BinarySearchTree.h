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

        void inOrder() const;
        void inOrder(TreeNode<T> *node) const;
        void preOrder() const;
        void preOrder(TreeNode<T> *node) const;
        void postOrder() const;
        void postOrder(TreeNode<T> *node) const;

        /* insert */
        bool insert(const T &data);
        void insert(const T &data, TreeNode<T> *node);

        /* delete */


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
    }
}
#endif