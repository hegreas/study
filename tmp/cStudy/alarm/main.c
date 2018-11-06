#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sig_alarm()
{
	printf("alarm alarm alarm...\n");
	exit(0);
}

int main(int argc, char** argv)
{
	signal(SIGALRM, sig_alarm);
	alarm(10);
	sleep(15);
	printf("Hello world!\n");
	return 0;
}
