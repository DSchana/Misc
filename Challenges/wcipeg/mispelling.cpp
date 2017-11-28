#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int* p = new int[4];
	char** s;
	s = new char*[n];

	for (int i = 0; i < n; i++) {
		s[i] = new char[80];
		scanf("%d %s", p + i, s[i]);
	}

	for (int i = 0; i < n; i++) {
		p[i] -= 1;
		if (p[i] > strlen(s[i]) - 1 || p[i] < 0) {  // Out of bounds
			continue;
		}
		if (p[i] == strlen(s[i]) - 1) {
			s[i][strlen(s[i]) - 1] = '\0';
			continue;
		}

		copy((s[i] + p[i] + 1), (s[i] + strlen(s[i])), (s[i] + p[i]));
		s[i][strlen(s[i]) - 1] = '\0';
	}

	for (int i = 1; i <= n; i++) {
		printf("%d %s\n", i, s[i - 1]);
	}

	return 0;
}
