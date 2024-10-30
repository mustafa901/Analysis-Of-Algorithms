#ifndef CONNECTED_COMPONENTS
#define CONNECTED_COMPONENTS

#include <iostream>

#include "adjacency_list.h"
#include "bfs.h"

void connected_components(AdjacencyList* graph, int numNodes){
	// takes a pointer to the adjacency list of a graph and the total number of nodes
	// discovers the connected components, printing the nodes in each component, with line breaks in between the components.
    bool* visited = new bool[numNodes];
    for (int i = 0; i < numNodes; i++) {
        visited[i] = false;
    }

    for (int start = 0; start < numNodes; start++) {
        if (!visited[start]) {
            std::queue<int> to_visit;
            to_visit.push(start);
            visited[start] = true;

            while (!to_visit.empty()) {
                int current = to_visit.front();
                to_visit.pop();
                std::cout << current << " ";

                for (auto neighbor : *(graph->neighbors(current))) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        to_visit.push(neighbor);
                    }
                }
            }
            std::cout << std::endl; 
        }
    }
    delete[] visited;

}

#endif