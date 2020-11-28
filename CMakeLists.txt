cmake_minimum_required(VERSION 3.17)
project(dijkstra_algorithm_base)

set(CMAKE_CXX_STANDARD 14)

add_executable(dijkstra_algorithm main.cpp Graph.cpp Graph.h Vertex.cpp Vertex.h DijkstraAlgorithm.cpp DijkstraAlgorithm.h DijkstraAlgorithm.cpp DijkstraAlgorithm.h)