#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int fact(int n);

int main(int arg_c, char* arg_v[]) {
	if (arg_c == 1) return -1;

	int n = atoi(arg_v[1]);
	if (n < 1 || n > 10) {
		printf("1 to 10\n");
		return -1;
	}

	int s = sizeof(arg_v[1]) / sizeof(char);
	printf("%s\n", arg_v[1]);

	int n_file = open("data.dat", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	write(n_file, arg_v[1], s);
	close(n_file);

	int status = 0;
	pid_t wpid;
	fork();

	if ((wpid = wait(&status)) > 0) {
		int fd = open("data.dat", O_RDONLY, 0777);
		int num;
		char* num_c = (char*)malloc(s);
		read(fd, num_c, s);
		num = atoi(num_c);

		printf("%d\n", fact(num));
	}

	return 0;
}

int fact(int n) {
	int a = 1;

	for (int i = 1; i <= n; i++) {
		a *= i;
	}

	return a;
}
