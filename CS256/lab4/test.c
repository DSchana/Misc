#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	fork();
	fork();
	fork();
	printf("%d\n", getppid());

	return 0;
}
