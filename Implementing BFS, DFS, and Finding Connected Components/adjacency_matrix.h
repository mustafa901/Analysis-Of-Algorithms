#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX

#include <iostream>
#include <fstream>
#include <string>

class AdjacencyMatrix{
	// class to represent the adjacency matrix of a graph
private:
	int V;					//number of nodes in the graph
	int** adjMatrix;		//adjacency matrix of a graph

public:
	AdjacencyMatrix(std::string filename, int numVertices, bool printProgress = false){
		// Constructor: takes a file name and the number of vertices in the graph, and constructs the adjacency matrix of the graph
		// Nodes are numbered 0, 1, 2, ..., numVertices-1
		// printProgress controls whether we print each edge as we add it to the graph
		V = numVertices;

		// set up adjacency matrix, as an array of arrays. 
		// Dimensions of the matrix are numVertices by numVertices.
		// adjMatrix[i][j] will be 0 or 1, depending on if there is an edge connecting node i and node j
		// all values in matrix are initialized to 0. Edges will be filled in later.
		adjMatrix = new int*[V];	
		for (int i = 0; i < V; i++){
			adjMatrix[i] = new int[V]();
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

		// read from the file, and update adjacency matrix for each edge in the file
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

			// TO DO: update the adjacency matrix to include this edge
			// YOUR CODE HERE


		}

		edgeFile.close();

	}

	~AdjacencyMatrix(){
		// This is the destructor. It deletes the dynamically allocated arrays, so that we don't have memory leaks.
		for (int i = 0; i < V; i++){
			delete[] adjMatrix[i];		//delete every row
		}
		delete[] adjMatrix;				//delete the array of rows
	}

	void printMatrix(){
		// Use this function to view your adjacency matrix, to check that it was set up correctly.
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++){				// print row
				std::cout << adjMatrix[i][j] << " ";
			}
			std::cout << std::endl;						// print line break between row
		}
	}

	int entry(int i, int j){
		// accesses and returns entry (i,j)
		// returns 1 if there is an edge connected node i and node j, returns 0 otherwise
		// returns -1 if i or j is out of range
		if (i < 0 || j < 0 || i >= V || j >= V){
			std::cout << "Invalid node in call to get entry (" << i << "," << j << ")\nNumber of nodes is " << V << std::endl;
			return -1;
		}
		return adjMatrix[i][j];
	}
};

#endif