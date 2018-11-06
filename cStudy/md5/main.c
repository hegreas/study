#include "md5c.h"

void main(int argc, char** argv)
{
    unsigned char digest[16];  //存放结果

	if(2 != argc) {
        printf("usage : md5 [text]\n");
		return;
	}
		   
    MDString(argv[1],digest); //直接输入字符串并得出结果
	for(int i=0; i<5; i++) {
		printf("%02x", digest[i]);
	}
	printf("\n");
}
