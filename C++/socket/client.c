#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define PORT 8000

int main() {
	const char* HOST = "localhost";
	int sockfd, n;
	struct sockaddr_in serv_addr;
	struct hostent* server;
	char buf[256] = "Here is my message";

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		perror("ERROR opening socket");

	if ((server = gethostbyaddr(HOST, sizeof(HOST), AF_INET)) == NULL) {
		perror("ERROR no such host");
		exit(0);
	}

	bzero((char*) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char*)server->h_addr, (char*)&serv_addr.sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(PORT);

	if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
		perror("ERROR connecting");

	if ((n = write(sockfd, buf, strlen(buf))) < 0)
		perror("ERROR writing to socket");

	bzero(buf, 256);
	if ((n = read(sockfd, buf, 255)) < 0)
		perror("ERROR reading from socket");

	printf("MESSAGE: %s\n", buf);

	return 0;
}
