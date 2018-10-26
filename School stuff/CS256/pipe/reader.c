#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/signal.h>
#include <sys/stat.h>
#include <unistd.h>

void callBack(int d) {}

int main() {
	int fd;
	int n;

	unlink("fifo.fifo");
	if (mkfifo("fifo.fifo", 0777) != 0) exit(1);

	fd = open("fifo.fifo", O_RDONLY);
	signal(SIGUSR1, callBack);

	pause();
	read(fd, &n, 4);
	close(fd);
	unlink("fifo.fifo");

	return 0;
}
