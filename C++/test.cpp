#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
	int *n;

	*n = 5;
	printf("%d\n", *n);

	//n = nullptr;
	// printf("%d\n", *n); --> Segmentation fault

	if (!n) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}

	return 0;
}
