#include <cstdio>

using namespace std;

int main() {
	for (int i = 0; i < 6; i++) {
		printf("%d\n", i);
	}
	printf("--- 1 -------------\n");

	for (int i = 0; i < 6; ) {
		printf("%d\n", i);
		i += 1;
	}
	printf("--- 2 -------------\n");

	for (int i = 0; ; ) {
		if (i >= 6) {
			break;
		}

		printf("%d\n", i);
		i += 1;
	}
	printf("--- 3 -------------\n");

	int i = 0;
	for ( ; i < 6; ) {
		printf("%d\n", i);
		i += 1;
	}
	printf("--- 4 -------------\n");

	int j = 0;
	while (j < 6) {
		printf("%d\n", j);
		j += 1;
	}
	printf("--- 5 -------------\n");

	return 0;
}
