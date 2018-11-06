#include <stdlib.h>

int main(int argc, char** argv)
{
    char* command = "lls -l | grep main";

	int result = system(command);

	printf("size of command : %d, result = %d\n", sizeof(command), result);

	return 0;
}
