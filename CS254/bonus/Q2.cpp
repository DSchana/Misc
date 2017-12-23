#include <cstdio>
#include <iostream>
#include <limits>
#include <vector>
#include <utility>
#include "Graph.h"

using namespace std;

int main() {
	/*
	 * 0 - Windsor
	 * 1 - Lasalle
	 * 2 - Amherstburg
	 * 3 - Essex
	 * 4 - Tecumseh
	 * 5 - Lakeshore
	 * 6 - Kingsville
	 * 7 - Leamington
	**/
	Graph g(8);

	g.connect(0, 1, 2);
	g.connect(1, 2, 2);
	g.connect(1, 3, 4);
	g.connect(2, 3, 2);
	g.connect(0, 4, 6);
	g.connect(4, 3, 5);
	g.connect(4, 5, 4);
	g.connect(3, 5, 7);
	g.connect(5, 6, 6);
	g.connect(5, 7, 8);
	g.connect(6, 7, 4);

	int q_path[8] = { 0, numeric_limits<int>::infinity(), numeric_limits<int>::infinity(), numeric_limits<int>::infinity(), numeric_limits<int>::infinity(), numeric_limits<int>::infinity(), numeric_limits<int>::infinity(), numeric_limits<int>::infinity() };
	vector<pair<Node*, pair<int, int> > > to_check;

	to_check.push_back(make_pair(g[0], make_pair(0, 0)));  // (Node, (weight, prev_weight))

	while (to_check.size() > 0) {
		Node* curr = to_check[0].first;
		pair<int, int> w = to_check[0].second;
		to_check.erase(to_check.begin());

		if (curr->visited) continue;
		curr->visited = true;

		q_path[curr->id] = w.first + w.second;

		for (int i = 0; i < curr->adj.size(); i++) {
			to_check.push_back(make_pair(curr->adj[i].first, make_pair(curr->adj[i].second, q_path[curr->id])));
		}
	}

	printf("Windsor to Kingsville: %d\n", q_path[6]);

	g.reset();

	int n_q_path[8] = { numeric_limits<int>::infinity(), numeric_limits<int>::infinity(), 0, numeric_limits<int>::infinity(), numeric_limits<int>::infinity(), numeric_limits<int>::infinity(), numeric_limits<int>::infinity(), numeric_limits<int>::infinity() };

	to_check.push_back(make_pair(g[2], make_pair(0, 0)));  // (Node, (weight, prev_weight))

	while (to_check.size() > 0) {
		Node* curr = to_check[0].first;
		pair<int, int> w = to_check[0].second;
		to_check.erase(to_check.begin());

		if (curr->visited) continue;
		curr->visited = true;

		n_q_path[curr->id] = w.first + w.second;

		for (int i = 0; i < curr->adj.size(); i++) {
			to_check.push_back(make_pair(curr->adj[i].first, make_pair(curr->adj[i].second, n_q_path[curr->id])));
		}
	}

	printf("Amherstburg to Leamington: %d\n", n_q_path[7]);

	return 0;
}
