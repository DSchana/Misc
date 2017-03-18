/*
 * Title:	lab5b.c
 * Author:	Dilpreet Chana
 * Description:	Various functions on arrays using pointers
**/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 5

void fillArray(int *a, int s);	 // Fill array with random numbers
void printArray(int *a, int s);  // Display elements of array
void bubbleSort(int *a, int s);  // Sort array
void swap(int *a, int *b);		 // Swap two numbers

int main() {
	int a[SIZE];

	fillArray(a, SIZE);
	printArray(a, SIZE);
	bubbleSort(a, SIZE);
	printArray(a, SIZE);

	return 0;
}

/*
 * Description:	Fill array with pseudo random numbers
 * Parameters:	Pointer - a: Pointer to first member in array
 *				Integer - s: Size of array
 * Returns:		void
**/
void fillArray(int *a, int s) {
	srand((unsigned)time(NULL));

	for (int i = 0; i < s; i++) {
		*(a + i) = rand() % 101;
	}
}

/*
 * Description: Display the elements of array with spacing
 * Parameters:	Pointer - a: Pointer to first member in array
 *				Integer - s: Size of array
 * Returns:		void
**/
void printArray(int *a, int s) {
	for (int i = 0; i < s; i++) {
		printf("%d ", *(a + i));
	}
	printf("\n");
}

/*
 * Description: Sort array using the bubble sort algorithm
 * Parameters:	Pointer - a: Pointer to first member in array
 *				Integer - s: Size of array
 * Returns:		void
**/
void bubbleSort(int *a, int s) {
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s - 1; j++) {
			if (*(a + j) > *(a + j + 1)) {
				swap(a + j, a + j + 1);
			}
		}
	}
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
