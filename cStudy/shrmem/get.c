#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <errno.h>

typedef struct _Teacher
{
	char name[64];
	int age;
}Teacher;

int main(int argc, char* argv[])
{
	int ret = 0;
	int shmid;

	shmid = shmget(0x2234, 0, 0);
	if(shmid == -1)
	{
		perror("shmget err");
		return errno;
	}

	printf("shmid:%d\n", shmid);
	Teacher *p = NULL;

	p = shmat(shmid, NULL, 0);
	if(p == (void*)-1)
	{
		perror("shmget err");
		return errno;
	}

	while(1) {
		sleep(1);
	    printf("name:%s\n", p->name);
	    printf("age:%d\n", p->age);
	}

	shmdt(p);

	printf("input 1 to stop program\n");

	int num;
	scanf("%d", &num);
	if(num == 1)
	{
		pause();
	}

	return 0;
}
