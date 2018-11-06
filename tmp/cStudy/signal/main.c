#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

static void pr_mask(const char* string) {
	sigset_t procmask;

	sigprocmask(SIG_SETMASK, NULL, &procmask);

	printf("%s: ", string);
	if(sigismember(&procmask, SIGINT))
		printf("SIGINT");
	if(sigismember(&procmask, SIGUSR1))
		printf("SIGUSR1");
	if(sigismember(&procmask, SIGUSR2))
		printf("SIGUSR2");
	if(sigismember(&procmask, SIGTERM))
		printf("SIGTERM");
	if(sigismember(&procmask, SIGQUIT))
		printf("SIGQUIT");
	printf("\n");
}

static void sigusr(int signum)
{
    pr_mask("int sigusr");

	if(signum == SIGUSR1)
		printf("SIGUSR1 received\n");
	else if(signum == SIGUSR2)
		printf("SIGUSR2 received\n");
	else
		printf("signal %d received\n", signum);
}

int main(void)
{
	if(signal(SIGUSR1, sigusr) == SIG_ERR) {
		printf("error catching SIGUSR1\n");
		exit(1);
	}

	if(signal(SIGUSR2, SIG_IGN) == SIG_ERR) {
		printf("error ignoring SIGUSR2\n");
		exit(1);
	}

	if(signal(SIGINT, SIG_DFL) == SIG_ERR) {
		printf("error setting SIGINT to default\n");
		exit(1);
	}

	while(1)
		pause();

	exit(0);
}
