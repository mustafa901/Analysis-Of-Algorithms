#include <iostream>
#include <string>

#include "adjacency_matrix.h"
#include "adjacency_list.h"
#include "bfs.h"
#include "dfs.h"
#include "connected_components.h"

using namespace std;

void test_adjacency_matrix(string filename, int numNodes){
	// Takes a file name and a number of nodes, and prints the adjacency matrix for the graph
	cout << "Processing " << filename << ":\n";
	AdjacencyMatrix mat(filename, numNodes, true);		// print edges as they're added
	cout << "Adjacency Matrix:\n";
	mat.printMatrix();
	cout << endl;
}

void test_adjacency_list(string filename, int numNodes){
	// Takes a file name and a number of nodes, and prints the adjacency list for the graph
	cout << "Processing " << filename << ":\n";
	AdjacencyList lst(filename, numNodes, true);		// print edges as they're added
	cout << "Adjacency List:\n";
	lst.printList();
	cout << endl;
}

void test_bfs(string filename, int numNodes, int start){
	// Takes a file name, number of nodes, and starting node, and performs breadth first search, printing nodes as they're visited
	AdjacencyList lst(filename, numNodes);
	cout << "BFS on " << filename << " starting at node " << start << ":\n";
	bfs(&lst, start, numNodes);
	cout << endl;			
}

void test_dfs(string filename, int numNodes, int start){
	// Takes a file name, number of nodes, and starting node, and performs depth first search, printing nodes as they're visited
	AdjacencyList lst(filename, numNodes);
	cout << "DFS on " << filename << " starting at node " << start << ":\n";
	dfs(&lst, start, numNodes);
	cout << endl;			
}

void test_cc(string filename, int numNodes){
	// Takes a file name and number of nodes, and finds the connected components in the graph, 
	//printing nodes in the same connected components on the same line, with line breaks in between the components
	AdjacencyList lst(filename, numNodes);
	cout << "Finding connected components for " << filename << ":\n";
	connected_components(&lst, numNodes);
	cout << endl;			
}

int main(){
	// call test functions to test your implementations as you work
	// feel free to edit, delete, or comment code here as you are testing

	cout << "**TESTING ADJACENCY MATRIX**\n\n";
	test_adjacency_matrix("test1.csv", 7);
	test_adjacency_matrix("test2.csv", 12);
	test_adjacency_matrix("test3.csv", 8);
	test_adjacency_matrix("test4.csv", 12);
	cout << "** FINISHED TESTING ADJACENCY MATRIX**\n\n";

	cout << "**TESTING ADJACENCY LIST**\n\n";
	test_adjacency_list("test1.csv", 7);
	test_adjacency_list("test2.csv", 12);
	test_adjacency_list("test3.csv", 8);
	test_adjacency_list("test4.csv", 12);
	cout << "** FINISHED TESTING ADJACENCY LIST**\n\n";

	cout << "**TESTING BFS**\n\n";
	test_bfs("test1.csv", 7, 0);
	test_bfs("test2.csv", 12, 0);			
	test_bfs("test3.csv", 8, 0);	
	test_bfs("test3.csv", 8, 1);
	test_bfs("test4.csv", 12, 0);
	test_bfs("test4.csv", 12, 1);
	test_bfs("test4.csv", 12, 2);
	cout << "** FINISHED TESTING BFS**\n\n";

	cout << "**TESTING DFS**\n\n";			
	test_dfs("test1.csv", 7, 0);
	test_dfs("test2.csv", 12, 0);
	test_dfs("test3.csv", 8, 0);
	test_dfs("test3.csv", 8, 1);
	test_dfs("test4.csv", 12, 0);
	test_dfs("test4.csv", 12, 1);
	test_dfs("test4.csv", 12, 2);
	cout << "** FINISHED TESTING DFS**\n\n";

	cout << "**TESTING CONNECTED COMPONENTS**\n\n";			
	test_cc("test1.csv", 7);
	test_cc("test2.csv", 12);
	test_cc("test3.csv", 8);
	test_cc("test4.csv", 12);
	cout << "** FINISHED TESTING CONNECTED COMPONENTS**\n\n";
}