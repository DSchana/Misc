#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int h1, m1, s1;
	int h2, m2, s2;

	scanf("%d:%d:%d", &h1, &m1, &s1);
	scanf("%d:%d:%d", &h2, &m2, &s2);

	int t1 = (h1 * 3600) + (m1 * 60) + (s1);
	int t2 = (h2 * 3600) + (m2 * 60) + (s2);

	int a1 = t2 - t1;
	int a2 = 86400 - t1 + t2;
	int a3 = t1 - t2;
	int a4 = 86400 - t2 + t1;

	if (a1 < 0) a1 = 86401;
	if (a2 < 0) a2 = 86401;
	if (a3 < 0) a3 = 86401;
	if (a4 < 0) a4 = 86401;

	printf("%d\n", min(a1, min(a2, min(a3, a4))));

	return 0;
}
