#include <cstdio>

int main() {
	unsigned long long num;
	int ip[4];

	scanf("%llu", &num);

	for (int i = 0; i < 4; i++) {
		ip[i] = num % 256;
		num /= 256;
	}

	printf("%d.%d.%d.%d\n", ip[3], ip[2], ip[1], ip[0]);

	return 0;
}
