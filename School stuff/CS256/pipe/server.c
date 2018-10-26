#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

void child(pid_t pid);

int main() {
	int fd, stat;
	char ch;
	pid_t pid;

	unlink("/tmp/t_server");
	if (mkfifo("/tmp/t_server", 0777) != 0) exit(1);

	while (1) {
		printf("Waiting for client...\n");
		fd = open("/tmp/t_server", O_RDONLY);

		read(fd, &pid, sizeof(pid_t));
		close(fd);
		sleep(1);

		printf("Client with pid: %d\n", pid);

		if (fork() == 0) {
			child(pid);
		}
		else {
			waitpid(0, &stat, WNOHANG);
		}
	}

	/*
	printf("ServerrrUP, Trying to connect...\n");
	fd = open("/tmp/t_server", O_RDONLY);

	printf("Connection established. Awaiting data...\n");
	while (read(fd, &ch, 1) == 1)
		printf("%c", ch);

	close(fd);
	*/

	return 0;
}

void child(pid_t pid) {
	char fifo_name[100];
	char n = '\n';
	int fd;

	sprintf(fifo_name, "/tmp/fifo%d", pid);
	unlink(fifo_name);
	mkfifo(fifo_name, 0777);

	fd = open(fifo_name, O_WRONLY);
	for (int i = 1; i < 10; i++) {
		write(fd, fifo_name, strlen(fifo_name));
		write(fd, &n, 1);
		sleep(1);
	}

	close(fd);
	unlink(fifo_name);
	exit(0);
}
