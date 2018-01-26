#include "Graph.h"
#include <iostream>

using namespace std;

int main() {
	Graph g(5);

	g.t;

	g.connect(0, 4);
	g.connect(1, 2);
	g.connect(1, 3, 2);
	g.connect(2, 3, 1);
	g.connect(3, 4, 5);
	g.connect(3, 2);

	cout << g << endl;

	return 0;
}
