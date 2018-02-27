#include <iostream>
#include "BinaryTreeNode.h"

#ifndef _BINARYTREE_H
#define _BINARYTREE_H

namespace Nathan {
    template <class T>
    class BinaryTree {
    public:
        BinaryTree(BinaryTreeNode<T> *root = nullptr);

        bool isEmpty() const;

        void inOrder() const;
        void inOrder(BinaryTreeNode<T> *node) const;
        void preOrder() const;
        void preOrder(BinaryTreeNode<T> *node) const;
        void postOrder() const;
        void postOrder(BinaryTreeNode<T> *node) const;

        bool insert(const T &data);
        void insert(const T &data, BinaryTreeNode<T> *node);
    private:
        BinaryTreeNode<T> *_root;
        int _size = 0;
    };

    template <class T>
    BinaryTree<T>::BinaryTree(BinaryTreeNode<T> *root) {
        _root = root;
        if (_root)
            _size = 1;
    }

    template <class T>
    bool BinaryTree<T>::isEmpty() const {
        return _size == 0;
    }

    template <class T>
    void BinaryTree<T>::inOrder() const {
        inOrder(_root);
    }

    template <class T>
    void BinaryTree<T>::inOrder(BinaryTreeNode<T> *node) const {
        if (node) {
            inOrder(node->_leftChild);
            std::cout<<node->_data<<std::endl;
            inOrder(node->_rightChild);
        }
    }

    template <class T>
    void BinaryTree<T>::preOrder() const {
        preOrder(_root);
    }

    template <class T>
    void BinaryTree<T>::preOrder(BinaryTreeNode<T> *node) const {
        if (node) {
            std::cout<<node->_data<<std::endl;
            inOrder(node->_leftChild);
            inOrder(node->_rightChild);
        }
    }

    template <class T>
    void BinaryTree<T>::postOrder() const {
        postOrder(_root);
    }

    template <class T>
    void BinaryTree<T>::postOrder(BinaryTreeNode<T> *node) const {
        if (node) {
            inOrder(node->_leftChild);
            inOrder(node->_rightChild);
            std::cout<<node->_data<<std::endl;
        }
    }

    template <class T>
    bool BinaryTree<T>::insert(const T &data) {
        BinaryTreeNode<T> *node =  new BinaryTreeNode<T>(data);
        if (isEmpty()) {
            _root = node;
            _size++;
            return true;
        }
        BinaryTreeNode<T> *nodeNow = _root;
        while(nodeNow) {
            if (nodeNow->_data == node->_data) {
                return false;
            } else if (nodeNow->_data < node->_data) {
                if (!nodeNow->_leftChild) {
                    nodeNow->_leftChild = node;
                    _size++;
                    return true;
                }
                nodeNow = nodeNow->_leftChild;
            } else if (nodeNow->_data > node->_data) {
                if (!nodeNow->_rightChild) {
                    nodeNow->_rightChild = node;
                    _size++;
                    return true;
                }
                nodeNow = nodeNow->_rightChild;
            }
        }
    }

    template <class T>
    void BinaryTree<T>::insert(const T &data, BinaryTreeNode<T> *node) {
        BinaryTreeNode<T> *newNode = new BinaryTreeNode<T>(data);
        if(!node) {
            node = newNode;
        } else if(node->_data < data) {
            insert(data,node->_leftChild);
        } else if(node->_data > data) {
            insert(data,node->_rightChild);
        } else {}
    }
}
#endif