#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

int main(void){

	void sig_handler(int sig);

	if (signal(SIGINT, sig_handler) == SIG_ERR){
		perror("no signal received");
		exit(1);
	}
	 if(signal(SIGTSTP, sig_handler) == SIG_ERR){
		perror("no signal received");
		exit(1);
	}
	if (signal(SIGQUIT, sig_handler) == SIG_ERR){
		perror("no signal received");
		exit(1);
	}
	return 0;
}
void sig_handler(int sig){

	if (sig ==  SIGINT)
		printf("This is a special signal handler for SIGINT");
	if (sig == SIGTSTP)
		printf("This is a special signal handler for SIGTSTP");
	if (sig == SIGQUIT)
		printf("This is a special signal handler for SIGQUIT");
}
