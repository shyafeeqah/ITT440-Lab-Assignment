#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

void sig_handler(int sig){

	if (sig ==  SIGINT)
		printf("This is a special signal handler for SIGINT");
	else if (sig == SIGTSTP)
		printf("This is a special signal handler for SIGTSTP");
	else if (sig == SIGQUIT)
		printf("This is a special signal handler for SIGQUIT");
}
int main(void){
	if (signal(SIGINT, sig_handler)==SIG_ERR)
		printf("No signal received.");
	if (signal(SIGTSTP, sig_handler)==SIG_ERR)
		printf("No signal received.");
	if (signal(SIGQUIT, sig_handler)==SIG_ERR)
		printf("No signal received.");

	return 0;
}
