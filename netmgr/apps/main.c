#include "ak_net.h"

int main(int argc, char** argv)
{
	char* eth_start = "eth_start.sh";
    struct net_mgr_cbs net_cbs;
	net_cbs.eth_start = eth_start;

	
    /* 初始化net模块，注册回调 */
	ak_net_init(&net_cbs);

	/* 启动有线网络 */
	ak_net_eth_start("eth0");

}
