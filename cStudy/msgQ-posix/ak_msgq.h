#ifndef AK_MSGQ_H
#define AK_MSGQ_H

#include <mqueue.h>

/* 创建消息队列 */
mqd_t ak_msgq_create(const char* mqName, struct mq_attr* pMqAttr);

/* 设置消息队列属性 */
int ak_msgq_setattr(mqd_t mqId, struct mq_attr* pMqAttr);

/* 获取消息队列属性 */
int ak_msgq_getattr(mqd_t mqId, struct mq_attr* pMqAttr);

/* 向消息队列中发送消息 */
int ak_msgq_send(mqd_t mqId, char* buf, int size);

/* 从消息队列中接收消息 */
int ak_msgq_recv(mqd_t mqId, char* buf, int size);

/* 销毁消息队列 */
int ak_msgq_destroy(const char* mqName);

#endif

/* end of file */
