#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main(void)
{
	struct timeval tv;
	time_t time;
	long time_usec;
	char str_t[26] = {0};
	struct tm* p_time;
    while(1) {
		gettimeofday(&tv, NULL);
	
		time = tv.tv_sec;
		time_usec = tv.tv_usec;
	
		p_time = localtime(&time);
		strftime(str_t, 26, "%Y-%m-%d %H:%M:%S", p_time);
	
		printf("%s %03ld\n", str_t, time_usec/1000);
		usleep(1000*1000);
	}

	return 0;
}
