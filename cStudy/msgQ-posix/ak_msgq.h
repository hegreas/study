#ifndef AK_MSGQ_H
#define AK_MSGQ_H

#include <mqueue.h>

/* ������Ϣ���� */
mqd_t ak_msgq_create(const char* mqName, struct mq_attr* pMqAttr);

/* ������Ϣ�������� */
int ak_msgq_setattr(mqd_t mqId, struct mq_attr* pMqAttr);

/* ��ȡ��Ϣ�������� */
int ak_msgq_getattr(mqd_t mqId, struct mq_attr* pMqAttr);

/* ����Ϣ�����з�����Ϣ */
int ak_msgq_send(mqd_t mqId, char* buf, int size);

/* ����Ϣ�����н�����Ϣ */
int ak_msgq_recv(mqd_t mqId, char* buf, int size);

/* ������Ϣ���� */
int ak_msgq_destroy(const char* mqName);

#endif

/* end of file */
