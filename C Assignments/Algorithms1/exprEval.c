// Dilpret S. Chana
// Add the given expression

#include <stdio.h>

int main() {
	float num1, num2, ans;
	char op;

	scanf("%f %c %f", &num1, &op, &num2);

	if (op == '+') {
		ans = num1 + num2;
	}
	else if (op == '-') {
		ans = num1 - num2;
	}
	else if (op == '*') {
		ans = num1 * num2;
	}
	else if (op == '/') {
		if (num2 == 0) {
			printf("Division by 0\n");
			return 0;
		}
		ans = num1 / num2;
	}
	else {
		printf("Invalid operation\n");
		return 0;
	}

	printf("%.2f %c %.2f = %.2f\n", num1, op, num2, ans);
	return 0;
}
