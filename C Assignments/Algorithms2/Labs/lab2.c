/*
 * Title:	  lab2.c
 * Author:	  Dilpreet S. Chana
 * Description:	  Some basic math functions
 * Last Modified: 24 Jan. 2017
**/

#include <stdio.h>

int sum(int n);  	// Calculate the sum of all numbers from 1 to n inclusive
int fact(int n);  	// Calculate the factorial of n
int fib(int n);		// Calculate the nth fibonacci number
int gcd(int x, int y);	// Calculate the greatest common dinominator of x and y
int powr(int a, int b);	// Calculate a raised to the exponent b

int main() {
	while (1) {
		printf("\tMenu\n");
		printf("\t0. Exit\n");
		printf("\t1. Summation\n");
		printf("\t2. Factorial\n");
		printf("\t3. Fibonacci\n");
		printf("\t4. Greatest Common Denominator\n");
		printf("\t5. Power\n");

		int userIn;
		printf("Please make a selection by number: ");
		scanf("%d", &userIn);

		int n, m;
		if (userIn == 0) {
			break;
		}
		else if (userIn < 0 || userIn > 5) {
			printf("Invalid input\n");
			continue;
		}
		else if (userIn <= 3) {
			printf("Please provide input for the selected function: ");
			scanf("%d", &n);
		}
		else if (userIn > 3) {
			printf("Please provide two inputs for the selected function (n m): ");
			scanf("%d %d", &n, &m);
		}

		int out;

		switch (userIn) {
		case 1:
			out = sum(n);
			break;
		case 2:
			out = fact(n);
			break;
		case 3:
			out = fib(n);
			break;
		case 4:
			out = gcd(n, m);
			break;
		case 5:
			out = powr(n, m);
			break;
		default:
			break;
		}

		printf("%d\n", out);
	}

	return 0;
}

/*
 * Objective: Add all the numbers from 1 to n
 * Input:     Integer n >= 1
 * Output:    Return sum of the numbers from 1 to n
 *	      Print error message if n < 1
**/
int sum(int n) {
	if (n < 1) {
		printf("Invalid input: %d is not greater than ", n);
		return 0;
	}

	if (n == 1) {  // Base case
		return 1;
	}

	return n + sum(n - 1);
}

/*
 * Objective: Calculate the factorial of a number
 * Input:     Integer n >= 0
 * Output:    Return factorial of input n
 *            Print error message if n < 0
**/
int fact(int n) {
	if (n < 0) {
		printf("Invalid input: %d is not greater than ", n);
		return -1;
	}

	if (n <= 1) {  // Base case
		return 1;
	}

	return n * fact(n - 1);
}

/*
 * Objective: Calculate the nth fibonacci number
 * Input:     Integer n >= 0
 * Output:    Return the nth fibonacci number
 *            Print error message if n < 0
**/
int fib(int n) {
	if (n < 0) {
                printf("Invalid input: %d is not greater than ", n);
                return -1;
        }

	if (n <= 1) {  // Base case
		return n;
	}

	return fib(n - 1) + fib(n - 2);
}

/*
 * Objective: Calculate the greates common denominator
 *            of two numbers
 * Input:     Integer x >= 0 and y >= 0
 * Output:    Return the gcd of x and y
 *            Print error message if x or y < 0
**/
int gcd(int x, int y) {
	if (x < 0 || y < 0) {
		printf("Invalid input: %d or %d is not greater then ", x, y);
		return -1;
	}

	if (y == 0) {  // Base case
		return x;
	}

	return gcd(y, x % y);
}

/*
 * Objective: Calculate the value of an power
 * Input:     Integer a > 0, b >= 0
 * Output:    Return a raised to the exponent b
 *            Print error message if a <= 0 or b < 0
**/
int powr(int a, int b) {
	if (a <= 0 || b < 0) {
		printf("Invalid input: %d and %d are not greater than ", a, b);
		return -1;
	}

	if (b == 0) {  // Base case
		return 1;
	}

	return a * powr(a, b - 1);
}
