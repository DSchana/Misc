#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int n;
	printf("Enter the number of students: ");
	scanf("%d", &n);

	int gpa_freq[4] = { 0, 0, 0, 0 };

	for (int i = 0; i < n; i++) {
		int userIn = (rand() % 4) + 1;
		printf("GPA of student #%d: %d\n", i + 1, userIn);
		// scanf("%d", &userIn);

		if (userIn > 0 && userIn < 5) {
			gpa_freq[userIn - 1]++;
			continue;
		}

		printf("Invalid number!\n");
		i--;
	}

	printf("The total number of students is %d.\n", n);
	for (int i = 0; i < 4; i++) {
		printf("GPA %d --- %d student(s)\n", i + 1, gpa_freq[i]);
	}

	return 0;
}
