#include "LQueue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int IsLQueueEmpty(PLQueue pqueue)
{
	return ( pqueue->size == 0 );
}

static int IsLQueueFull(PLQueue pqueue)
{
	return ( MAX_QUEUE_SIZE <= pqueue->size )
}

int CreateLQueue(PLQueue pqueue)
{
	memset(pqueue,0,sizeof(LQueue));
	pqueue->size = 0;
	pqueue->front = NULL;
	pqueue->rear = NULL;
	return 0;
}

int EnLQueue(PLQueue pqueue,char *data,int datasize)
{
	int ret = 0;
	PLQueueData qdata = (PLQueueData)malloc(sizeof(LQueueData));
	if ( datasize == 0 )
	{
		printf("datasize cannot be zero\n");
		return -1;
	}
	if ( qdata == NULL )
	{
		printf("LQueueData malloc error\n");
		return -1;
	}
	if ( IsLQueueFull(pqueue) )
	{
		printf("LQueueData out of the range %d\n",pqueue->size);
		char datatmp[datasize];
		DnLQueue(pqueue,datatmp,datasize);
		ret = -2;
	}
	memset(qdata,0,sizeof(LQueueData));
	qdata->lqdata = (char *)malloc(datasize);
	if ( qdata->lqdata == NULL )
	{
		printf("LQueueData data malloc error\n");
		return -1;
	}
	memset(qdata->lqdata,0,sizeof(datasize));
	qdata->datasize = datasize;
	memcpy(qdata->lqdata,data,qdata->datasize);
	qdata->next = NULL;
	
	if ( IsLQueueEmpty(pqueue) )
	{
		pqueue->front = qdata;
		pqueue->rear = qdata;
	}
	else
	{
		pqueue->rear->next = qdata;
		pqueue->rear = qdata;;
	}
	pqueue->size += 1;
	//printf("En size:%d\n",pqueue->size);
	return ret;
}

int DnLQueue(PLQueue pqueue,char *data,int datasize)
{
	if ( IsLQueueEmpty(pqueue) )
	{
		//printf("LQueue Empty\n");
		return -1;
	}
	else
	{
		if ( datasize < pqueue->front->datasize )
		{
			printf("datasize is too small\n");
			return -1;
		}
		else
		{
			PLQueueData pqueuetmp;
			memcpy(data,pqueue->front->lqdata,pqueue->front->datasize);
			free(pqueue->front->lqdata);
			pqueue->front->lqdata = NULL;

			pqueuetmp = pqueue->front;
			pqueue->front = pqueue->front->next;
			free(pqueuetmp);
			pqueue->size -= 1;
		}
	}
	//printf("Dn size:%d\n",pqueue->size);
	return 0;
}

void FreeLQueue(PLQueue pqueue)
{
	PLQueueData pqueuedatatmp;
	if ( ! IsLQueueEmpty(pqueue) )
	{
		do {
			pqueuedatatmp = pqueue->front;
			pqueue->front = pqueue->front->next;
			free(pqueuedatatmp->lqdata);
			free(pqueuedatatmp);
		}while(pqueue->front);
	}
	return ;
}

void TestListQueue(PLQueue pqueue)
{
	PLQueueData pqueuedatatmp = pqueue->front;
	PLQueueData pqueuedatatmp2;
	int type = 0;
	do {
		pqueuedatatmp2 = pqueuedatatmp->next;
		memcpy(&type,pqueuedatatmp->lqdata,sizeof(type));
		//printf("type:%d\n",type);
		pqueuedatatmp = pqueuedatatmp2;
	}while(pqueuedatatmp);
	return ;
}

