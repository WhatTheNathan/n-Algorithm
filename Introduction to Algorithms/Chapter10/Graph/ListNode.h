//
// Created by Nathan on 27/02/2018.
//

#ifndef LINKEDLIST_LISTNODE_H
#define LINKEDLIST_LISTNODE_H

namespace Nathan {

    template<class T> class DoubleLinkedList;

    template <class T>
    class ListNode {
        friend class DoubleLinkedList<T>;
    public:
        ListNode(const T &data);
        T value();
        ListNode<T>* next();
    private:
        T _data;
        ListNode *_pre;
        ListNode *_link;
    };

    template <class T>
    ListNode<T>::ListNode(const T &data) {
        _data = data;
        _pre = nullptr;
        _link = nullptr;
    }

    template <class T>
    T ListNode<T>::value() {
        return _data;
    }

    template <class T>
    ListNode<T>* ListNode<T>::next() {
        return _link;
    }
}

#endif //LINKEDLIST_LISTNODE_H
