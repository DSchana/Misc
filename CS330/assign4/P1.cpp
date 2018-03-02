#include <cstdio>
#include <cstdlib>
#include <cstdint>

using namespace std;

int main(int argc, char *argv[]) {
	uint32_t a = (uint32_t)atoi(argv[1]);

	printf("The address %d contains:\n",a);
	printf("Page number = %d\n", a >> 12);
	printf("Offset = %d", a &0x0fff);


	return 0;
}
