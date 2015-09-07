// main.cpp

#include <iostream>

using namespace std;

int main() {
	const int NSTRINGS = 5;
	string texts[NSTRINGS] = {"one", "two", "three", "four", "five"};

	string *pTexts = texts;
	cout << *pTexts << endl;  // outputs first element of array: one

	pTexts++;
	cout << *pTexts << endl;  // outputs second element of array: two

	pTexts--;
	cout << *pTexts << endl;  // outputs first element again : one

	string *pEnd = &texts[NSTRINGS-1];  // Points to location of last element
	pTexts = &texts[0];  // reset pTexts
	cout << "=====================================" << endl;

	while (pTexts != pEnd+1) {
		cout << *pTexts << endl;
		pTexts++;
	}

	pTexts = &texts[0];  // reset pTexts
        cout << "=====================================" << endl;

	long elements = (long)(pEnd + 1 - pTexts);  // long to handle the long types of pointers
	cout << elements << endl;

	return 0;
}
