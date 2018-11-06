#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void usage()
{
    printf("help...\n");
}

int main(int argc, char** argv)
{
    printf("Have %d parameter...\n", argc);

	for(int i=0; i<argc; i++) {
		printf("parameter %d : %s\n", i, argv[i]);
	}

	int para;
	char* para_value;

    if(argc < 2) {
        usage();
	}

	int times, gop, dura;
	while(-1 != (para = getopt(argc, argv, ":i:t:c:"))) {
		switch(para) {
        case 'i':
			printf("Get i parameter, value = %s\n", optarg);
			times = atoi(optarg);
			printf("times = %d\n", times);
		    break;
		case 't':
			printf("Get t parameter, value = %s\n", optarg);
			gop = atoi(optarg);
			printf("gop = %d\n", gop);
		    break;
		case 'c':
			printf("Get c parameter, value = %s\n", optarg);
			dura = atoi(optarg);
			printf("dura = %d\n", dura);
		    break;
		case ':':
			printf("%s : -%c must have a value\n", argv[0], optopt);
			break;
		default:
			printf("Can't support %c parameter...\n", para);
		    break;
		}
	}
}
