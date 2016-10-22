#include <cstdio>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int nums[n];
	for (int i = 0; i < n; i++) {
		int userIn;
		scanf("%d", &userIn);
		nums[i] = userIn;
	}

	for (int i = 0; i < n; i++) {
		if (nums[i] % 2 == 0) printf("%d is even\n", nums[i]);
		else printf("%d is odd\n", nums[i]);
	}

	return 0;
}
