#include <unistd.h>

int main(int argc, char **argv)
{
    if(0 == access("/sys/class/net/wlan0", F_OK)) {
        printf("Wifi node existed!\n");
	} else {
		printf("Wifi node not existed!\n");
	}
}
