#include <cstdio>

using namespace std;

void greet();

void showFavNum() {
	printf("%d\n", 4);
}

int main() {
	showFavNum();

	return 0;
}

void greet() {
	printf("Hello World!\n");
}
