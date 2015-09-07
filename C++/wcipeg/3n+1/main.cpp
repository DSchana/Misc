// main.cpp

#include <iostream>

using namespace std;

int main() {
	int n;
	int count = 0;
	cin >> n;

	while (true) {
		if (n == 1) {
			cout << count << endl;
			break;
		} else if (n % 2 == 1) {
			n = (3 * n) + 1;
		} else {
			n /= 2;
		}
		count++;
	}

	return 0;
}
