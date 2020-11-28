//
// Created by Erik Peterson on 11/5/20.
//

#include "Vertex.h"

using namespace std;

Vertex::Vertex(const string &name)
: name(name) {}

void Vertex::addAdjacentVertex(Vertex* adjacentVertex, int distance) {
    pair<Vertex*, int> newAdjacentPair(adjacentVertex, distance);
    adjacentVertices.insert(newAdjacentPair);
}

const std::string &Vertex::getName() const {
    return name;
}

void Vertex::getAdjacentVertices(vector<Vertex*>& adjacentVerticesList) const {
    for ( auto entry : adjacentVertices) {
        adjacentVerticesList.push_back(entry.first);
    }
}

int Vertex::getEdgeWeight(Vertex *adjacentVertex) {
    // This will throw an out_of_range exception if the value isn't found
    return adjacentVertices.at(adjacentVertex);
}
