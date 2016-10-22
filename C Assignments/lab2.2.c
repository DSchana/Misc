// Author: Dilpreet S. Chana
// Date:   Wednesday, 5 October

#include <stdio.h>

int main() {
	// Declare variables
	int item_number;
	float unit_price;
	int day, month, year;

	// Display prompt and get inputs
	printf("Enter item number: ");
	scanf("%d", &item_number);
	printf("Enter unit price: ");
	scanf("%f", &unit_price);
	printf("Enter purchase date (mm/dd/yyyy): ");
	scanf("%2d/%2d/%4d", &day, &month, &year);

	// Output formated table
	printf("%-10s %-10s %-10s\n", "Item", "Unit", "Purchase");
	printf("%-10s %-10s %-10s\n", "", "Price", "Date");
	printf("%-10s %-10s %-14s\n", "----", "------", "--------------");
	printf("%-10d $%9.2f %2d/%2d/%4d\n", item_number, unit_price, day, month, year);

	return 0;
}
