#include <cstdio>
#include <vector>

using namespace std;

void finalPrice(vector < int > prices) {
	int n = prices.size();
	vector<int> discounts(n);
	vector<int> n_disc;
	discounts[n-1] = 0;  // constant

	for (int i = n - 2; i >= 0; i--) {
		bool disc = false;
		for (int j = i + 1; j < n; j++) {
			if (discounts[j] <= prices[j]) {
				discounts[i] = prices[j];
				disc = true;
				break;
			}
		}
		if (!disc) {
			discounts[i] = 0;
			n_disc.push_back(i);
		}
	}

	n_disc.push_back(n-1);

	int tot = 0;
	for (int i = 0; i < n; i++) {
		tot += prices[i] - discounts[i];
	}
	printf("%d\n", tot);

	for (int i = 0; i < n_disc.size(); i++) {
		printf("%d ", n_disc[i]);
	}
	printf("\n");
}


int main() {
	int n;
	scanf("%d", &n);
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int userIn;
		scanf("%d", &userIn);
		vec.push_back(userIn);
	}

	finalPrice(vec);

	return 0;
}
