#include <stdlib.h>
#include <dirent.h>

int main(void)
{
    struct dirent **entry_list;

	int count;
	int i;

	count = scandir("/home/chehongfeng/project", &entry_list, 0, alphasort);

	if(count < 0) {
		perror("scandir");
		return EXIT_FAILURE;
	}

	for(i=0; i<count; i++) {
		struct dirent *entry;

		entry = entry_list[i];
		printf("%s\n", entry->d_name);
		free(entry);
	}

	free(entry_list);

	return 0;
}
