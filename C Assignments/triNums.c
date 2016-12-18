#include <stdio.h>

int readNum();
int itTriNum(int num);
int recTriNum(int num);


int main() {
	int num;

	while (1) {
		num = readNum();
		if (num == 0) {
			break;
		}

		printf("Iterative: triangular number for %d is %d\n", num, itTriNum(num));
		printf("Recursive: triangular number for %d is %d\n", num, recTriNum(num));
	}

	return 0;
}

int readNum() {
	int num = -1;

	while (num < 0) {
		printf("Enter a number greater than 0: ");
		scanf("%d", &num);
		if (num < 0) {
			printf("Invalid number\n");
		}
	}

	return num;
}

int itTriNum(int num) {
	int ans = 0;

	for (int i = 1; i <= num; i++) {
		ans += i;
	}

	return ans;
}

int recTriNum(int num) {
	if (num == 1) {
		return 1;
	}
	return num + recTriNum(num - 1);
}
