#include <stdio.h>

// Boolean values
#define BOOL int
#define TRUE 1
#define FALSE 0

int readNum () {
	int num = 0;
	while (num < 1) {
		printf("Enter a valid number (>1): ");
		scanf("%d", &num);
	}
	return num;
}

BOOL IsPrime(int prime) {
	BOOL p_flag = FALSE;
	for (int i = 2; i < prime; i++) {
		if (prime % i > 0) {
			p_flag = TRUE;
			break;
		}
	}
	return p_flag;
}

int FindPrimeCount(int num, int prime) {
	int freq = 0;
	while(num % prime == 0) {
		num /= prime;
		freq++;
	}
	if (freq  > 0) {
		printf("(%d^%d)", prime, freq);
		if (num != 1) {
			printf(" x ");
		}
	}
	return num;
}

int main() {
	int current_prime, num;
	num = readNum();
	current_prime = 2;

	printf("%d = 1 x ", num);

	while (num != 1) {
		num = FindPrimeCount(num, current_prime);

		current_prime ++;
		while (!IsPrime(current_prime)) {
			current_prime ++;
		}
	}

	printf("\n");

	return 0;
}
