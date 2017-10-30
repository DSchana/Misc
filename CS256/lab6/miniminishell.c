#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int arg_c, char** arg_v) {
	int pid, s;

	// Execute all but the last command
	for (int i = 1; i < arg_c - 1; i += 2) {
		pid = fork();
		if (pid == 0) {
			execlp(arg_v[i], arg_v[i], arg_v[i + 1], (char*)0);
			exit(0);
		}
		else if (pid > 0) {
			wait(&s);
		}
	}

	pid = fork();
	if (pid == 0) {
		if (arg_c % 2 == 0) {  // Last command has no parameter
			execlp(arg_v[arg_c - 1], arg_v[arg_c - 1], (char*)0);
		}
		else {  // Last command has parameter
			execlp(arg_v[arg_c - 2], arg_v[arg_c - 2], arg_v[arg_c - 1], (char*)0);
		}

		exit(0);
	}
	else if (pid > 0) {
		wait(&s);
	}

	// Last command
	

	return 0;
}
