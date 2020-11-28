//
// Created by Erik Peterson on 11/5/20.
//

#ifndef DIJKSTRA_ALGORITHM_GRAPH_H
#define DIJKSTRA_ALGORITHM_GRAPH_H

#include <vector>
#include "Vertex.h"

class Graph {
public:
    Graph() = default;

    // Disable copy constructor and operator=
    // In the past we did this in the private: section, but apparently that has changed
    // (Clang wanted them here)...
    Graph(const Graph& other) = delete;
    const Graph& operator=(const Graph& other) = delete;

    void addVertex(Vertex* vertex);
    const std::vector<Vertex*>& getVertices() const;

    void clear();

private:
    std::vector<Vertex*> vertices;
};


#endif //DIJKSTRA_ALGORITHM_GRAPH_H
