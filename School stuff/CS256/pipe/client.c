#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
	int fd;
	char ch, fifo_name[100];
	pid_t pid;

	if ((fd = open("/tmp/t_server", O_WRONLY) == -1)) {
		perror("Fifo open");
		exit(1);
	}

	pid = getpid();
	write(fd, &pid, sizeof(pid_t));
	close(fd);

	sprintf(fifo_name, "/tmp/fifo%d", pid);
	sleep(1);

	fd = open(fifo_name, O_RDONLY);
	while (read(fd, &ch, 1) == 1) {
		printf("%c", ch);
	}

	close(fd);

	/*
	while ((fd = open("/tmp/t_server", O_WRONLY)) == -1) {
		printf("Connecting...\n");
		sleep(1);
	}

	printf("Connected. Sending data...\n");
	while ((ch = getchar()) != -1)
		write(fd, &ch, 1);

	close(fd);
	*/

	return 0;
}
