#include <fcntl.h>
#include <stdlib.h>
#include <sys/signal.h>
#include <sys/stat.h>
#include <unistd.h>

void callBack() {}

int main() {
	int fd;
	int n = 98;

	while ((fd = open("fifo.fifo", O_WRONLY)) == -1) sleep(1);

	write(fd, &n, 4);
	signal(SIGUSR1, callBack);

	pause();
	close(fd);

	return 0;
}
