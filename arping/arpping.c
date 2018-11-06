#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/if_ether.h>
#include <net/if_arp.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

#define MAC_BCAST_ADDR (uint8_t *) "\xff\xff\xff\xff\xff\xff"

struct arpMsg {
    struct ethhdr ethhdr;
	uint16_t htype;
	uint16_t ptype;
	uint8_t hlen;
	uint8_t plen;
	uint16_t operation;
	uint8_t sHaddr[6];
	uint8_t sInaddr[4];
	uint8_t tHaddr[6];
	uint8_t tInaddr[4];
	uint8_t pad[18];
}ATTRIBUTE_PACKED;

int arpping_by_time(u_int32_t yiaddr, u_int32_t ip, unsigned char *mac, char *interface,int sec, int usec)
{
    int     timeout = usec;         // we need to reduce time
    int     optval = 1;
    int     s;                      /* socket */
    int     rv = 1;                 /* return value */
    struct sockaddr addr;           /* for interface name */
    struct arpMsg   arp;
    fd_set          fdset;
    struct timeval  tm;
    time_t          prevTime;
    struct in_addr ipaddr;  // add by honor
    
    if ((s = socket (PF_PACKET, SOCK_PACKET, htons(ETH_P_ARP))) == -1) {
        fprintf(stderr,"Could not open raw socket\n");
        return -1;
    }
    
    if (setsockopt(s, SOL_SOCKET, SO_BROADCAST, &optval, sizeof(optval)) == -1) {
        fprintf(stderr, "Could not setsocketopt on raw socket\n");
        close(s);
        return -1;
    }
    
    /* send arp request */
    memset(&arp, 0, sizeof(arp));
    memcpy(arp.ethhdr.h_dest, MAC_BCAST_ADDR, 6);   /* MAC DA */
    memcpy(arp.ethhdr.h_source, mac, 6);            /* MAC SA */
    arp.ethhdr.h_proto = htons(ETH_P_ARP);          /* protocol type (Ethernet) */
    arp.htype = htons(ARPHRD_ETHER);                /* hardware type */
    arp.ptype = htons(ETH_P_IP);                    /* protocol type (ARP message) */
    arp.hlen = 6;                                   /* hardware address length */
    arp.plen = 4;                                   /* protocol address length */
    arp.operation = htons(ARPOP_REQUEST);           /* ARP op code */
    *((u_int *) arp.sInaddr) = ip;                  /* source IP address */
    memcpy(arp.sHaddr, mac, 6);                     /* source hardware address */
    //*((u_int *) arp.tInaddr) = yiaddr;              /* target IP address */
    memcpy(arp.tInaddr, &yiaddr, 4);
    
    memset(&addr, 0, sizeof(addr));
    strcpy(addr.sa_data, interface);
    if (sendto(s, &arp, sizeof(arp), 0, &addr, sizeof(addr)) < 0)
        rv = 0;
    
    /* wait arp reply, and check it */
    tm.tv_sec = sec;
    time(&prevTime);
    FD_ZERO(&fdset);
    FD_SET(s, &fdset);
    tm.tv_usec = timeout;
    
    int i;
    while (1) {
        if (select(s + 1, &fdset, (fd_set *) NULL, (fd_set *) NULL, &tm) < 0) {
            fprintf(stderr, "Error on ARPING request: [%s] !", strerror(errno));
            if (errno != EINTR) rv = 0;
        } else if (FD_ISSET(s, &fdset)) {
            memset(&arp, 0, sizeof(struct arpMsg));
            if (recv(s, &arp, sizeof(arp), 0) < 0 ) rv = 0;

            if (arp.operation == htons(ARPOP_REPLY) &&
                bcmp(arp.tHaddr, mac, 6) == 0 &&
                *((u_int *) arp.sInaddr) == yiaddr) {
            
                fprintf(stderr,"Valid arp reply receved for this address\n");
                rv = 0;
            } else {
            	continue;
            }
        }
        break;
    }
    close(s);
    ipaddr.s_addr = yiaddr; // add by honor
    fprintf(stderr,"%salid arp replies for this address (%s)\n", rv ? "No v" : "V", inet_ntoa(ipaddr));    // modify by michael
    return rv;
}

int main(int argc, char** argv)
{
	char ip_src[20];
	char ip_dst[20];
	gets(ip_src);
	gets(ip_dst);
    int yiaddr = inet_addr(ip_dst);
	int ip = inet_addr(ip_src);
	unsigned char mac[6] = {0xEA, 0xC0, 0x1E, 0x49, 0x97, 0x4D};
	char* interface = "eth0";
	int sec = 3;
	int usec = 0;
    arpping_by_time(yiaddr, ip, mac, interface, sec, usec);
}

/* end of file */
