#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	double e = 0;  // Final value

	for (float i = 0; i <= n; i++) {
		float fact = 1;

		// multiply i * i-1 * i-2 * ... * 1 to find the factorial
		for (int j = i; j > 0; j--) {
			fact *= j;
		}

		e += i / fact;
	}

	printf("%f\n", e);

	return 0;
}
