#include <algorithm>
#include <sstream>
#include "_Graph.h"

using namespace std;

Graph::Graph(int s) {
	for (int i = 0; i < s; i++) {
		Node* n = new Node;
		n->id = i;
		nodes.push_back(n);
	}
}

/*
 * Description:	Deallocate nodes
 * Parameters:	void
 * Returns:	Null
**/
Graph::~Graph() {
	for (int i = 0; i < nodes.size(); i++) {
		delete nodes[i];
	}
}

/*
 * Description:	Connect two nodes by adding them into
 *		each other's adjacency list
 * Parameters:	Integer n1: ID of node 1
 *		Integer n2: ID of node 2
 *		Integer 2: Weight of traversing between
 *		Node n1 and Node n2
 * Returns:	void
**/
void Graph::connect(int n1, int n2, int w = 1) {
	nodes[n1]->adj.push_back(make_pair(nodes[n2], w));
	nodes[n2]->adj.push_back(make_pair(nodes[n1], w));
}

/*
 * Description:	Get a list of all nodes adjacent to
 *		and indicated node
 * Parameters:	Integer n: ID of node to get adjacency of
 * Returns:	List of Nodes: List of all nodes adjacent
 *		to Node with ID n
**/
vector<pair<Node*, int> > Graph::getAdjacency(int n) {
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

/*
 * Description: Element access operator
 * Parameters:	Integer id: Node id
 * Returns:	Pointer to Node with ID id
 * Usage:	graph[2]; --> node with id = 2
**/
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

void Graph::reset() {
	for (int i = 0; i < nodes.size(); i++) {
		nodes[i]->visited = false;
	}
}

/*
 * Description:	Get printable version of the graph
 * Parameters:	void
 * Returns:	String of graph
**/
const char* Graph::toString() {
	stringstream ss;

	for (int i = 0; i < nodes.size(); i++) {
		ss << "Node " << nodes[i]->id << ": ";

		for (int j = 0; j < nodes[i]->adj.size(); j++) {
			ss << "(" << nodes[i]->adj[j].first->id << ", " << nodes[i]->adj[j].second << ") ";
		}

		if (i < nodes.size() - 1)
			ss << endl;
	}

	char* ret = new char[ss.str().size()];
	strcpy(ret, ss.str().c_str());

	return ret;
}

/*
 * Description:	Out stream operator
 * Parameters:	ostream os: Out stream
 *		Graph g: graph to output
 * Returns:	Loaded stream
 * Usage:	os << g
**/
ostream& operator<<(ostream& os, Graph& g) {
	os << g.toString();

	return os;
}
