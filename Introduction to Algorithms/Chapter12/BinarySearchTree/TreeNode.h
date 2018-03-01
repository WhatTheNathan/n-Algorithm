//
// Created by Nathan on 27/02/2018.
//

#ifndef _TREENODE_H
#define _TREENODE_H

namespace Nathan {

    template<class T> class BinarySearchTree;

    template <class T>
    class TreeNode {
        friend class BinarySearchTree<T>;
    public:
        TreeNode(const T &data);
        T value() const;
    private:
        T _data;
        TreeNode<T> *_leftChild;
        TreeNode<T> *_rightChild;
        TreeNode<T> *_parent;
    };

    template <class T>
    TreeNode<T>::TreeNode(const T &data) {
        _data = data;
        _leftChild = nullptr;
        _rightChild = nullptr;
        _parent = nullptr;
    }

    template <class T>
    T TreeNode<T>::value() const {
        return _data;
    }

}

#endif //_TREENODE_H
