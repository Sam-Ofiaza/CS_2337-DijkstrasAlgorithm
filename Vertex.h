//
// Created by Erik Peterson on 11/5/20.
//

#ifndef DIJKSTRA_ALGORITHM_VERTEX_H
#define DIJKSTRA_ALGORITHM_VERTEX_H

#include <string>
#include <unordered_map>
#include <vector>

class Vertex {
public:
    Vertex(const std::string& name);

    void addAdjacentVertex(Vertex* adjacentVertex, int distance);

    const std::string& getName() const;
    void getAdjacentVertices(std::vector<Vertex*>& adjacentVerticesList) const;
    int getEdgeWeight(Vertex* adjacentVertex);

private:
    std::string name;
    std::unordered_map<Vertex*, int> adjacentVertices;
};


#endif //DIJKSTRA_ALGORITHM_VERTEX_H
