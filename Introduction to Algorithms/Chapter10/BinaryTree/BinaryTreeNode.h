//
// Created by Nathan on 27/02/2018.
//

#ifndef _BINARYTREENODE_H
#define _BINARYTREENODE_H

namespace Nathan {

    template<class T> class BinaryTree;

    template <class T>
    class BinaryTreeNode {
        friend class BinaryTree<T>;
    public:
        BinaryTreeNode(const T &data);
    private:
        T _data;
        BinaryTreeNode<T> *_leftChild;
        BinaryTreeNode<T> *_rightChild;
    };

    template <class T>
    BinaryTreeNode<T>::BinaryTreeNode(const T &data) {
        _data = data;
        _leftChild = nullptr;
        _rightChild = nullptr;
    }

}

#endif //_BINARYTREENODE_H
