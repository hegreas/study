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
	char* teststring[3] = {"hello", "world", "everyone"};

	shmid = shmget(0x2234, sizeof(Teacher), IPC_CREAT | 0666);
	if(shmid == -1)
	{
		perror("shmget err");
		return errno;
	}

	printf("shmid:%d \n", shmid);
	Teacher *p = NULL;

	p = shmat(shmid, NULL, 0);
	if(p == (void*) -1)
	{
		perror("shmget err");
		return errno;
	}
    
	for(unsigned char i=0; i<80000; i++) {
	    sleep(1);
	    strcpy(p->name, teststring[i%3]);
	    p->age = i%33;
	}

	shmdt(p);

	printf("input 1 to delete share memory!\n");

	int num;
	scanf("%d", &num);
	if(num == 1)
	{
		ret = shmctl(shmid, IPC_RMID, NULL);
		if(ret < 0)
		{
			perror("rmerr\n");
		}
	}

	return 0;
}
