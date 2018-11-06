#include <stdio.h>

int main(int argc, char** argv)
{
    FILE* fp;

    if(argc < 2) {
		return -1;
	}

    int a = atoi(argv[1]);

	printf("%s, %s\n", argv[0], argv[1]);

	fp = fopen("test.txt", "w");

	fwrite(argv[1], 1, 1, fp);

	fclose(fp);
}
