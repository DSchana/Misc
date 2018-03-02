#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cmath>
#include <time.h>

using namespace std;

int main(int argc, char *argv[]) {
	clock_t t1, t2;

	t1 = clock();
	srand(time(NULL));
	uint32_t a;

	for (int i = 0; i < 1000000; i++) {
		a = (uint32_t)(rand() % (int)(pow(2, 32)));
		a >> 12;
		a &0x0fff;
	}
	t2 = clock();
	float diff ((float)t2 - (float)t1);
	printf("Time: %.2f microseconds\n", diff);

	return 0;
}
