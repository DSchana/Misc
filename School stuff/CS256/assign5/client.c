/*
 * Title:	client.c
 * Author:	Dilpreet S. Chana
 * Description:	Client code
**/

#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 
#include <stdlib.h>
#include <signal.h> 
#include <sys/stat.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]){
	char buf[100], in[100];
	int server, pid;
	socklen_t len;
	struct sockaddr_in servAdd;

	server = socket(AF_INET, SOCK_STREAM, 0);
	servAdd.sin_family = AF_INET;
	servAdd.sin_addr.s_addr = inet_addr(argv[1]);
	servAdd.sin_port = 5555;

	if((pid = fork()) == 0){
		while(1){
			if(read(server, in, 100) == 0){
				kill(getppid(), SIGTERM);
				exit(0);
			}
		}
	}
	else{
		while(1){
			connect(server, (struct sockaddr*)&servAdd, sizeof(servAdd));
			printf("\nEnter shell command: ");
			scanf("%s", buf);

			write(server, buf, strlen(buf) + 1);
			read(server, in, 100);
			printf("%s", in);

			memset(in, 0, 100);
		}
	}
}
