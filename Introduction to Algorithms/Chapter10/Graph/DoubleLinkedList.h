#include <iostream>
#include "ListNode.h"

#ifndef _Nathan_DOUBLELINKEDLIST_H
#define _Nathan_DOUBLELINKEDLIST_H

namespace Nathan {
    template <class T>
    class DoubleLinkedList {
    public:
        DoubleLinkedList(ListNode<T> *first = nullptr);

        bool isEmpty() const;
        int getSize() const;

        T head();
        T tail();
        ListNode<T>* headNode();
        ListNode<T>* tailNode();

        void insertHead(const T & value);
        void insertTail(const T & value);
        void insertTail(ListNode<T> *newNode);

        bool removeHead();
        bool removeTail();

        void print();
    private:
        ListNode<T> *_head;
        ListNode<T> *_tail;
        int _size = 0;
    };

    template <class T>
    DoubleLinkedList<T>::DoubleLinkedList(ListNode<T> *first) {
        _head = first;
        _tail = first;
        if (_head != nullptr) {
            _size = 1;
        }
    }

    template <class T>
    bool DoubleLinkedList<T>::isEmpty() const {
        return _size == 0;
    }

    template <class T>
    int DoubleLinkedList<T>::getSize() const {
        return _size;
    }

    template <class T>
    T DoubleLinkedList<T>::head() {
        return _head->value();
    }

    template <class T>
    ListNode<T>* DoubleLinkedList<T>::headNode() {
        return _head;
    }

    template <class T>
    ListNode<T>* DoubleLinkedList<T>::tailNode() {
        return _tail;
    }

    template <class T>
    T DoubleLinkedList<T>::tail() {
        return _tail->value();
    }

    template <class T>
    void DoubleLinkedList<T>::insertHead(const T &value) {
        ListNode<T> *newNode = new ListNode<T>(value);
        if (!_head) {
            _head = newNode;
        } else {
            ListNode<T> *temp = _head;
            _head = newNode;
            _head->_link = temp;
            temp->_pre = _head;
        }
    }

    template <class T>
    void DoubleLinkedList<T>::insertTail(const T &value) {
        ListNode<T> *newNode = new ListNode<T>(value);
        if (!_head) {
            _head = newNode;
        } else {
            ListNode<T> *temp = _tail;
            _tail = newNode;
            temp->_link = _tail;
            _tail->_pre = temp;
        }
        _size++;
    }

    template <class T>
    void DoubleLinkedList<T>::insertTail(ListNode<T> *newNode) {
        if (!_head) {
            _head = newNode;
        } else {
            ListNode<T> *temp = _tail;
            _tail = newNode;
            temp->_link = _tail;
            _tail->_pre = temp;
        }
        _size++;
    }

    template <class T>
    bool DoubleLinkedList<T>::removeHead() {
        if (!_head)
            return false;
        ListNode<T> *temp = _head;
        _head = _head->_link;
        _head->_pre = nullptr;
        delete temp;
        return true;
    }

    template <class T>
    bool DoubleLinkedList<T>::removeTail() {
        if (!_tail)
            return false;
        ListNode<T> *temp = _tail;
        _tail = _tail->_pre;
        _tail->_link = nullptr;
        delete temp;
        return true;
    }

    template <class T>
    void DoubleLinkedList<T>::print() {
        ListNode<T> *temp = _head;
        while(temp->_link != nullptr) {
            std::cout << temp->_data<<" ";
            temp = temp->_link;
        }
        std::cout<<temp->_data<<std::endl;
    }
}
#endif