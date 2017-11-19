#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include "Graph.h"

using namespace std;

int main() {
	int dim, start, end;

	ifstream infile;
	infile.open("input.txt");
	string tmp;

	infile >> dim;
	infile >> start;
	infile >> end;

	// Generate graph
	Graph g(dim);
	for (int i = 0; i < dim / 2; i++) {
		printf("1\n");
		getline(infile, tmp);

		int tok;
		stringstream ss(tmp);
		printf("2\n");
		for (int j = 0; j < dim; j++) {
			printf("2.1\n");
			ss >> tok;

			if (tok == 1) {
				g.connect(i, j);
			}

			/*
			if (strcmp(tok, "1") == 0) {
				g.connect(i, j);
			}
			*/

			//tok = strtok(NULL, ",");
		}
	}
	printf("3\n");

	// Traverse graph
	vector<Node*> to_check;
	printf("3.1\n");

	if (!g[start]) printf("Shit sticks\n");
	g[start]->prev = g[start]->id;
	printf("3.2\n");
	to_check.push_back(g[start]);
	printf("4\n");

	while (to_check.size() > 0) {
		printf("5\n");
		// Pop from front
		Node* curr = to_check.front();
		to_check.erase(to_check.begin());

		if (!curr || curr->visited) continue;

		curr->visited = true;

		if (curr->id == end) break;  // Found end

		for (int i = 0; i < curr->adj.size(); i++) {
			printf("6\n");
			if (!curr->adj[i]->visited) {
				curr->adj[i]->prev = curr->id;
				to_check.push_back(curr->adj[i]);
			}
		}
	}
	printf("7\n");

	if (!g[end]->visited) {  // End is unreachable
		printf("Room %d is unreachable from room %d\n", end, start);
		return 0;
	}

	vector<int> path;

	Node* curr = g[end];
	while (curr->id != start) {
		path.push_back(curr->id);
		curr = g[curr->prev];
	}

	printf("Path: %d ", start);
	for (int i = path.size() - 1; i >= 0; i--) {
		printf("%d ", path[i]);
	}
	printf("\n");

	return 0;
}
