#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

void callBack(int sig);

int main() {
	pid_t pid_1, pid_2;
	char* buf1 = "EXAM! EXAM! EXAM!\n";
	char* buf2 = "HELP! HELP! HELP!\n";
	char* buf3 = "STUDY! STUDY! STUDY!\n";

	signal(SIGUSR1, callBack);
	signal(SIGUSR2, callBack);

	int f = open("exam", O_WRONLY | O_CREAT | O_TRUNC, 0755);

	if ((pid_1 = fork()) > 0) {
		printf("Parent created child: %d\n", pid_1);

		// Second child
		if ((pid_2 = fork()) > 0) {
			printf("Parent created child: %d\n", pid_2);
		}
		else {
			pause();
			printf("Child 2 is writing to file: %s\n", buf2);
			//lseek(f, sizeof(buf1) + 1, SEEK_SET);
			write(f, buf2, 18);
			sleep(5);

			kill(getppid(), SIGUSR2);
			//exit(SIGUSR2);
		}
	}
	else {
		printf("Child 1 is writing to file: %s\n", buf1);
		//lseek(f, 0, SEEK_SET);
		write(f, buf1, 18);
		sleep(5);

		kill(getppid(), SIGUSR1);
		//exit(SIGUSR1);
	}

	pause();
	kill(pid_2, SIGUSR2);

	pause();
	printf("Parent is writing to file: %s\n", buf3);
	//lseek(f, sizeof(buf1) + sizeof(buf2) + 1, SEEK_SET);
	write(f, buf3, 21);
	sleep(5);

	close(f);	

	return 0;
}

void callBack(int sig) {
	if (sig == SIGUSR1) {
		printf("Go child\n");
	}
	else if (sig == SIGUSR2) {
		printf("Go parent\n");
	}
}
