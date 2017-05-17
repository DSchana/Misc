#include <cstdio>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		int h, w;
		int curr_x = -1;
		int curr_y = -1;
		scanf("%d %d", &h, &w);

		char[h][w] map;

		// Generate map and identify start loc.
		for (int j = 0; j < h; j++) {
			scanf("%s", map[j]);
			if (curr_x == -1) {
				for (int k = 0; k < w; k++) {
					if (map[j][k] == 'F') {
						curr_x = k;
						curr_y = h;
					}
				}
			}
		}
	}

	return 0;
}
