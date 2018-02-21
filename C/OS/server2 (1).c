/* A simple server in the internet domain using TCP
   The port number is passed as an argument 
   This version runs forever, forking off a separate 
   process for each connection
   gcc server2.c -lsocket
*/
#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void dostuff(int); /* function prototype */
void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
     int sockfd, newsockfd, portno, clilen, pid;
     struct sockaddr_in serv_addr, cli_addr;
     int n;
    char buffer[256];

     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     sockfd = socket(AF_INET, SOCK_DGRAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");

     // /listen(sockfd,5);
     clilen = sizeof(cli_addr);
     /*newsockfd = accept(sockfd, 
               (struct sockaddr *) &cli_addr, &clilen);
     if (newsockfd < 0) 
             error("ERROR on accept");
      */   
     while (1) {
         
          
      
   bzero(buffer,256);
   
   //n = read(sock,buffer,255);
   recvfrom(sockfd,buffer, sizeof(buffer), 0, (struct sockaddr *) &cli_addr, &clilen);

   
   printf("Here is the message: %s\n",buffer);
   bzero(buffer,256);
   fgets(buffer,255,stdin);
   
   n = sendto(sockfd,buffer,strlen(buffer),0,(struct sockaddr *) &cli_addr, clilen);
   //n = sendto(sockfd,"I got your message",18, 0,);
    }
     return 0; 
}

