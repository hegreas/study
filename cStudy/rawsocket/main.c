#include <sys/types.h>
#include <sys/socket.h>
#include <linux/if_ether.h>

#define MAX_RECV_BUFFER 2048
#define NULL (void*)0

int main(int argc, char **argv)
{
    int socket_fd;
	char recv_buffer[MAX_RECV_BUFFER];

	socket_fd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));

	if(socket_fd < 0) {
		printf("socket alloc failed %d\n", socket_fd);
		perror("socket");
		return -1;
	}

	int recv_num = recvfrom(socket_fd, recv_buffer, MAX_RECV_BUFFER, 0, NULL, NULL);

	for(int i=0; i<recv_num; i++) {
		printf("0x%02x, ", recv_buffer[i]);

		if((i+1)%10 == 0) {
            printf("\n");
		}

	}

	return 0;
}
