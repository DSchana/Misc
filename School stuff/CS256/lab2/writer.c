#include<fcntl.h>
#include<unistd.h>

int main(void){
	char s1[45]="101   GM\tBuick\t2010\n102   Ford\tLincoln\t2005\n";
	int fd = creat("list1.txt",0777);

	write(fd, s1, 44);

	close(fd);

	return 0;    
}
