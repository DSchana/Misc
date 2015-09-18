// warmup1.cpp

#include <iostream>
#include <limits>

using namespace std;

int main() {
	int a, min_p = numeric_limits<int>::max();

	cin >> a;

	for (int i=0; i<a/2; i++) {
		if (a % i == 0 && (2*i) + (2*(a/i)) < min_p) {
			min_p = (2*i) + (2*(a/i));
		}
	}

	cout << min_p << endl;

	return 0;
}