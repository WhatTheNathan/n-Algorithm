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

tuple<int,int,int> minWeightEdge(set<tuple<int,int,int>> &E) {
    int minWeight = INT_MAX;
    int head,tail;
    int tempHead,tempTail,weight;
    for(auto edge: E) {
        tie(tempHead,tempTail,weight) = edge;
        if(weight < minWeight) {
            minWeight = weight;
            head = tempHead;
            tail = tempTail;
        }
    }
    tuple<int,int,int> minWE = make_tuple(head,tail,minWeight);
    set<tuple<int,int,int>>::iterator it = E.find(minWE);
    E.erase(it);
    return minWE;
};

bool isCyclic(set<tuple<int,int,int>> T, tuple<int,int,int> newEdge) {
    int newHead,newTail,weight;
    tie(newHead,newTail,weight) = newEdge;

    int head,tail;

    set<int> findSet;
    findSet.insert(newHead);

    int flag = false;
    for(auto findHead: findSet) {
        if(newTail == 2 && newHead == 6)
        for(auto edge: T) {
            tie(head,tail,weight) = edge;
            if(findHead == head) {
                findSet.insert(tail);
                if(tail == newTail)
                    flag = true;
            }
            else if(findHead == tail) {
                if(newTail == 2 && newHead == 6) {
                    cout << "times" << endl;
                    cout<<head<<endl;
                }
                findSet.insert(head);
                if(head == newTail)
                    flag = true;
            }
        }
    }
    return flag;
}

set<tuple<int,int,int>> Kruskal(set<tuple<int,int,int>> E, int n) {
    set<tuple<int,int,int>> T;
    while(T.size() < n - 1 && !E.empty() ) {
        tuple<int,int,int> minWE = minWeightEdge(E);
        if(!isCyclic(T,minWE)) {
            T.insert(minWE);
        }
    }
    if(T.size() < n - 1)
        cout<<"no exists"<<endl;
    return T;
};

int main() {
    int n = 7;
    set<tuple<int,int,int>> E = initialGraph();
    set<tuple<int,int,int>> MinSpanningTree = Kruskal(E,n);
    int head,tail,weight;
    for(auto edge: MinSpanningTree) {
        tie(head,tail,weight) = edge;
        cout<<"("<<head<<","<<tail<<","<<weight<<")"<<endl;
    }
}


