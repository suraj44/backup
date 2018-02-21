#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
void error(char *msg)
{
	perror(msg);
	exit(1);
}

int main(int argc, char const *argv[])
{
	int sockfd, portno, n;

	struct sockaddr_in serv_addr;
	struct hostent *server;

	char buffer[256];
	if(argc<3)
	{
		fprintf(stderr, "usage %d hostname port\n", argv[0]);

		exit(1);
	}

	portno = atoi(argv[2]);
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	server = gethostbyname(argv[1]);

	serv_addr.sin_family =  AF_INET;
	serv_addr.sin_port = htons(portno);

	while(1)
	{
		printf("Please enter a message: ");
		bzero(buffer,256);
		fgets(buffer,255,stdin);
		n = sendto(sockfd,buffer,strlen(buffer),0,(struct sockaddr *)&serv_addr,sizeof(serv_addr));

		bzero(buffer,256);

		n = recv(sockfd, buffer, 255,0);
		if(n<0)
			error("error\n");
		printf("%s\n",buffer);
	}



	return 0;
}