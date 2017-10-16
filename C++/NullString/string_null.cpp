#include <cstdio>
#include <string>

using namespace std;

int main() {
	printf("1\n");
	string* s;
	int* n = 3;
	s = NULL;
	//n = NULL;
	printf("%d\n", *n);

	if (s == NULL && n == NULL) {
		printf("Works\n");
	}

	return 0;
}
