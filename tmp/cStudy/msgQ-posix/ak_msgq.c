#include <mqueue.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/* ������Ϣ���� */
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

/* ������Ϣ�������� */
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

/* ��ȡ��Ϣ�������� */
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

/* ����Ϣ�����з�����Ϣ */
int ak_msgq_send(mqd_t mqId, char* buf, int size)
{
    int result;
    
    /* �����Ϣ�����Ƿ���� */

    /* ��鷢�ͻ���ָ���Ƿ�Ϊ�� */
    if(NULL == buf) {
        //ak_print_error("Send msg-->msgQ failed!\n");
        printf("Send msg-->msgQ failed!\n");
    }

    /* ������Ϣ */
    result = mq_send(mqId, buf, size, 0);

    return result;
}

/* ����Ϣ�����н�����Ϣ */
int ak_msgq_recv(mqd_t mqId, char* buf, int size)
{
    int result;
    
    /* �����Ϣ�����Ƿ���� */

    /* ��鷢�ͻ���ָ���Ƿ�Ϊ�� */
    if(NULL == buf) {
        //ak_print_error("Receive data from msgQ failed!\n");
        printf("Receive data from msgQ failed!\n");
    }

    /* ������Ϣ */
    result = mq_receive(mqId, buf, size, NULL);

    return result;
}

/* ������Ϣ���� */
int ak_msgq_destroy(const char* mqName)
{
    int result;

    /* �����Ϣ�����Ƿ���� */

    /* ������Ϣ���� */
    result = mq_unlink(mqName);

    return result;
}

