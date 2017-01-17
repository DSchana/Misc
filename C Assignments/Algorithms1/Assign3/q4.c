#include <stdio.h>
#include <math.h>

int main() {
	// part A
	int n = 1, a = 1;
	if (a > n && n > 0)
		printf("Good!\n");
	else
		printf("Hello!\n");

	// Part B
	int k = 1;
	while (k <= 10) {
		printf("%d ", k);
		k++;
	}
	printf("\n");

	// Part C
	k = 1;
	do {
		printf("%d ", k);
		k++;
	} while (k <= 10);
	printf("\n");

	// Part D
	float x = 10.0f;
	while (x >= 1.001) {
		printf("%.4f ", x);
		x = sqrt(x);
	}
	printf("\n");

	return 0;
}
