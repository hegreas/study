#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int testdir(const char *path)
{
    struct dirent *ent = NULL;
	DIR *pDir;
	pDir = opendir(path);

	while(NULL != (ent = readdir(pDir))) {
//		if(ent->d_reclen == 24) {
			if(ent->d_type == 8) {
				printf("regular file : %s\n", ent->d_name);
			} else {
				printf("child dir : %s\n", ent->d_name);
//				testdir(ent->d_name);
			}
//		}
	}
}

int main(int argc, char **argv)
{
	const char *path = "/home/chehongfeng/";
    testdir(path);
}
