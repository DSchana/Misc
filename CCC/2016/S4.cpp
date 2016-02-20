#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	bool found = true;
	cin >> n;
	int balls[n];
	for (int i=0; i<n; i++) {
		cin >> balls[i];
	}

	while (found) {
		found = false;
		for (int i=0; i<n-2; i++) {
			if (balls[i] == balls[i+2]) {
				balls[i] = balls[i] + balls[i+1] + balls[i+2];
				balls[i+1] = 0;
				balls[i+2] = 0;
				i+=2;
				found = true;
			}
			else if (balls[i] == balls[i+1]) {
				balls[i] = balls[i] + balls[i+1];
				balls[i+1] = 0;
				i++;
				found = true;
			}
		}
	}
	
	cout << endl << *max_element(balls, balls+n) << endl;

	return 0;
}