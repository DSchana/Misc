#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

struct Node {
	int id;
	std::vector<Node*> adj;
	bool visited = false;
	int prev = -1;  // Previous node closest to start
};

class Graph {
private:
	std::vector<Node*> nodes;

public:
	Graph(int s);  // Create graph with size s
	void connect(int n1, int n2);  // Connects node 1 with node 2
	std::vector<Node*> getAdjacency(int n);
	Node* getNode(int id);
	Node* operator[](int id);
	int size();
};

#endif
