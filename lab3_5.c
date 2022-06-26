#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int getNum(){
	int inputNum;
	fgets(inputNum);
	return inputNum;
}

int main(void){
	int fd[2];
	pipe(fd);
	pid_t pid=fork();
	int count=2;

	if(pid==0){
		close(1);
		close(fd[0]);
		dup(fd[1]);

		int num = getNum();
		write(fd[1], &num, sizeof(num));
	}
	else if (pid>0){
		close(0);
		close(fd[1]);
		dup (fd[0]);

		printf("Enter a number\n");
		scanf("%d", num);
		if(num%count==0){
			 printf("%d is not a prime number\n", num);
		}
		else{
			printf ("%d is a prime number\n", num);
		}
	}
	return EXIT_SUCCESS;
}
