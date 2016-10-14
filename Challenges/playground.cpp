#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> nums;
	for (int i = 0; i < 11; i++) {
		nums.push_back(i);
	}

	for (vector<int>::iterator i = nums.begin() + 5; i != nums.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;

	return 0;
}
