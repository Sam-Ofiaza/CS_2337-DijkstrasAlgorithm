//
// Created by Sam on 11/27/2020.
//

#ifndef DIJKSTRA_ALGORITHM_BASE_DIJKSTRAALGORITHM_H
#define DIJKSTRA_ALGORITHM_BASE_DIJKSTRAALGORITHM_H

#include "Graph.h"
#include <iostream>

using namespace std;

class DijkstraAlgorithm {
public:
    DijkstraAlgorithm(Graph *graph);

    void runAlgorithm(Vertex *vertex);

    int getShortestDistance(Vertex *vertex);

    string getPathTo(Vertex *vertex);

private:
    Graph *graph;
    Vertex *source;
    unordered_map<Vertex *, int> distances;
    unordered_map<Vertex *, Vertex *> predecessors;
    vector<pair<Vertex *, int>> vertexList;
};


#endif //DIJKSTRA_ALGORITHM_BASE_DIJKSTRAALGORITHM_H
