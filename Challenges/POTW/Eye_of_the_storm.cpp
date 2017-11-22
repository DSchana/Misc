/*
 * Title:	eye_of_the_storm.cpp
 * Author:	Dilpreet S. Chana
 * Description:	Given a fake data set, find the eye
 *		of the strom if it exists
**/

#include <cstdio>
#include <vector>
#include <limits>

using namespace std;

int main() {
	int eye = -1;
	// NOTE: Right average is reverese relative to the data set
	vector<double> left_avg;   // left average of all readings
	vector<double> right_avg;  // right average of all readings
	vector<int> data_set;

	int n;
	scanf("%d", &n);

	// Populate data set and calculate left avg
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		data_set.push_back(t);

		if (i == 0) {
			left_avg.push_back(numeric_limits<double>::max());
		}
		else if (i == 1) {
			left_avg.push_back(data_set[0]);
		}
		else {
			left_avg.push_back((left_avg[i - 1] + data_set[i - 1]) / 2.0);
		}
	}

	// Calculate right avg
	for (int i = n - 1; i >= 0; i--) {
		if (i == n - 1) {
			right_avg.push_back(numeric_limits<double>::max());
		}
		else if (i == n - 2) {
			right_avg.push_back(data_set[n - 1]);
		}
		else {
			right_avg.push_back((right_avg[i - 1] + data_set[n - 1 - i - 1]) / 2.0);
		}
	}

	for (int i = 0; i < n; i++) {
		if (data_set[i] <= 0.85 * left_avg[i] && data_set[i] <= 0.85 * right_avg[n - 1 - i]) {
			eye = i;
			break;
		}
	}

	printf("%d\n", eye);

	return 0;
}
