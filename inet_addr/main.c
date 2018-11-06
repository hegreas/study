#include <arpa/inet.h>

int main(int argc, char **argv)
{
	long int l_ip;
	char* new_ip;
    char test_ip[] = "192.168.123.1";

	l_ip = inet_addr(test_ip);

	long int  new_ip_int = l_ip ^ (1 << 16);
	long int new_ip_router = new_ip_int & 0xffffff;
	new_ip_router = new_ip_router | 0x14000000;
	struct in_addr test_tt;
	test_tt.s_addr = new_ip_int;

	new_ip = inet_ntoa(test_tt);

	test_tt.s_addr = new_ip_router;

	char *new_mask = inet_ntoa(test_tt);

	//printf("%s, %s\n", test_ip, inet_ntoa(new_ip_int));
	printf("%d, %d, %s, %s, %s, %p, %p\n", l_ip, new_ip_int, test_ip, new_ip, new_mask, new_ip, new_mask);

    return 0;
}
