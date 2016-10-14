#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

struct Point {
	int x, y;
	int d;
};

int getDistance(Point p1, Point p2) {
	return abs(hypot(abs(int(p1.x) - int(p2.x)), abs(int(p1.y) - int(p2.y))));
}

void sortAndWrite(Point A[], int n, int toFind) {
	int k = 0;
	// Set to max value in array
	for (int i = 0; i < n; i++) {
		if (A[i].d > k) {
			k = A[i].d;
		}
	}

	Point count[k + 1];
	Point output[k + 1];

	for (int i = 0; i < k + 1; i++) {
		count[i].d = 0;
	}

	// Histogram for each key
	for (int i = 0; i < n; i++) {
		count[A[i].d].d += 1;
	}

	int total = 0;
	for (int i = 0; i < k + 1; i++) {
		int oldCount = count[i].d;
		count[i].d = total;
		total += oldCount;
	}

	for (int i = 0; i < n; i++) {
		output[count[A[i].d].d] = A[i];
		count[A[i].d].d += 1;
	}

	for (int i = 0; i < toFind; i++) {
		printf("%d %d\n", output[i].x, output[i].y);
	}
}

int main() {
	Point will_loc;
	int K, N;  // K-num of gurls to find; N-num of gurls

	scanf("%d %d", &will_loc.x, &will_loc.y);
	scanf("%d", &K);
	scanf("%d", &N);

	// Populate dem_gurlz
	Point dem_gurlz[N];
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &dem_gurlz[i].x, &dem_gurlz[i].y);
		dem_gurlz[i].d = getDistance(will_loc, dem_gurlz[i]);  // Get distance from william
	}

	sortAndWrite(dem_gurlz, N, K);

	return 0;
}
