#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> ints;
	ints.push_back(0);
	ints.push_back(3);
	ints.push_back(4);

	printf("%d\n", *max_element(ints.begin(), ints.end()));

	vector<int> another(*max_element(ints.begin(), ints.end()));

	for (int &n : ints) {
		printf("%d\n", n);
	}

	return 0;
}
