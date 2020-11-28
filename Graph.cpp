//
// Created by Erik Peterson on 11/5/20.
//

#include "Graph.h"

void Graph::addVertex(Vertex *vertex) {
    vertices.push_back(vertex);
}

const std::vector<Vertex *>& Graph::getVertices() const {
    return vertices;
}

void Graph::clear() {
    vertices.clear();
}

