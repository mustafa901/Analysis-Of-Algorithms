#ifndef BFS
#define BFS

#include <iostream>
#include <queue>

#include "adjacency_list.h"

void bfs(AdjacencyList* graph, int start, int numNodes){
	// takes a pointer to the adjacency list of a graph, a starting node, and the total number of nodes
	// performs a breadth first traversal, printing each node as it is visited

	// track which nodes have been visited using an array of booleans
	bool* visited = new bool[numNodes];
	for (int i = 0; i < numNodes; i ++){
		visited[i] = false;
	}

	// to_visit tracks nodes that need to be explored, stored in a queue
	std::queue<int> to_visit;
	visited[start] = true;
	to_visit.push(start);

	// WHAT SHOULD YOU DO HERE?
	while (!to_visit.empty()){
		int current = to_visit.front();
		to_visit.pop();

		std::cout << current << " ";
	

		if (!visited[current]){
			// WHAT SHOULD YOU DO HERE?

			for (auto neighbor : *(graph->neighbors(current))){		//for each neighbor of current (this is using an iterator through the neighbors of current, using the member function neighbors of AdjacencyList)
				// WHAT SHOULD YOU DO HERE?
				visited[neighbor] = true;
				to_visit.push(neighbor);			
			}
		}
	}
	std::cout << std::endl;
	delete[] visited;
}

#endif