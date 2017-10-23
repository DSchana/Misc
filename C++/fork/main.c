#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t pid = fork();  // returns 0 in child and child id in parent

	if (pid == 0) {  // This is the child
		printf("Child\n");
	}
	else if (pid > 0) {
		printf("Parent\n");
	}

	printf("End\n");

	return 0;
}
