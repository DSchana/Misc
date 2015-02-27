#include <iostream>

using namespace std;

int pies(int n, int k, int prev) {
	if (k == 1 && n >= prev) {
		return 1;
	}
	else if (k == n && n >= prev) {
		return 1;
	}
	else {
		int tot = 0;
		for (int i = 1; i < n-k+2; ++i) {
			if (i >= prev) {
				tot += pies(n-i, k-1, i);
			}
		}
		return tot;
	}
}

int main() {
	int n;
	int k;
	cin >> n >> k;
	cout << pies(n, k, 0) << endl;
}
