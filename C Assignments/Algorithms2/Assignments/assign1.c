/*
 * Title:	assign1.c
 * Author:	Dilpreet S. Chana
 * Description:	Express a number's factorial as a linear
 *		combination of the set of prime numbers.
**/

#include <stdio.h>
#include <stdbool.h>

// Prototypes
int findPrimeCount(int n, int p);  // Get number of times p goes into n!
int findNextPrime(int p);	   // Get the prime after p
bool isPrime(int n);		   // Determine if n is prime

int main() {
	while (true) {
		int s_in;
		int curr = 2;  	  // Current prime
		int d_count = 0;  // Number of primes displayed on a line

		scanf("%d", &s_in);

		if (s_in == 0) {
			return 0;
		}

		printf("%3d! = ", s_in);

		while (curr <= s_in) {
			if (curr != 2) {
				printf("*");
			}

			int p_count = findPrimeCount(s_in, curr);
			printf("(%d^%d)", curr, p_count);

			curr = findNextPrime(curr);

			d_count++;
			if (d_count == 9) {  // End of line reached
				printf("\n%6s", " ");
				d_count = 0;
			}
		}

		printf("\n\n");
	}

	return 0;
}

/*
 * Description:	Calculate the number of times p divides into
 *		the factorial of n.
 * Parameters:	Integer n - number to be factorialed
 * 		Integer p - a prime number
 * Return:	The number of time p divides into n!
**/
int findPrimeCount(int n, int p) {
	int p_count = 0;

	for (int i = 2; i <= n; i++) {
		int tmp = i;
		while (tmp % p == 0) {
			p_count++;
			tmp /= p;
		}
	}

	return p_count;
}

/*
 * Description:	Calculate the next number in the set of prime numbers
 * Parameters:	Integer p - a prime number
 * Return:	The next number in the set of prime numbers
**/
int findNextPrime(int p) {
	p++;

	while (!isPrime(p)) {
		p++;
	}

	return p;
}

/*
 * Description: Determine if a number is prime
 * Parameters:	Integer n - any number
 * Return:	True if prime,
 * 		False if not
**/
bool isPrime(int n) {
	if (n < 2) {
		return false;
	}

	// check if n has any factors other than 1, n
	for (int i = 2; i < n / 2; i++) {
		if (n % i == 0) {
			return 0;
		}
	}

	return true;
}
