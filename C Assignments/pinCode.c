#include <stdio.h>
#include <math.h>

int main() {
	for (int i = 0; i < 6; i++) {
		float n;
		printf("Enter pin code (attempt %d): ", i);
		scanf("%f", &n);

		// 5 digit number
		if (n / 10000 >= 1 && n / 100000  < 1) {
			int j;
			for (j = 1; j <= 10000; j *= 10) {
				if ((((int)n / j) % 10) % 3 != 0) {
					printf("Code %.0f is invalid!\n", n);
					break;
				}
			}
			if (j == 100000) {
				printf("Code %.0f is correct!\n", n);
				return 0;
			}
		}
		else {
			printf("Code %.0f is invalid!\n", n);
		}
	}

	printf("Intruder alert!\n");

	return 0;
}
