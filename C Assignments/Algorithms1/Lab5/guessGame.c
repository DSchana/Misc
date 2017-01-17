#include <stdio.h>
#include <stdlib.h>

int main() {
	int goal = rand() % 50 + 1;

	for (int i = 0; i < 10; i++) {
		int n;
		printf("Guess number between 1 and 50: ");
		scanf("%d", &n);

		if (n > goal) {
			printf("Too high...\n");
		}
		else if (n < goal) {
			printf("Too low...\n");
		}
		else {
			printf("Correct, the number was %d\n", goal);
			return 0;
		}
	}

	printf("Wrong, the number was %d\n", goal);

	return 0;
}
