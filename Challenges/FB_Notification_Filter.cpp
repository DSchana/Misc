#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <utility>

using namespace std;

int main () {
	map<int, vector<int> > friends;	  	   // person - List of people
	map<int, vector<pair<int, int> > > posts;  // person - (post #, vote)
	//vector<vector<int> > friends;
	//vector<vector<pair<int, int> > > posts;
	vector<int> post_nums;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);

		bool found = false;
		for (int j = 0; j < post_nums.size(); j++) {
			if (post_nums[j] == y) {
				found = true;
				break;
			}
		}
		if (!found) {
			post_nums.push_back(y);
		}

		posts[x].push_back(make_pair(y, z));
	}

	int u, t;
	scanf("%d %d", &u, &t);

	map<int, int> s;  // Post # - votes

	for (int i = 0; i < friends[u].size(); i++) {
		for (int j = 0; j < posts[friends[u][i]].size(); j++) {
			s[posts[friends[u][i]][j].first] += posts[friends[u][i]][j].second;
		}
	}

	for (int i = 0; i < post_nums.size(); i++) {
		if (s[post_nums[i]] >= t) {
			printf("%d\n", post_nums[i]);
		}
	}

	return 0;
}
