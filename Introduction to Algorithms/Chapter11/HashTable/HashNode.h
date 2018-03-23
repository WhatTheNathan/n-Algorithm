//
// Created by Nathan on 23/03/2018.
//

#ifndef HASHTABLE_HASHNODE_H
#define HASHTABLE_HASHNODE_H

namespace Nathan {
    template <class K, class V>
    class HashNode {
    public:
        HashNode(const K & key,const V & value);
        HashNode<K,V> * getNext() const;
        V getValue();
        K getKey() const;

        void setValue(V value);
        void setNext(HashNode<K,V>* node);
    private:
        K _key;
        V _value;
        HashNode<K,V>* link;
    };

    template <class K, class V>
    HashNode<K,V>::HashNode(const K &key, const V &value) {
        _key = key;
        _value = value;
        link = nullptr;
    }

    template <class K, class V>
    HashNode<K,V>* HashNode<K,V>::getNext() const{
        return link;
    }

    template <class K, class V>
    K HashNode<K,V>::getKey() const {
        return _key;
    }

    template <class K, class V>
    V HashNode<K,V>::getValue() {
        return _value;
    }

    template <class K, class V>
    void HashNode<K,V>::setValue(V value) {
        _value = value;
    }

    template <class K, class V>
    void HashNode<K,V>::setNext(HashNode<K,V> *node) {
        link = node;
    }

}

#endif //HASHTABLE_HASHNODE_H
