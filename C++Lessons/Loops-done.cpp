#include <cstdio>

using namespace std;

int main() {
	int n;

	scanf("%d", &n);

	if (n > 0) {
		printf("%d is a positive number\n", n);
	}
	else if (n < 0) {
		printf("%d if a negative number\n", n);
	}
	else {
		printf("%d is zero\n");
	}

	return 0;
}