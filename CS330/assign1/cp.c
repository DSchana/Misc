#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int arg_c, char** arg_v) {
	int f1, f2, file_size;
	struct stat file_stat;
	char* buff;

	if (arg_c != 3) {
		printf("Usage: cp src dst\n");
		return -1;
	}

	if ((f1 = open(arg_v[1], O_RDONLY)) < 0)
		perror("File 1 did not open\n");

	if ((f2 = open(arg_v[2], O_WRONLY | O_CREAT, 0755)) < 0)
		perror("File 2 did not open\n");

	fstat(f1, &file_stat);
	file_size = file_stat.st_size;

	buff = (char*)malloc(file_size);
	read(f1, buff, file_size);
	write(f2, buff, file_size);

	free(buff);

	close(f1);
	close(f2);

	return 0;
}
