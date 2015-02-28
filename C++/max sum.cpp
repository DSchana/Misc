#include <iostream>

using namespace std;

int main() {
	int n, i, s1 = 0, s2 = 0;
	cin >> n;
	int nums[n];
	for (i = 0; i<n; i++) {
		cin >> nums[i];
	}
	for (i = 0; i < n; i+=2) {
		s1 += nums[i];
	}
	for (i = 1; i < n; i+=2) {
		s2 += nums[i];
	}
	if (s1 > s2) {
		cout << s1 << endl;
	}
	else {
		cout << s2 << endl;
	}

	return 0;
}