#include <cstdio>
#include <array>

using namespace std;

int main() {
	int a[5];
	int b[] = { 4, 7, 3, 2, 3 };
	array<int, 4> c = { 32, 5, 2, 5 };

	for (int i = 0; i < 5; i++) {
		a[i] = i * 2;
	}

	// Size
	printf("b: %d\n", (int)sizeof(b) / (int)sizeof(int));
	printf("c: %lu\n\n", c.size());

	// Multidimensional
	int m[3][5];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			m[i][j] = i + j;
		}
	}

	printf("m: %lu\n", sizeof(m) / sizeof(int));
	printf("m: %lu\n", sizeof(m[0]) / sizeof(int));
	printf("m: %lu\n", sizeof(m) / sizeof(m[0]));

	return 0;
}
