#include <cstdio>
#include <string>

using namespace std;

int main() {
	char c = 'H';
	char ca[15] = "HelloWorld!";
	string s = "HelloWorld";

	printf("%c\n", c);
	printf("%s\n", ca);
	printf("%s\n", s.c_str());

	return 0;
}
