//
// Created by Nathan on 22/03/2018.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include "DoubleLinkedList.h"
#include <queue>
using std::queue;

namespace Nathan {
    template <class T>
    class Graph {
    public:
        Graph(const int vertices);
        void insertVertice(DoubleLinkedList<T> list);
        void DFS();
        void DFS(const int v);
        void BFS(const int v);

    private:
        DoubleLinkedList<T>* headNodes;
        int _vertices;
        int _size;
        int *visited;
    };

    template <class T>
    Graph<T>::Graph(const int vertices)
        : _vertices(vertices)
    {
        headNodes = new DoubleLinkedList<T>[_vertices];
        _size = -1;
    }

    template <class T>
    void Graph<T>::insertVertice(DoubleLinkedList<T> list) {
        if(_size < _vertices) {
            headNodes[++_size] = list;
        }
    }

    template <class T>
    void Graph<T>::DFS() {
        if(_size) {
            visited = new int[_size];
            for(int i = 0; i < _size; i++)
                visited[i] = false;
            DFS(0);
        }
    }

    template <class T>
    void Graph<T>::DFS(const int v) {
        visited[v] = true;
        ListNode<T>* currentNode = headNodes[v].headNode();
        std::cout<<currentNode->value()<<std::endl;
        while(currentNode->next()) {
            currentNode = currentNode->next();
            if(!visited[currentNode->value()]){
                DFS(currentNode->value());
            }
        }
    }

    template <class T>
    void Graph<T>::BFS(const int v) {
        visited = new int[_size];
        for(int i = 0; i < _size; i++)
            visited[i] = false;

        std::queue<T> queue;
        visited[v] = true;
        queue.push(v);
        while(!queue.empty()) {
            ListNode<T>* currentNode = headNodes[queue.front()].headNode();
            std::cout<<currentNode->value()<<std::endl;
            queue.pop();
            while(currentNode->next()) {
                currentNode = currentNode->next();
                if(!visited[currentNode->value()]) {
                    queue.push(currentNode->value());
                    visited[currentNode->value()] = true;
                }
            }
        }
    }
}
#endif //GRAPH_GRAPH_H
