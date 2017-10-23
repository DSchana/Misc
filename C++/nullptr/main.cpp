#include <cstdio>

using namespace std;

int main() {
	int *n, *m;

	*n = 5;  // n points to a real spot in memory with the value 5
	m = nullptr;  // m points to nowhere. Works for NULL as well

	if (n) {  // true if not nullptr
		printf("%d\n", *n);
	}
	else {
		printf("n is a nullptr\n");
	}

	if (m) {
		printf("%d\n", *m);
	}
	else {
		printf("m is a nullptr\n");
	}

	return 0;
}
