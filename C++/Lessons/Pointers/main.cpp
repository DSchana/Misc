// main.cpp

#include <iostream>

using namespace std;

void manipulate(double* value) {
	*value = 10.0;
	cout << "Value of int in manipulate: " << *value << endl;
}

int main() {
	int nValue = 8;
	int* pnValue = &nValue;  // * is pointer. Points to the & (address) of nValue

	cout << nValue << " is located: " << pnValue << endl;
	cout << "Int value via pointer: " << *pnValue << endl;  // *Pointer gives value at location

	cout << "===========================================" << endl;
	double dValue = 123.4;
	double* pdValue = &dValue;

	cout << "1. dValue: " << dValue << endl;
	manipulate(pdValue);
	cout << "2. dValue: " << dValue << endl;

	return 0;
}
