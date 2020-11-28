#include "DijkstraAlgorithm.h"
#include "Graph.h"

#include <cassert>
#include <iostream>
#include <limits.h>

using namespace std;

void simpleGraph() {
    Graph* graph = new Graph();

    auto* aVertex = new Vertex("A");
    auto* bVertex = new Vertex("B");
    auto* cVertex = new Vertex("C");

    aVertex->addAdjacentVertex(bVertex, 3);
    aVertex->addAdjacentVertex(cVertex, 10);
    bVertex->addAdjacentVertex(cVertex, 5);

    graph->addVertex(aVertex);
    graph->addVertex(bVertex);
    graph->addVertex(cVertex);

    DijkstraAlgorithm algorithm(graph);
    algorithm.runAlgorithm(aVertex);

    assert(algorithm.getShortestDistance(aVertex) == 0);
    assert(algorithm.getShortestDistance(bVertex) == 3);
    assert(algorithm.getShortestDistance(cVertex) == 8);

    assert(algorithm.getPathTo(aVertex) == "A");
    assert(algorithm.getPathTo(bVertex) == "A-B");
    assert(algorithm.getPathTo(cVertex) == "A-B-C");

    graph->clear();
    delete graph;

    delete aVertex;
    delete bVertex;
    delete cVertex;

    cout << "Simple graph test complete" << endl;
}

void fiveElementGraph() {
    Graph* graph = new Graph();

    auto* aVertex = new Vertex("A");
    auto* bVertex = new Vertex("B");
    auto* cVertex = new Vertex("C");
    auto* dVertex = new Vertex("D");
    auto* eVertex = new Vertex("E");

    graph->addVertex(aVertex);
    graph->addVertex(bVertex);
    graph->addVertex(cVertex);
    graph->addVertex(dVertex);
    graph->addVertex(eVertex);

    aVertex->addAdjacentVertex(bVertex, 5);
    aVertex->addAdjacentVertex(cVertex, 7);
    aVertex->addAdjacentVertex(eVertex, 18);
    bVertex->addAdjacentVertex(cVertex, 7);
    cVertex->addAdjacentVertex(eVertex, 4);
    dVertex->addAdjacentVertex(aVertex, 11);
    dVertex->addAdjacentVertex(eVertex, 4);

    DijkstraAlgorithm algorithm(graph);
    algorithm.runAlgorithm(aVertex);

    assert(algorithm.getShortestDistance(aVertex) == 0);
    assert(algorithm.getShortestDistance(bVertex) == 5);
    assert(algorithm.getShortestDistance(cVertex) == 7);
    assert(algorithm.getShortestDistance(dVertex) == INT_MAX);
    assert(algorithm.getShortestDistance(eVertex) == 11);

    assert(algorithm.getPathTo(aVertex) == "A");
    assert(algorithm.getPathTo(bVertex) == "A-B");
    assert(algorithm.getPathTo(cVertex) == "A-C");
    assert(algorithm.getPathTo(dVertex) == "");
    assert(algorithm.getPathTo(eVertex) == "A-C-E");

    graph->clear();
    delete graph;
    delete aVertex;
    delete bVertex;
    delete cVertex;
    delete dVertex;
    delete eVertex;

    cout << "Five element graph test complete" << endl;
}

void cantGoAnywhere() {
    Graph* graph = new Graph();

    auto* aVertex = new Vertex("A");
    auto* bVertex = new Vertex("B");
    auto* cVertex = new Vertex("C");
    auto* dVertex = new Vertex("D");
    auto* eVertex = new Vertex("E");

    graph->addVertex(aVertex);
    graph->addVertex(bVertex);
    graph->addVertex(cVertex);
    graph->addVertex(dVertex);
    graph->addVertex(eVertex);

    bVertex->addAdjacentVertex(aVertex, 5);
    cVertex->addAdjacentVertex(aVertex, 7);
    bVertex->addAdjacentVertex(cVertex, 7);
    cVertex->addAdjacentVertex(eVertex, 4);
    dVertex->addAdjacentVertex(aVertex, 11);
    dVertex->addAdjacentVertex(eVertex, 4);

    DijkstraAlgorithm algorithm(graph);
    algorithm.runAlgorithm(aVertex);

    assert(algorithm.getShortestDistance(aVertex) == 0);
    assert(algorithm.getShortestDistance(bVertex) == INT_MAX);
    assert(algorithm.getShortestDistance(cVertex) == INT_MAX);
    assert(algorithm.getShortestDistance(dVertex) == INT_MAX);
    assert(algorithm.getShortestDistance(eVertex) == INT_MAX);

    assert(algorithm.getPathTo(aVertex) == "A");
    assert(algorithm.getPathTo(bVertex) == "");
    assert(algorithm.getPathTo(cVertex) == "");
    assert(algorithm.getPathTo(dVertex) == "");
    assert(algorithm.getPathTo(eVertex) == "");

    graph->clear();
    delete graph;
    delete aVertex;
    delete bVertex;
    delete cVertex;
    delete dVertex;
    delete eVertex;

    cout << "Can't go anywhere graph test complete" << endl;
}

void canGoEverywhere() {
    Graph* graph = new Graph();

    auto* aVertex = new Vertex("A");
    auto* bVertex = new Vertex("B");
    auto* cVertex = new Vertex("C");
    auto* dVertex = new Vertex("D");
    auto* eVertex = new Vertex("E");

    graph->addVertex(aVertex);
    graph->addVertex(bVertex);
    graph->addVertex(cVertex);
    graph->addVertex(dVertex);
    graph->addVertex(eVertex);

    aVertex->addAdjacentVertex(bVertex, 5);
    aVertex->addAdjacentVertex(cVertex, 59);
    aVertex->addAdjacentVertex(dVertex, 36);
    aVertex->addAdjacentVertex(eVertex, 88);
    bVertex->addAdjacentVertex(cVertex, 3);
    cVertex->addAdjacentVertex(dVertex, 7);
    dVertex->addAdjacentVertex(eVertex, 9);

    DijkstraAlgorithm algorithm(graph);
    algorithm.runAlgorithm(aVertex);

    assert(algorithm.getShortestDistance(aVertex) == 0);
    assert(algorithm.getShortestDistance(bVertex) == 5);
    assert(algorithm.getShortestDistance(cVertex) == 8);
    assert(algorithm.getShortestDistance(dVertex) == 15);
    assert(algorithm.getShortestDistance(eVertex) == 24);

    assert(algorithm.getPathTo(aVertex) == "A");
    assert(algorithm.getPathTo(bVertex) == "A-B");
    assert(algorithm.getPathTo(cVertex) == "A-B-C");
    assert(algorithm.getPathTo(dVertex) == "A-B-C-D");
    assert(algorithm.getPathTo(eVertex) == "A-B-C-D-E");

    graph->clear();
    delete graph;
    delete aVertex;
    delete bVertex;
    delete cVertex;
    delete dVertex;
    delete eVertex;

    cout << "Can go everywhere graph test complete" << endl;
}

int main(int argc, char** argv) {
    int testToRun = INT_MAX;
    if ( argc > 1) {
        testToRun = atoi(argv[1]);
    }
    switch( testToRun) {
        case 0:
            simpleGraph();
            break;
        case 1:
            fiveElementGraph();
            break;
        case 2:
            cantGoAnywhere();
            break;
        case 3:
            canGoEverywhere();
            break;
        default:
            // Run 'em all
            simpleGraph();
            fiveElementGraph();
            cantGoAnywhere();
            canGoEverywhere();
    }
}
