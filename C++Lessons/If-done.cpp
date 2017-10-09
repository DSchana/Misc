#include <cstdio>

using namespace std;

int main() {
	int n;

	printf("Enter a grade: ");
	scanf("%d", &n);

	if (n >= 80) {
		printf("%d is an A\n", n);
	}
	else if (n >= 70) {
		printf("%d is a B\n", n);
	}
	else if (n >= 60) {
		printf("%d is a C\n", n);
	}
	else if (n >= 50) {
		printf("%d is a D\n", n);
	}
	else {
		printf("%d is a fail\n", n);
	}

	return 0;
}
