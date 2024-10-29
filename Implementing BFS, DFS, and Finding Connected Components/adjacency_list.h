#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST

#include <iostream>
#include <list>
#include <fstream>
#include <string>

class AdjacencyList{
	// class to represent the adjacency list of a graph
private:
	int V;						//number of nodes in the graph
	std::list<int>** adjList;	//adjacency list of a graph

public:
	AdjacencyList(std::string filename, int numVertices, bool printProgress = false){
		// Constructor: takes a file name and the number of vertices in the graph, and constructs the adjacency list of the graph
		// Nodes are numbered 0, 1, 2, ..., numVertices-1
		// printProgress controls whether we print each edge as we add it to the graph
		V = numVertices;

		// set up adjacency list, as an array of pointers to double linked lists of ints. 
		// if there is an edge connecting node i and node j, then j appears in the list *adjList[i]
		// all lists are initialized to be empty. Edges will be filled in later.
		adjList = new std::list<int>*[V];
		for (int i = 0; i < V; i++){
			adjList[i] =  new std::list<int>;
		}

		// open the file with name provided. 
		//	The file is a csv file, listing the edges of the graph. For example, the file could contain:
		//	0, 2
		//	1, 2
		//	3, 1
		//	This means that there is an edge between node 0 and node 2, an edge between node 1 and node 2,
		//	and an edge between node 3 and node 1. You can assume that each edge is only listed once.
		std::ifstream edgeFile;
		edgeFile.open(filename);

		// these variables will be used to store the two nodes of each edge as we process the file
		std::string v1_string, v2_string;
		int v1, v2;

		// read from the file, and update adjacency list for each edge in the file
		while (!edgeFile.eof()){
			std::getline(edgeFile, v1_string, ',');		// read until the comma, store in v1_string (this is the first node)
			std::getline(edgeFile, v2_string, '\n');	// read until the newline, store in v2_string (this is the second node)

			// convert node strings to ints
			v1 = std::stoi(v1_string);
			v2 = std::stoi(v2_string);

			// make sure node names are valid
			if (v1 < 0 || v1 >= V || v2 < 0 || v2 >= V){
				std::cout << "Invalid node in edge (" << v1 << "," << v2 << ")\nNumber of nodes is " << V << std::endl;
				edgeFile.close();
				return;
			}

			// there is an edge from v1 to v2, we'll add it to the adjacency matrix
			if (printProgress){
				std::cout << "Adding edge from " << v1 << " to " << v2 << std::endl;
			}

			// TO DO: update the adjacency list to include this edge. Use the list member function push_back, and remember that adjList[x] is a pointer to a list.
			// YOUR CODE HERE
			

		}

		edgeFile.close();
	}

	~AdjacencyList(){
		// This is the destructor. It deletes the dynamically allocated lists and array, so that we don't have memory leaks.
		for (int i = 0; i < V; i++){
			delete adjList[i];		//delete every list
		}
		delete[] adjList;				//delete the array of pointers to lists
	}

	void printList(){
		// Use this function to view your adjacency list, to check that it was set up correctly.
		for (int i = 0; i < V; i++) {
			std::cout << i << ": ";				// print node
			for (auto j : *adjList[i]){			
				std::cout << j << " ";			//print neighbors of node
			}
			std::cout << std::endl;				
		}
	}

	std::list<int>* neighbors(int i){
		// returns a pointer to the list of neighbors of node i
		return adjList[i];
	}
};

#endif