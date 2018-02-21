#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char const *argv[])
{
	int sockfd, portno, clilen, pid;
	struct sockaddr_in serv_addr,cli_addr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	portno =  atoi(argv[1]);

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr =INADDR_ANY;
	serv_addr.sin_port = htons(portno);


	bind(sockfd, (struct sockaddr*) &serv_addr,sizeof(serv_addr));

	listen(sockfd, 5);

	clilen = sizeof(cli_addr);

	while(1)
	{
		int n;
		char buffer[256];
		bzero(buffer,256);

		n = read(sockfd, buffer,255);
		printf("Here's the message: %s\n", buffer);

		bzero(buffer,256);
		fgets(buffer,255,stdin);

		write(sockfd, buffer, strlen(buffer));


	}
	

	return 0;
	
}