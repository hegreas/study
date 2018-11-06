#include "ak_net.h"

struct net_mgr_cbs g_net_cbs;

int ak_net_init(struct net_mgr_cbs net_cbs) 
{
    strcpy();
}

static int cmd_call(const char* cmd, const char* para1, ...)
{
    /* 拼装命令 */
    sprintf();

	/* 调用命令 */
	system();
}

int ak_net_eth_start(const char* iface)
{
    cmd_call(g_net_cbs.eth_start, iface);  
}

