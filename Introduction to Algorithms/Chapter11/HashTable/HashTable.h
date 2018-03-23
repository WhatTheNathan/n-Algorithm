//
// Created by Nathan on 23/03/2018.
//

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include "HashNode.h"
#include <cstring>
using std::memset;

namespace Nathan
{
    template<class K, class V>
    class HashTable
    {
    public:
        // constructor
        HashTable(unsigned int bucketNum, unsigned int(*hash)(const K &key, unsigned int range));

        // deconstructor
        ~HashTable();

        // put
        void put(int key, V value);

        // get
        V get(const int &key);

    private:
        unsigned int _bucketNum;		// the number of buckets
        HashNode<K,V> ** _heads;          // array of heads for each bucket

        unsigned int (*_hash)(const int & key,unsigned int range);	// hash strategy
    };

    template<class K, class V>
    HashTable<K,V>::HashTable(unsigned int bucketNum, unsigned int(*hash)(const K &key, unsigned int range)) {
        _hash = hash;
        _bucketNum = bucketNum;
        _heads = new HashNode<K,V>*[_bucketNum];
        memset(_heads,0,sizeof(HashNode<K,V> *) * _bucketNum);
    }

    template<class K, class V>
    void HashTable<K,V>::put(int key, V value) {
        int index = _hash(key,_bucketNum);

        HashNode<K,V>* p = _heads[index];
        while(p) {
            if(p->getKey() == key) {
                p->setValue(value);
                return;
            }
            p = p->getNext();
        }

        p = new HashNode<K,V>(key,value);
        p->setNext(_heads[index]);
        _heads[index] = p;
    }

    template<class K, class V>
    V HashTable<K,V>::get(const int &key) {
        int index = _hash(key,_bucketNum);

        HashNode<K,V>* p  = _heads[index];
        while(p) {
            if(p->getKey() == key) {
                return p->getValue();
            }
            p = p->getNext();
        }
        return 0;
    }
}


#endif //HASHTABLE_HASHTABLE_H