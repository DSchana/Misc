#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	vector<int> nums;
	cin >> n;

	vector<int> diffs(n, 0);

	for (int i = 0; i < n; i++) {
		int in;
		cin >> in;
		nums.push_back(in);
	}

	for (int i = 0; i < n-1; i++) {
		diffs[abs(nums[i] - nums[i+1])] = 1;
	}

	for (int i = 1; i < n; i++) {
		if (diffs[i] != 1) {
			cout << "Not Jolly\n";
			return 0;
		}
	}

	cout << "Jolly\n";

	return 0;
}
