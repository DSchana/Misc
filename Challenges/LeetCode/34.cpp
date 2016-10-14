#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
	vector<int>& tmp = nums;
        int final_index = 0;
        while (nums[0] != target && nums[nums.size() - 1] != target) {  // Second condition for [target, ..., target] case
		int index = tmp.size() / 2;
                if (nums[index] < target) {
                        tmp.assign(nums.begin() + index, nums.end());
                        final_index += index;
                }
                else if (nums[index] > target) {
                        tmp.assign(nums.begin(), nums.end() - index);
                        final_index -= index;
                }
                else if (nums[index] == target) {
                        final_index += index;
                        break;
                }

                if (tmp.size() == 1) {
                        return vector<int>(2, -1);
                }
        }

	if (nums[nums.size() - 1] == target) {
		final_index = nums.size() - 1;
	}

        int lower_bound = final_index;
        int upper_bound = final_index;

	//cout << lower_bound << " " << nums.size() << endl;

        // Count left
        while (true) {
                if (lower_bound < 0 || nums[lower_bound] != target) {
                        lower_bound++;
                        break;
                }
                lower_bound--;
        }

        // Count right
        while (true) {
                if (upper_bound > nums.size() - 1 || nums[upper_bound] != target) {
                        upper_bound--;
                        break;
                }
                upper_bound++;
        }

        vector<int> retVal;
        retVal.push_back(lower_bound);
        retVal.push_back(upper_bound);

        return retVal;
}

int main() {
	vector<int> nums;
	/*
	nums.push_back(5);
	nums.push_back(7);
	nums.push_back(7);
	nums.push_back(8);
	nums.push_back(8);
	nums.push_back(10);
	*/
	int in;
	cin >> in;
	for (int i = 0; i < in; i++) {
		int userIn;
		cin >> userIn;
		nums.push_back(userIn);
	}
	cin >> in;

	vector<int> ans = searchRange(nums, in);
	cout << ans[0] << " " << ans[1] << endl;

	return 0;
}
