#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>

void ak_timer_init(timer_t* timeid, int time_val, int sig, void*sigHandler);
void ak_timer_destroy(timer_t* timerid);
void SignHandler(int iSignNo);
void printTime();
int exitflag = 1;
timer_t a_timer;

int main(){
	ak_timer_init(&a_timer, 30, SIGUSR1, SignHandler);
//	while(exitflag) {
	while(1) {
		sleep(1);
		static int i = 0;
		i++;
		if(i>30) {
			printf("now delete timer...\n");
			timer_delete(a_timer);
			a_timer = NULL;
			exit(0);
		}
		//ak_timer_destroy(a_timer);
	}

	return 0;
}

void SignHandler(int iSignNo) {
	printTime();
	if(iSignNo == SIGUSR1) {
		printf("Capture sign No.=SIGUSR1\n");
    } else {
		printf("Capture sign NO.=%d\n", iSignNo);
	}

//	ak_timer_destroy(a_timer);

	exitflag = 0;
}

void ak_timer_init(timer_t* timeid, int time_val, int sig, void* sigHandler) {
	printf("Timer init, time_val = %d, sig = %d\n", time_val, sig);
	struct sigevent evp;
	struct itimerspec ts;

	int ret;
	evp.sigev_value.sival_ptr = timeid;
	evp.sigev_notify = SIGEV_SIGNAL;
	evp.sigev_signo = sig;
    signal(evp.sigev_signo, sigHandler);
	//evp.sigev_signo = SIGUSR1;
	//signal(evp.sigev_signo, SignHandler);

	ret = timer_create(CLOCK_REALTIME, &evp, timeid);
	if(ret) {
		perror("timer_create");
	}

	ts.it_interval.tv_sec = 10;
	ts.it_interval.tv_nsec = 0;
	ts.it_value.tv_sec = 10;
	ts.it_value.tv_nsec = 0;
	printTime();
	printf("start\n");
	ret = timer_settime(*timeid, 0, &ts, NULL);
	if(ret) {
		perror("timer_settime");
	}
}

void ak_timer_destroy(timer_t* timerid) {
    printf("Destroy timer...\n");
    timer_delete(*timerid);

    printf("Destroy timer success...\n");
}


void printTime() {
	struct tm *cursystem;
	time_t tm_t;
	time(&tm_t);
	cursystem = localtime(&tm_t);
	char tszInfo[2048];
	sprintf(tszInfo, "%02d:%02d:%02d", cursystem->tm_hour, cursystem->tm_min, cursystem->tm_sec);
	printf("[%s]", tszInfo);
}
