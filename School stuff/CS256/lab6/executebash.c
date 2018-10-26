#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
	int pid, s;

	write(1, "EXAM! EXAM! EXAM!\n", sizeof("EXAM! EXAM! EXAM!\n"));

	pid = fork();
	if (pid == 0) {
		execlp("bash", "bash", "study.sh", (char*)0);
	}
	else if (pid > 0) {
		wait(&s);
	}

	return 0;
}
