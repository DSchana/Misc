#include <iostream>

using namespace std;

int main() {
	bool returned = false;
	long long x = 0;
	long long y = 0;
	int breaks = 0;
	int tot_time = 0;
	int n;
	cin >> n;
	int direction [n];
	int travle_time [n];
	int speed [n];
	for (int i = 0; i<n; i++) {
		cin >> direction[i];
		cin >> travle_time[i];
		cin >> speed[i];
	}

	for (int i = 0; i<n; i++) {
		tot_time += travle_time[i];

		if (direction[i] == 12) {
			y -= travle_time[i]*speed[i];
		}
		if (direction[i] == 6) {
			y += travle_time[i]*speed[i];
		}
		if (direction[i] == 9) {
			x -= travle_time[i]*speed[i];
		}
		if (direction[i] == 3) {
			x += travle_time[i]*speed[i];
		}
		if (x == 0 && y == 0) {
			returned = true;
			break;
		}
		if (tot_time % 5 == 0) {
			breaks ++;
		}
		cout << x << " " << y << "   " << tot_time << " " << breaks << endl;
	}
	if (breaks > 0 && returned) {
		cout << breaks << endl;
	} else {
		cout << -1 << endl;
	}

	return 0;
}