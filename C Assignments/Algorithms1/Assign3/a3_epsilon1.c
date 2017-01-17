#include <stdio.h>

int main() {
	double eps, e = 0.0f, term = 1.0f, fact = 1;
	int i = 1;

	scanf("%lf", &eps);

	while (eps <= term) {
		e += term;
		fact *= i;
		i++;
		term = 1/fact;
	}

	printf("Approximation of e: %f\n", e);

	return 0;
}
