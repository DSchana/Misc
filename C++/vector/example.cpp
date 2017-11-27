#include <cstdio>
#include "vector.h"


using namespace std;

int main() {
	vector<int> v(3, 2);

	for (int i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}

	return 0;
}
