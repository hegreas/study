#ifndef AK_NET_H
#define AK_NET_H

struct net_mgr_cbs {
	char* eth_start;
}

int ak_net_init(struct net_mgr_cbs net_cbs); 

int ak_net_eth_start(const char* iface);

#endif
