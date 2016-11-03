#include <cstdio>
#include <map>
#include <vector>

using namespace std;

struct ip {
	int x1, x2, x3, x4;
};

int main() {
	int b, n;
	scanf("%d", &b);

	map<int, vetor<int>> banned;

	for (int i = 0; i < b; i++) {
		int t1, t2, t3, t4;
		scanf("%d.%d.%d.%d", &t1, &t2, &t3, &t4);

		banned[t1].push_back(t2);`
		banned[t2] = t3;
		banned[t3] = t4;
		banned[t4] = -1;
	}

	scanf("%d", &n);

	for (int i = 0; i < n;

	}

	return 0;
}
