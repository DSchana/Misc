#include <algorithm>
#include "_Graph.h"

using namespace std;

Graph::Graph(int s) {
	for (int i = 0; i < s; i++) {
		Node* n;
		nodes.push_back(n);
		nodes[i]->id = i;
	}
}

/*
 * Description:	Connect two nodes by adding them into
 *		each other's adjacency list
 * Parameters:	Integer n1: ID of node 1
 *		Integer n2: ID of node 2
 * Returns:	void
**/
void Graph::connect(int n1, int n2) {
	printf("Connecting\n");
	printf("ID: %d ", nodes[n2]->id);
	nodes[n1]->adj.push_back(nodes[n2]);
	nodes[n2]->adj.push_back(nodes[n2]);
	printf("ID: %d\n", nodes[n1]->id);
}

/*
 * Description:	Get a list of all nodes adjacent to
 *		and indicated node
 * Parameters:	Integer n: ID of node to get adjacency of
 * Returns:	List of Nodes: List of all nodes adjacent
 *		to Node with ID n
**/
vector<Node*> Graph::getAdjacency(int n) {
	return nodes[n]->adj;
}

/*
 * Description:	Get pointer to node pf specified ID
 * Parameters:	Integer id: ID of node to return
 * Returns:	Pointer to node with ID id
**/
Node* Graph::getNode(int id) {
	return nodes[id];

	for (int i = 0; i < nodes.size(); i++) {
		//printf("ID: %d\n", nodes[i]->id);
		if (nodes[i]->id == id) {
			return nodes[i];
		}
	}

	return nullptr;
}

Node* Graph::operator[](int id) {
	return getNode(id);
}

/*
 * Description:	Get number of nodes in graph
 * Parameters:	void
 * Returns: Integer: Number of nodes in graph
**/
int Graph::size() {
	return nodes.size();
}
