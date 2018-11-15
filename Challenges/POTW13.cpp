#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	vector< vector<int> > tree;
	int rows;

	scanf("%d", &rows);

	for (int i = 0; i < rows; i++) {
		vector<int> row;
		for (int j = 0; j < pow(2, i); i++) {
			int userIn;
			scanf("%d", &userIn);

			row.push_back(userIn);
		}
		tree.push_back(row);
	}

	return 0;
}
