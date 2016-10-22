#include <cstdio>
#include <vector>
#include <utility>
#include <string>

using namespace std;

void findPath(pair<int, int> p1, pair<int, int> p2, int **grid, int r, int c) {
	int toCheck = grid[get<0>(p1)][get<1>(p1)];
	vector< pair<int, int> > loc;
	loc.push_back(p1);

	pair<int, int> curr;

	while (!loc.empty()) {
		curr = loc.front();
		loc.erase(loc.begin());

		if (curr == p2) {
			if (toCheck == 1) printf("binary\n");
			else if (toCheck == 0) printf("decimal\n");
			return;
		}

		if (grid[get<0>(curr)][get<1>(curr)] == toCheck) {
			if (get<0>(curr) + 1 < r)
				loc.push_back(pair<int, int>(get<0>(curr) + 1, get<1>(curr)));
			if (get<0>(curr) - 1 > 0)
				loc.push_back(pair<int, int>(get<0>(curr) - 1, get<1>(curr)));
			if (get<1>(curr) + 1 < c)
				loc.push_back(pair<int, int>(get<0>(curr), get<1>(curr) + 1));
			if (get<0>(curr) - 1 < 0)
				loc.push_back(pair<int, int>(get<0>(curr), get<1>(curr) - 1));
		}
	}

	printf("neither\n");
	return;
}

int main() {
	int r, c;
	scanf("%d %d", &r, &c);
	int **grid;
	grid = new int *[c];
	for (int i = 0; i < r; i++) {
		grid[i] = new int[c];
	}

	for (int i = 0; i < r; i++) {
		int userIn;
		scanf("%d", &userIn);

		for (int j = 0; j < c; j++) {
			grid[i][j] = userIn % 10;
			userIn /= 10;
		}
	}

	int n;
	scanf("%d", &n);

	int r1[n], c1[n], r2[n], c2[n];
	for (int i = 0; i < n; i++) {
		int t_r1, t_r2, t_c1, t_c2;
		scanf("%d %d %d %d",  &t_r1, &t_c1, &t_r2, &t_c2);
		r1[i] = t_r1 - 1;
		c1[i] = t_c1 - 1;
		r2[i] = t_r2 - 1;
		c2[i] = t_c2 - 1;
	}

	for (int i = 0; i < n; i++) {
		findPath(pair<int, int>(r1[i], c1[i]), pair<int, int>(r2[i], c2[i]), grid, r, c);
	}

	return 0;
}
