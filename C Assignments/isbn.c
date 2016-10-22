#include <stdio.h>

int main() {
	// Declare variables
	unsigned int isbn;
	int total = 0;

	// Get 6 digit ISBN
	printf("Enter ISBN: ");
	scanf("%u", &isbn);

	// Extract numbers indevidually and calculate the check digit
	for (int i = 2; i < 11; i++) {
		total += (isbn % 10) * i;
		isbn = isbn / 10;
	}

	total = 11 - (total % 11);

	// Output check digit
	if (total == 10)
		printf("The check digit is X\n");
	else
		printf("The check digit is %d\n", total);

	return 0;
}
