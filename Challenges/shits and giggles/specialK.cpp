#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int size;
	scanf("%d", &size);

	vector<int> s;

	for (int i = 0; i < size; i++) {
		int in;
		scanf("%d", &in);
		s.push_back(in);
	}

	if (size <= 0) {
		printf("No\n");
		return 0;
	}

	for (int i = size; i >= 0; i--) {
		for (int j = 0; j <= size - i + 1; j++) {
			vector<int> ns;
			for (int k = j; k < i + 1; k++) {
				ns.push_back(s[k]);
			}
			//printf("\n");

			int t = pow(ns.size(), 3);

			int sum = 0;
			for (int k = 0; k < ns.size(); k++) {
				printf("%d ", ns[k]);
				sum += ns[k];
			}
			printf("\n");

			if (sum < t) {
				printf("No\n");
				//return 0;
			}
		}
	}
	printf("Yes\n");

	return 0;
}
