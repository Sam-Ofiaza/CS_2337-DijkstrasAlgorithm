//
// Created by Sam on 11/27/2020.
//

#include "DijkstraAlgorithm.h"

using namespace std;

DijkstraAlgorithm::DijkstraAlgorithm(Graph *graph)
: graph(graph) {}

void DijkstraAlgorithm::runAlgorithm(Vertex *vertex) {
    source = vertex;

    //Fill vector
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

    //Fill distances map
    for (pair<Vertex *, int> p : vertexList) {
        distances.insert(p);
    }

    //Instantiate predecessors map
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
            //Loop through lowest distance vertex's adjacent vertices
            vector<Vertex *> adjVertexList;
            lowestDistancePair.first->getAdjacentVertices(adjVertexList);

            for (Vertex *adjVertex : adjVertexList) {
                //New references for values for readability
                int adjVertexDistance = distances.at(adjVertex); //Shortest path for adj vertex in map
                int possibleShorterDistance =
                        distances.at(lowestDistancePair.first) + lowestDistancePair.first->getEdgeWeight(adjVertex); //Shortest path distance for lowestDistancePair vertex in map + adj vertex edge weight

                //If current shortest distance for lowestDistanceVertex + adj vertex edge weight < current shortest adj vertex distance
                if (possibleShorterDistance < adjVertexDistance) {
                    //Update shortest distance to the new distance of adj vertex
                    distances.at(adjVertex) = possibleShorterDistance;
                    //Update predecessor
                    predecessors.at(adjVertex) = lowestDistancePair.first;
                    //Find adj vertex spot in vertexList and update distance
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
    while(currentVertex != source) {
        path = "-" + currentVertex->getName() + path;
        currentVertex = predecessors.at(currentVertex);
    }
    path = source->getName() + path;

    return path;
}
