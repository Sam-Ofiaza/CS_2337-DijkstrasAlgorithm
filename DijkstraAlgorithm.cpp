//
// Created by Sam on 11/27/2020.
//

#include "DijkstraAlgorithm.h"
#include <limits.h>

using namespace std;

DijkstraAlgorithm::DijkstraAlgorithm(Graph *graph)
: graph(graph) {}

void DijkstraAlgorithm::runAlgorithm(Vertex *vertex) {
    source = vertex;

    for (Vertex *v : graph->getVertices()) {
        if(v == vertex) {
            pair<Vertex *, int> newDistancesPair(v, 0);
            vertexList.push_back(newDistancesPair);
        }
        else {
            pair<Vertex *, int> newDistancesPair(v, INT_MAX);
            vertexList.push_back(newDistancesPair);
        }
    }

    for (pair<Vertex *, int> p : vertexList) {
        distances.insert(p);
    }

    for(pair<Vertex *, int> p : vertexList) {
        pair<Vertex *, Vertex *> newPredecessorsPair(p.first, nullptr);
        predecessors.insert(newPredecessorsPair);
    }

    while(!vertexList.empty()) {
        //Find lowest distance vertex, saving the pair and spot
        pair<Vertex *, int> lowestDistancePair(nullptr, INT_MAX);
        int spot = 0;

        for(int i = 0; i < vertexList.size(); i++) {
            if(vertexList.at(i).second < lowestDistancePair.second) {
                lowestDistancePair = vertexList.at(i);
                spot = i;
            }
        }

        vertexList.erase(vertexList.begin()+spot);

        //If no pair found, an adjacency list wont exist
        if(lowestDistancePair.first != nullptr) {
            vector<Vertex *> adjVertexList;
            lowestDistancePair.first->getAdjacentVertices(adjVertexList);

            //Loop through lowest distance vertex's adjacent vertices
            for (Vertex *adjVertex : adjVertexList) {
                //New references for values for readability
                int adjVertexDistance = distances.at(adjVertex);
                int possibleShorterDistance =
                        distances.at(lowestDistancePair.first) + lowestDistancePair.first->getEdgeWeight(adjVertex);

                //If current shortest distance for lowestDistanceVertex + adj vertex edge weight < current shortest adj vertex distance
                if (possibleShorterDistance < adjVertexDistance) {
                    distances.at(adjVertex) = possibleShorterDistance;
                    predecessors.at(adjVertex) = lowestDistancePair.first;

                    int spot2 = 0;
                    for (int i = 0; i < vertexList.size(); i++) {
                        if (vertexList.at(i).first == adjVertex) {
                            spot2 = i;
                        }
                    }
                    vertexList.at(spot2).second = possibleShorterDistance;
                }
            }
        }
    }

}

int DijkstraAlgorithm::getShortestDistance(Vertex *vertex) {
    return distances.at(vertex);
}

string DijkstraAlgorithm::getPathTo(Vertex *vertex) {
    if(distances.at(vertex) == INT_MAX) {
        return "";
    }

    string path;
    Vertex *currentVertex = vertex;
    //Goes through path backwards and adds to string backwards as well
    while(currentVertex != source) {
        path = "-" + currentVertex->getName() + path;
        currentVertex = predecessors.at(currentVertex);
    }
    path = source->getName() + path;

    return path;
}
