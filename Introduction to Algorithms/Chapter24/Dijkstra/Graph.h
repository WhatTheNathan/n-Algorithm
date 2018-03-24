//
// Created by Nathan on 24/03/2018.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
#include <cstring>
using std::memset;


const int LARGEINT = 100;

class Graph {
public:
    Graph(int number);
    void shrotestPath(int vertice);
    void initial();
    int choose();
private:
    int ** length;  // 图中边之间的距离，若没有该边，则距离设置为LARGEINT
    int* dist;      // 从v出发，只经过S中的顶点，到达[index]的最短距离
    int* path;      // 最短距离
    bool* S;        // S集合，用bool数组表示
    int _number;
};

Graph::Graph(int number) {
    _number = number;
    length = new int*(_number);
    memset(length,0, sizeof(int*) * _number);

    dist = new int(_number);
    path = new int(_number);
    S = new bool(_number);
}

void Graph::initial() {
    for(int i = 0; i < _number; i++) {
        for(int j = 0; j < _number; j++) {
            length[i][j] = LARGEINT;
        }
    }
    length[0][5] = 10;
    length[0][1] = 22;
    length[5][6] = 7;
    length[6][1] = 2;
    length[1][2] = 6;
    length[6][4] = 11;
    length[4][5] = 3;
    length[3][2] = 23;
    length[3][4] = 12;
    length[6][2] = 9;
}

int Graph::choose() {
    int minDist = LARGEINT;
    int index = 0;
    for(int i = 0 ; i < _number; i++) {
        if(dist[i] < minDist && !S[i]){
            minDist = dist[i];
            index = i;
        }
    }
}

void Graph::shrotestPath(int vertice) {
    for(int i = 0; i < _number; i++) {
        S[vertice] = false;
        dist[i] = length[vertice][i];
        if(dist[i] < LARGEINT && i != vertice)
            path[i] = vertice;
        else
            path[i] = -1;
    }
    S[vertice] = true;
    dist[vertice] = 0;

    for(int i = 0; i < _number - 2; i++) {
        int u = choose();
        S[u] = true;
        for(int w = 0; w < _number; w++) {
            if(!S[w])
                if(dist[u] + length[u][w] < dist[w]) {
                    dist[w] = dist[u] + length[u][w];
                    path[w] = u;
                }
        }
    }
}


#endif //GRAPH_GRAPH_H
