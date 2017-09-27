#include<unistd.h>
#include<fcntl.h>
#include <stdio.h>

int main(void){

	int num = 101;

	int fd = open("list1.txt", O_RDWR,0777);
	
	lseek(fd, 0, SEEK_SET);
	write(fd, &num, 3);

	close(fd);

	return 0;
}
