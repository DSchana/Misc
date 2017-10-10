#include <cstdio>
#include <string>

using namespace std;

void greet();
void add(int a, int b);
char getFirstLetter(string s);

void showFavNum() {
	printf("%d\n", 4);
}

int main() {
	showFavNum();
	greet();
	add(4, 5);
	printf("%c\n", getFirstLetter("Hello"));

	return 0;
}

void greet() {
	printf("Hello World!\n");
}

void add(int a, int b) {
	printf("%d\n", a + b);
}

char getFirstLetter(string s) {
	return s[0];
}
