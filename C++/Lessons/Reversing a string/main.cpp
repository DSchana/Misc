// main.cpp

#include <iostream>

using namespace std;

int main() {
	char text[] = "Hello, World;";
	int nChars = sizeof(text)-1;

	char *pStart = text;
	char *pEnd = &text[nChars-1];

	while (pStart < pEnd) {
		char save = *pStart;
		*pStart = *pEnd;
		*pEnd = save;

		pStart++;
		pEnd--;
	}

	cout << text << endl;

	return 0;
}
