#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>


int main(int argc, char *argv[])
{
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr;

	char sendbuff[255];


	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&serv_addr, '0', sizeof(serv_addr));
	memset(sendbuff, '0', sizeof(sendbuff));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(5000);


	bind(listenfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));


	listen(listenfd, 10);

	connfd = accept(listenfd, (struct sockaddr*) NULL, NULL );

	while(1)
	{
		printf("message from serv to client");
		scanf("%s", sendbuff);
		write(connfd, sendbuff,strlen(sendbuff));
	}

	

	return 0;
}