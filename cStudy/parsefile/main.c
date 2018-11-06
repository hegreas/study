#include <unistd.h>

#include "ak_update_packet_pro.h"

#define RING_UPDATE_PKG "/home/chehongfeng/ring_update.pkg"

int main(int argc, char **argv)
{
    int fd;

    if(0 != access(RING_UPDATE_PKG, F_OK)) {
        printf("File not existed! filename : %s\n", RING_UPDATE_PKG);
		perror("access");
		return -1;
    }

	fd = open(RING_UPDATE_PKG);
	if(-1 == fd) {
        perror("open");
		return -1;
	}

	update_file_t file_des;

	if(sizeof(update_file_t) == read(fd, &file_des, sizeof(update_file_t))) {
        printf("file_des.magic : %s\n", file_des.magic);
		printf("file_des.version : %s\n", file_des.version);
		printf("date:%d,%d,%d,%d:%d:%d, zone:%d\n", file_des.date.year, file_des.date.month, file_des.date.day, file_des.date.hour, file_des.date.minute, file_des.date.second, file_des.date.timezone);
    }
}
