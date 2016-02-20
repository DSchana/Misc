#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int q, n, tot=0;
	cin >> q >> n;
	int dmoj[n], peg[n];

	for (int i=0; i<n; i++) {
		cin >> dmoj[i];
	}
	for (int i=0; i<n; i++) {
		cin >> peg[i];
	}

	vector<int> dmojV(dmoj, dmoj+n);
	vector<int> pegV(peg, peg+n);

	sort(dmojV.begin(), dmojV.end());
	sort(pegV.begin(), pegV.end());

	if (q == 1) {
		for (int i=0; i<n; i++) {
			tot += max(dmojV[i], pegV[i]);
		}
	}
	else if (q == 2) {
		for (int i=0; i<n; i++) {
			tot += max(dmojV[i], pegV[n-i-1]);
		}
	}

	cout << tot << endl;

	return 0;
}