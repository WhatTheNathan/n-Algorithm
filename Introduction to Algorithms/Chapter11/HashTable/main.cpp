//
// Created by Nathan on 05/03/2018.
//
#include <iostream>
#include "HashTable.h"
#include "HashFunc.h"

using namespace::std;
using Nathan::HashTable;
using Nathan::HashNode;
using Nathan::HashFunc;

int main() {
    HashTable<int,int> *table = new HashTable<int,int>(10,HashFunc::hashInt);

    table->put(20,4);
    table->put(42,2);
    table->put(60,5);

    cout<<table->get(20)<<endl;
    cout<<table->get(45)<<endl;
    cout<<table->get(60)<<endl;
}


