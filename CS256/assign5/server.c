/*
 * Title:	server.c
 * Author:	Dilpreet S. Chana
 * Description:	Server code
**/

#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h> 
#include <stdlib.h>
#include <signal.h> 
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
	char buf[100];

	int sd, client, pid;
	socklen_t len;
	struct sockaddr_in servAdd;
	struct sockaddr_in cliAdd;

	sd = socket(AF_INET, SOCK_STREAM, 0);
	servAdd.sin_family = AF_INET;
	servAdd.sin_addr.s_addr = INADDR_ANY;
	servAdd.sin_port = 5555;

	bind(sd, (struct sockaddr*)&servAdd, sizeof(servAdd));
	listen(sd, 5);

	while(1){
		printf("Waiting for connection...\n");
		len = sizeof(cliAdd);
		client = accept(sd, (struct sockaddr*)&cliAdd, &len);
		printf("Connected\n");
		memset(buf, 0, 100);
		while(read(client, buf, 100) > 0){
			printf("Receieved command: %s\n", buf);

			if((pid = fork()) == 0){
				dup2(client, STDOUT_FILENO);	// 10,000 IQ Plays
				execlp(buf, buf, (char*)0);
			}




			memset(buf, 0, 100);
		}

	}
}
