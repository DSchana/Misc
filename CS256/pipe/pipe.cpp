#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
	pid_t pid;
	int fd[2];  // I/O Channles
		    // 0 - Read to pipe
		    // 1 - Write from pipe

	if (pipe(fd) == -1) {
		exit(1);
	}

	if ((pid = fork()) == 0) {  // Child
		close(fd[0]);

		char msg[] = "Hello from child process\n";
		write(fd[1], msg, strlen(msg));
	}
	else {  // Parent
		close(fd[1]);

		char ch = '0';
		printf("Reading: ");

		while (ch != '\n') {
			read(fd[0], &ch, 1);
			printf("%c", ch);
		}
	}

	return 0;
}
