#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <fcntl.h>
#include <unistd.h>

#define PORT 8000

int main() {
	int sockfd, newsockfd, n;
	socklen_t cli_addr_len;
	char buf[256];
	struct sockaddr_in serv_addr, cli_addr;

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0) < 0))
		perror("ERROR opening socket");

	bzero((char*) &serv_addr, sizeof(serv_addr));  // Reset server address

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	serv_addr.sin_addr.s_addr = INADDR_ANY;

	if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
		perror("ERROR on binding");

	listen(sockfd, 5);

	cli_addr_len = sizeof(cli_addr);

	while (1) {
		if ((newsockfd = accept(sockfd, (struct sockaddr*) &cli_addr, &cli_addr_len)) < 0)
			perror("ERROR on accept");

		bzero(buf, 256);
		if ((n = read(newsockfd, buf, 255)) < 0)
			perror("ERROR reading from socket");

		printf("MESSAGE: %s\n", buf);

		if ((n = write(newsockfd, "msg received", 18)) < 0)
			perror("ERROR writing to client");
	}

	return 0;
}
