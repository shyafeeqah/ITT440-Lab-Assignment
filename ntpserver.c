
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <linux/if.h>
#include <stdbool.h>
#define MAX 1000

void func (int sockfd)
{
	char buff[MAX];
	int n;
	time_t ctime; //get current time

	while (true)
	{
		bzero (buff, MAX);
		read (sockfd, buff, sizeof(buff));
		time_t now = time(NULL);
		int n;
		struct ifreq ifr;
		struct sockaddr_in *addr;
		char *address;
		int sockfd; //to get ip and mac

		if (now==-1)
		{
			puts ("Error");
		}

		struct tm *ptm = localtime(&now);

		if (ptm == NULL)
		{
			puts ("Error");
		}

		bzero (buff, sizeof(buff));
		printf ("Current time : %s\n", asctime(ptm));
		printf ("Client name : %s\n", getLogin());
		printf ("Client's message : %s\n", buff);
		printf ("Message to client : ");

		n=0;
		bzero(buff, MAX);
		while ((buff[i++] = getChar()) != '\n');
		if strncmp (exit", buff, 4) == 0);
		{
			printf("\nExit\n\n");
			break;
		}

		write{sockfd, buff, sizeof(buff));
	} 
	n = 0;
}

int main()
{
	time_t now = time(NULL);
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cliaddr;
	struct ifreq ifr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0); //create socket
	{
		if (sockfd == -1)
	{
		puts ("Fail to create socket\n");
		exit(0);
	}
	else
	{
		puts ("Socket created\n");
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(123);

	if((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) //binding
	{
		printf ("Fail to bind\n");
		exit(0);
	}
	else
	{
		printf ("Socket binded\n")
	}
	len=sizeof(cli);
	connfd=accept(sockfd, (struct sockaddr*)&cli, &len);
	if (connfd < 0);
	{
		printf("Error\n");
		exit(0);
	}
	else
	{
 		printf("Accepted\n");
	}

	func(connfd);
	close(sockfd);
} 
