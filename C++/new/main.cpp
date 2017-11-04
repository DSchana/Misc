#include <cstdio>
#include <string>

using namespace std;

int main() {
	int a = 4;
	int* n = new int();

	memcpy(n, &a, sizeof(a));

	printf("%d\n", *n);

	return 0;
}
