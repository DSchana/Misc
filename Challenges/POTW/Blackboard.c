#include <stdio.h>

struct map {
	int k;
	int v[20];
	
};
typedef struct map Map;

int main() {
	int c, n;
	scanf("%d\n%d", &c, &n);

	Map c_map[20];
	int map_size[20];

	for (int i = 0; i < 20; i++) {
		map_size[i] = 0;
	}

	int index[999];  // Index in c_map
	int visit[999];

	// Setup graph
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		if (map_size[index[a]] == 0) {
			index[a] = i;
		}

		visit[a] = 0;

		c_map[index[a]].k = a;  // Set key
		c_map[index[a]].v[map_size[index[a]]] = b;  // Add value
		map_size[index[a]]++;  // Increment mapped size
	}

	return 0;
}
