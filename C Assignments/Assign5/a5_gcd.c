#include <stdio.h>
#include <time.h>

int gcd(int n1, int n2);

int main() {
	srand(time(NULL));

	int n1 = (rand() % 99) + 2;
	int n2 = (rand() % 99) + 2;

	if (n1 < n2) {
		int tmp = n1;
		n1 = n2;
		n2 = tmp;
	}

	printf("The GCD of %d and %d is %d\n", n1, n2, gcd(n1, n2));

	return 0;
}

int gcd(int n1, int n2) {
	int m = n1 % n2;
	if (m == 0) {
		return n2;
	}
	return gcd(n1, m);
}
