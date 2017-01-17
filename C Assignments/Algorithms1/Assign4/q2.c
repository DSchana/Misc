#include <stdio.h>

int main() {
	int n1, n2, d1, d2, an, ad;  // numerators, denominators, answer
	char op;  // operator

	scanf("%d/%d%c%d/%d", &n1, &d1, &op, &n2, &d2);

	switch (op) {
	case '+':
		an = n1 * d2 + n2 * d1;
		ad = d1 * d2;
		break;
	case '-':
		an = n1 * d2 - n2 * d1;
                ad = d1 * d2;
		break;
	case '*':
		an = n1 * n2;
		ad = d1 * d2;
		break;
	case '/':
		an = n1 * d2;
		ad = n2 * d1;
		break;
	default:
		break;
	}

	printf("%d/%d\n", an, ad);

	return 0;
}
