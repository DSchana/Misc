#include<unistd.h>
#include<fcntl.h>

int main(void){
	int num=101;
	char s1[45]="GM\t101   Buick\t2010\nFord\t102   Lincoln\t2005\n";
	int fd = creat("list2.txt",0777);

	write(fd, s1, 44);

	lseek(fd,3,SEEK_SET);
	write(fd, &num, 3);

	close(fd);

	return 0;
}
