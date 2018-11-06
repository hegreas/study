#include <stdio.h>
#include <unistd.h>

#include "ak_msgq.h"

int main(int argc, char** argv)
{
	mqd_t mqId;
	const char* mqName = "/testmq";

	struct mq_attr mqAttr;
	mqAttr.mq_maxmsg = 10;
	mqAttr.mq_msgsize = 1024*100;

	/* 创建消息队列 */
    mqId = ak_msgq_create(mqName, &mqAttr);

	/* 检查创建队列的结果 */
	if(-1 == mqId) {
		printf("Create mq failed! mqName = %s\n", mqName);
		return -1;
	}

	/* 获取消息队列的属性并输出 */
	ak_msgq_getattr(mqId, &mqAttr);
	printf("mq_flags = %ld\n", mqAttr.mq_flags);
	printf("mq_maxmsg = %ld\n", mqAttr.mq_maxmsg);
	printf("mq_msgsize = %ld\n", mqAttr.mq_msgsize);
	printf("mq_curmsgs = %ld\n", mqAttr.mq_curmsgs);

	/* 创建子进程 */
	char buf[8192];
	if(fork() == 0) {
        for(int i=0; i<20; i++) {
            /* 从消息队列接收数据 */
		    ak_msgq_recv(mqId, buf, mqAttr.mq_msgsize);
			printf("Receive msg, i = %d\n", i);
		}
	}

	/* 发送数据到消息队列 */
	char msg[] = "hello!";
	for(int i=0; i<20; i++) {
		/* 发送消息 */
	    ak_msgq_send(mqId, msg, mqAttr.mq_msgsize);
		printf("Send msg, i = %d\n", i);
	}	

	return 0;
}
