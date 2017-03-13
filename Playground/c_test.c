#include <string.h>
#include <stdio.h>

int main() {
	char c;
	int d;

	while (1) {
		scanf("%c", &c);
		printf("%c -> %d\n", c, (int)c);
	}

	return 0;
}