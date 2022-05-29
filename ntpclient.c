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
	time_t ctime; 

	while (true)
	{
		bzero (buff, MAX);
		read (sockfd, buff, sizeof(buff));
		time_t now = time(NULL);
		int n;
		struct ifreq ifr;
		struct sockaddr_in *addr;
		char *address;
		int sockfd;

		if (now ==-1)
		{
			puts ("Error");
		}

		struct tm *ptm = localtime(&now);

		if (ptm == NULL)
		{
			puts ("Error");
		}

		bzero(buff, sizeof(buff));
		printf ("Message : ");
		n=0;
		bzero(buff, MAX);
		while ((buff[i++] = getChar()) != '\n')
		{
			if (strncmp("exit", buff, 4) == 0)
			{
				printf ("\nExit\n\n");
				break;
				}
		}
		write(sockfd, buff, sizeof(buff));
		read{sockfd, buff, sizeof(buff));
		printf ("Current time : %s\n", asctime(ptm));
		printf ("Server name : %s\n", getLogin());
		printf ("Server's message : %s\n", buff);
	}
	n = 0;
}

int main()
{
	time_t now = time(NULL);
	int sockfd, connfd;
	struct sockaddr_in servaddr, cliaddr;
	struct ifreq ifr;

	sockfd = socket(AF_INET, SOCK_STEAM, 0);
	if (sockfd == -1)
	{
		printf("Fail to create socket\n");
		exit(0);
	}
	else
	{
		printf("Socket created\n");
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("192.168.0.119");
	servaddr.sin_port = htons(123);

	if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) //to connect socket
	{
		printf("Fail to connect\n");
		exit(0);
	}
	else
	{
		printf("Connected\n");
	}

	func(sockfd);
	close(sockfd);
}
