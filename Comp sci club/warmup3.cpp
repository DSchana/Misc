// warmup3.cpp

#include <iostream>

using namespace std;

double getEquation(x1, y1, x2, y2) {
	double a, b, c;
	double slope = (y2-y1)/(x2-x1);
}

int main(int argc, char const *argv[]) {
	long int xh, yh, xs, ys, n;

	cin >> xh >> yh >> xs >> ys >> n;

	int roads[n][3];
	double path[3];

	for (int i=0; i<n; i++) {
		for (int j=0; j<3; j++) {
			cin >> roads[i][j];
		}
	}

	return 0;
}