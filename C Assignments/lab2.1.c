// Author: Dilpreet S. Chana
// Date:   Wednesday, 5 October

#include <stdio.h>

int main() {
	printf("%-15.8u\n", 40000);
	printf("%09.3f\n", 1.234);

	// Declare variables for time
	int hour, min, sec;

	scanf("%2d:%2d:%2d", &hour, &min, &sec);

	return 0;
}
