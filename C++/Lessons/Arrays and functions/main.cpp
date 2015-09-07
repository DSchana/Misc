// main.cpp

#include <iostream>
using namespace std;

void show1(const int nElements, string texts[]) {
	for (int i=0; i<nElements; i++) {
		cout << texts[i] << endl;
	}
}

void show2(const int nElements, string *texts) {  // does same as show1
        for (int i=0; i<nElements; i++) {
                cout << texts[i] << endl;
        }
}

void show3(string (&texts)[3]) {  // does same as show1 and retains sizeof information
        for (int i=0; i<sizeof(texts)/sizeof(string); i++) {
                cout << texts[i] << endl;
        }
}

char *getMemory() {
	char *pMem = new char[100];

	return pMem;
}

void freeMemory(char *pMem) {
	delete [] pMem;
}

int main() {
	string texts[] = {"apple", "orange", "banana"};
	cout << sizeof(texts)/sizeof(string) << endl;

	show1(sizeof(texts)/sizeof(string), texts);
	show2(sizeof(texts)/sizeof(string), texts);
	show3(texts);

	char *pMemory = getMemory();
	freeMemory(pMemory);

	return 0;
}
