/*
TRACE:

*salary = 200
salary1 = 20000
salary2 = 60000
salary3 = 2008
**/

/*
 * Title		lab4.c
 * Author:		Dilpreet Chana
 * Description:	Implement manipulations on
 *				arrays using pointers.
**/

#include <stdio.h>

// Prototypes
int *largest(int *a, int s);  // Find largest element in array
void swap(int *a, int *b);	  // Swap two numbers

int main() {
	int nums[] = { 3, 4, 2, 5 };
	int a = 3;
	int b = 6;

	printf("%d\n", *largest(nums, 4));

	printf("%d %d\n", a, b);
	swap(&a, &b);
	printf("%d %d\n", a, b);

	return 0;
}

/*
 * Description: Find largest element in array
 * Parameters:	Pointer - a: Pointer to first member in array
 *				Integer - s: Size of array
 * Returns:		Pointer to largest element in a
**/
int *largest(int *a, int s) {
	int *ret = a;

	for (int i = 0; i < s; i++) {
		if (*a > *ret) {
			ret = a;
		}
		a++;
	}

	return ret;
}

/*
 * Description: Swap two numbers
 * Parameters:	Pointer - a: Pointer to first number
 *				Pointer - b: Pointer to second number
 * Returns:		void
**/
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}