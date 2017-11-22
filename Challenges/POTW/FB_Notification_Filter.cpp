#include <algorithm>
#include <vector>
#include <cstdio>
#include <utility>

using namespace std;

int main () {
	vector<vector<int> > friends;
	vector<vector<pair<int, int> > > posts;
	vector<int> post_nums;

	int n;
	scanf("%d", &n);
	printf("%d\n", n);

	for (int i = 0; i < n; i++) {
		int a, b;
		printf("1\n");
		scanf("%d %d", &a, &b);
		printf("2\n");

		// Resize friends list
		if (a > friends.size() || b > friends.size()) {
			printf("3\n");
			friends.resize(max(a, b));
		}

		printf("4\n");
		friends[a].push_back(b);
		friends[b].push_back(a);
		printf("5\n");
	}
	printf("3\n");

	int m, max_post = 0;
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);

		if (x > posts.size()) {
			posts.resize(x);
		}

		if (find(post_nums.begin(), post_nums.end(), y) != post_nums.end() && post_nums[post_nums.size() - 1] != y) {
			post_nums.push_back(y);
		}

		max_post = max(max_post, y);
		posts[x].push_back(make_pair(y, z));
	}

	int u, t;
	scanf("%d %d", &u, &t);

	vector<int> s;
	s.resize(max_post, 0);

	for (int i = 0; i < friends[u].size(); i++) {
		for (int j = 0; j < posts[friends[u][i]].size(); i++) {
			s[posts[friends[u][i]][j].first] += posts[friends[u][i]][j].second;
		}
	}

	for (int i = 0; i < post_nums.size(); i++) {
		if (s[post_nums[i]] >= t) {
			printf("%d", post_nums[i]);
		}
	}

	return 0;
}
