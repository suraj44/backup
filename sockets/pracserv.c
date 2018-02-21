#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080

int main(int argc, char const *argv[])
{
	int servfd, newfd, valread;
	struct socketaddr_in address;
	int addrlen = sizeof(address);
	char buffer[256] = {0};
	char hello[20];

	if(servfd =  socket(AF_INET, SOCK_STREAM,0)<0)
	{
		perror("socket not initialised\n");
		exit(1);
	}



	return 0;
}