//
// Created by Nathan on 05/03/2018.
//
#include <iostream>
#include <set>
#include <tuple>

using namespace::std;

set<tuple<int,int,int>> initialGraph() {
    set<tuple<int,int,int>> set;
    set.insert(make_tuple(0,5,10));
    set.insert(make_tuple(0,1,22));
    set.insert(make_tuple(1,2,6));
    set.insert(make_tuple(1,6,2));
    set.insert(make_tuple(3,2,23));
    set.insert(make_tuple(3,4,12));
    set.insert(make_tuple(4,6,11));
    set.insert(make_tuple(4,5,3));
    set.insert(make_tuple(6,5,7));
    set.insert(make_tuple(6,2,9));
    return set;
};

bool isInSet(set<int> TV, int vertice) {
    for(auto v: TV){
        if(v == vertice)
            return true;
    }
    return false;
}

tuple<int,int,int> minWeightEdge(set<tuple<int,int,int>> &E, set<int> TV) {
    int minWeight = INT_MAX;
    int head,tail;
    int tempHead,tempTail,weight;
    for(auto vertice: TV) {
        for(auto edge: E) {
            tie(tempHead,tempTail,weight) = edge;
            if( ((vertice == tempHead && !isInSet(TV, tempTail)) || (vertice == tempTail && !isInSet(TV,tempHead)) ) &&  weight < minWeight) {
                minWeight = weight;
                head = tempHead;
                tail = tempTail;
            }
        }
    }
    tuple<int,int,int> minWE = make_tuple(head,tail,minWeight);
    set<tuple<int,int,int>>::iterator it = E.find(minWE);
    E.erase(it);
    return minWE;
};

set<tuple<int,int,int>> Prim(set<tuple<int,int,int>> E, int n, int origin) {
    set<tuple<int,int,int>> T;
    set<int> TV;
    TV.insert(origin);

    while(T.size() < n - 1 && !E.empty() ) {
        tuple<int,int,int> minWE = minWeightEdge(E, TV);
//        if(!isCyclic(T,minWE)) {
        int head,tail,weight;
        tie(head,tail,weight) = minWE;
        TV.insert(head);
        TV.insert(tail);
        T.insert(minWE);
//        }
    }
    if(T.size() < n - 1)
        cout<<"no exists"<<endl;
    return T;
};

int main() {
    int n = 7;
    set<tuple<int,int,int>> E = initialGraph();
    set<tuple<int,int,int>> MinSpanningTree = Prim(E,n,0);
    int head,tail,weight;
    for(auto edge: MinSpanningTree) {
        tie(head,tail,weight) = edge;
        cout<<"("<<head<<","<<tail<<","<<weight<<")"<<endl;
    }
}


