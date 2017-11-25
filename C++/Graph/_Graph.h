#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <utility>

struct Node {
	int id;
	std::vector<std::pair<Node*, int> > adj;
	bool visited = false;
};

class Graph {
private:
	std::vector<Node*> nodes;

public:
	Graph(int s);
	~Graph();
	void connect(int n1, int n2, int w);  // Connects node 1 with node 2
	std::vector<std::pair<Node*, int> > getAdjacency(int n);
	Node* getNode(int id);
	Node* operator[](int id);
	int size();
	const char* toString();
};

std::ostream& operator<<(std::ostream& os, Graph& g);

#endif
