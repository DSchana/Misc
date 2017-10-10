#include <cstdio>

using namespace std;

void showArray(int a[], int s);
char getFirstLetter(char s[]);

int main() {
	int a[] = { 1, 4, 2, 5 };
	char s[] = "Hello";

	showArray(a, 4);
	printf("%c\n", getFirstLetter(s));

	return 0;
}

void showArray(int a[], int s) {
	for (int i = 0; i < s; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

char getFirstLetter(char s[]) {
	return s[0];
}
