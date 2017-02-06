/*
 * Title:	lab3.c
 * Author:	Dilpreet S. Chana
 * Description:	Basic 2D array manipulations
**/

// Includes
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// C preproccesor directives
#define M 6
#define N 5

// Prototypes
void printArray2D(int A[][N]);		 // Print the array
void populateRandom2D(int A[][N]);	 // Fill the array with random numbers
bool linearSearch2D(int n, int A[][N]);  // Search for int n in array
void leftShift2D(int A[][N]);		 // Shift all elements to the left

int main() {
	srand((unsigned)time(NULL));

	int A2D[M][N];
	int userIn;

	while (true) {
		// Menu
		printf("\t 0. Exit\n");
		printf("\t 1. Populate\n");
		printf("\t 2. Print\n");
		printf("\t 3. Search\n");
		printf("\t 4. Left Shift\n");

		scanf("%d", &userIn);

		switch (userIn) {
		case 0:
			return 0;
		case 1:
			populateRandom2D(A2D);
			break;
		case 2:
			printArray2D(A2D);
			break;
		case 3:
			scanf("%d", &userIn);
			if (linearSearch2D(userIn, A2D))  printf("true\n");
			else				  printf("false\n");
			break;
		case 4:
			leftShift2D(A2D);
			break;
		default:
			break;
		}
	}

	return 0;
}

/*
 * Description: Fill array with random numbers from 1 to M x N
 * 		without any duplicates
 * Parameters:  Array of integers A - the array to populate
 * Returns:	void
**/
void populateRandom2D(int A[][N]) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			while (true) {
				int n = rand() % (M * N) + 1;
				if (!linearSearch2D(n, A)) {  // n is not in the array
					A[i][j] = n;
					break;
				}
			}
		}
	}
}

/*
 * Description: Print all elements of 2D array in a grid
 * Parameter:	Array of integers A - the array to print
 * Returns:	void
**/
void printArray2D(int A[][N]) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			printf("%2d ", A[i][j]);
		}
		printf("\n");
	}
}

/*
 * Description: Search of a int n in the array
 * Parameter:	Array of integers A - the array to search
 * 		Integer n 	    - the element to search for
 * Returns:	true if n is found
 *		false if not
**/
bool linearSearch2D(int n, int A[][N]) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] == n) {
				return true;
			}
		}
	}

	return false;
}

/*
 * Description: Shift all elements of array to left by one
 * Parameter:	Array of integers A - the array to left shift
 * Returns:	void
**/
void leftShift2D(int A[][N]) {
	int f_tmp = A[0][0];  // First element

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (j == N - 1 && i == M - 1) {  // Last element
				A[i][j] = f_tmp;
			}
			else if (j == N - 1) {  // End of row
                        	A[i][j] = A[i + 1][0];
                        }
			else {
				A[i][j] = A[i][j + 1];
			}
		}
	}
}
