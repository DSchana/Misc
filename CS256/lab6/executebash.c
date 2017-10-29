#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
	int pid, s;

	pid = fork();
	if (pid == 0) {
		sleep(1);
		execlp("bash", "bash", "study.sh", (char*)0);
	}
	if (pid > 0) {
		execlp("echo", "echo", "EXAM! EXAM! EXAM!", (char*)0);
		wait(&s);
	}

	return 0;
}
