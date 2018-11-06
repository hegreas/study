#include <mqueue.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/* 创建消息队列 */
mqd_t ak_msgq_create(const char* mqName, struct mq_attr* pMqAttr)
{
    mqd_t mqID;

    mqID = mq_open(mqName, O_RDWR | O_CREAT | O_EXCL, 0666, pMqAttr);

    if(mqID < 0) {
        if(errno == EEXIST) {
            mq_unlink(mqName);
            mqID = mq_open(mqName, O_RDWR | O_CREAT, 0666, pMqAttr);
        } else {
            //ak_print_error("Open message queue error, %s\n", strerror(errno));
            printf("Open message queue error, %s\n", strerror(errno));
        }
    }

    return mqID;
}

/* 设置消息队列属性 */
int ak_msgq_setattr(mqd_t mqId, struct mq_attr* pMqAttr)
{
    if(NULL == pMqAttr) {
        //ak_print_error("Set msgQ attr failed!\n");
        printf("Set msgQ attr failed!\n");
        //return AK_FAILED;
		return -1;
    }

    mq_setattr(mqId, pMqAttr, NULL);

    //return AK_SUCCESS;
    return 0;
}

/* 获取消息队列属性 */
int ak_msgq_getattr(mqd_t mqId, struct mq_attr* pMqAttr)
{
    if(NULL == pMqAttr) {
        //ak_print_error("Get msgQ attr failed!\n");
        printf("Get msgQ attr failed!\n");
        //return AK_FAILED;
		return -1;
    }

    mq_getattr(mqId, pMqAttr);

    //return AK_SUCCESS;
	return 0;
}

/* 向消息队列中发送消息 */
int ak_msgq_send(mqd_t mqId, char* buf, int size)
{
    int result;
    
    /* 检查消息队列是否存在 */

    /* 检查发送缓存指针是否为空 */
    if(NULL == buf) {
        //ak_print_error("Send msg-->msgQ failed!\n");
        printf("Send msg-->msgQ failed!\n");
    }

    /* 发送消息 */
    result = mq_send(mqId, buf, size, 0);

    return result;
}

/* 从消息队列中接收消息 */
int ak_msgq_recv(mqd_t mqId, char* buf, int size)
{
    int result;
    
    /* 检查消息队列是否存在 */

    /* 检查发送缓存指针是否为空 */
    if(NULL == buf) {
        //ak_print_error("Receive data from msgQ failed!\n");
        printf("Receive data from msgQ failed!\n");
    }

    /* 接收消息 */
    result = mq_receive(mqId, buf, size, NULL);

    return result;
}

/* 销毁消息队列 */
int ak_msgq_destroy(const char* mqName)
{
    int result;

    /* 检查消息队列是否存在 */

    /* 销毁消息队列 */
    result = mq_unlink(mqName);

    return result;
}

