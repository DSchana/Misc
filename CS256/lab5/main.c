#include <stdio.h>
#include <unistd.h>

int main(int arg_c, char **arg_v) {
	pid_t p1 = fork();

	// Second fork in parent only
	if (p1 > 0) {
		pid_t p2 = fork();
	}

	return 0;
}
