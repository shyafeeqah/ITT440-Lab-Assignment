#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main (void){
	for(int i=1; i<5; i++){
		pid_t pid = fork();
		char name[20];

		if (pid == 0){
			printf("What is your name?");
			scanf("%s", name);
    			printf("Your name is %s\n", name);
			exit(0);
		}

		else{
			printf("Waiting for child processes to finish...\n");
			wait (NULL);
			printf("Job is done.\n");
		}
	}
	return EXIT_SUCCESS;
}
