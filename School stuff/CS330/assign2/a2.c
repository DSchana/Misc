/*
 * Title:	a2.c
 * Author:	Dilpreet S. Chana
 * Description: Create zombie process. Kill any parents of
 *		zombie process.
**/

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	pid_t pid;

	// Parent
	if ((pid = fork()) > 0) {
		sleep(10);
		printf("10 seconds later... what is my child??\n");

		// Another child
		if ((pid = fork()) == 0) {
			execlp("ps", "ps", "-l", (char*)NULL);
		}

		sleep(1);
		printf("My child is a zombie\n");
		pause();
	}
	else {  // Child
		exit(0);
	}

	return 0;
}
