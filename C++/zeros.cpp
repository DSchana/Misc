// zeros.cpp

#include <iostream>
#include <stdlib.h>

using namespace std;

int factorial(int n) {
	if (n <= 1) {
		return 1;
	}
	else {
		return n*factorial(n-1);
	}
}

int main() {
	int n;
	int zeros = 0;
	char facted[225];
	cin >> n;
	itoa(factorial(n), facted, 10);
	cout << facted << endl;
	for (int i = 0; i < 256; i++) {
		if (facted[i] == '0') {
			zeros++;
		}
	}
	cout << zeros-1 << endl;
}