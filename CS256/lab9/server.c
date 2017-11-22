#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
	int fd1, fd2;
	pid_t pid;
	char ch;
	int add_space = 1;

	unlink("./fifo1");
	unlink("./fifo2");

	if (mkfifo("./fifo1", 0777) == -1 || mkfifo("./fifo2", 0777) == -1) {
		perror("fifo");
		exit(1);
	}

	while (1) {
		printf("Awaiting connection...\n");
		fd1 = open("./fifo1", O_RDONLY);
		fd2 = open("./fifo2", O_WRONLY);
		printf("Server \t Client\n");
		printf("-------\t-------");

		if ((pid = fork()) == 0) {
			while (1) {
				// Do something
			}

			while (read(fd1, &ch, 1) == 1) {
				if (add_space == 1) {
					write(1, "\t", 1);
				}
				write(1, &ch, 1);
				// Do shit
			}

			close(fd1);
			close(fd2);

			printf("Client left\n");
			kill(pid, SIGTERM);
		}
	}

	return 0;
}
