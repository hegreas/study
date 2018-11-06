#include <signal.h>
#include <unistd.h>

#define EXIT_SUCCESS 0

int main(int argc, char** argv)
{
	signal(SIGHUP, SIG_IGN);
	signal(SIGCHLD, SIG_IGN);

	int a, max_fd, i;

	a = fork();
	if(a>0)
		exit(EXIT_SUCCESS);

	setsid();
	a = fork();
	if(a>0)
		exit(EXIT_SUCCESS);

	setpgrp();

	max_fd = sysconf(_SC_OPEN_MAX);

	for(i=3; i<max_fd; i++)
		close(i);

	umask(0);
	chdir("/");

	while(1)
	{
		sleep(2);
		printf("test program...\n");
	}
}
