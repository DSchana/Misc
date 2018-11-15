// Remove Duplicates from Sorted Array II
// Author: Dilpreet Chana
#include <vector>
#include <algorithm>
#include <cstdio>
#include <array>

using namespace std;

int removeDuplicates(vector<int> &nums) {
	int retVal = nums.size();
	int freqSize = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] > freqSize) {
			freqSize = nums[i];
		}
	}

	int frequency[freqSize];
	for (int i = 0; i < freqSize; i++) {
		frequency[i] = 0;
	}

	for (int i = 0; i < nums.size(); i++) {
		frequency[nums[i]]++;
	}

	for (int i = 0; i < freqSize; i++) {
		if (frequency[i] > 2)
			retVal -= frequency[i] - 2;
	}

	return retVal;
}

int main() {
	vector<int> nums;

	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(3);

	printf("%d\n", removeDuplicates(nums));

	return 0;
}
