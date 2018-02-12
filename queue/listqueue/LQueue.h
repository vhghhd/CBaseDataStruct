#ifndef __QUEUE_LIST__
#define __QUEUE_LIST__

//#include "list.h"

typedef struct LISTQUEUEDATA {
	char * lqdata;
	int datasize;
	struct LISTQUEUEDATA * next;
}LQueueData,*PLQueueData;

typedef struct LISTQUEUE {
	PLQueueData front;
	PLQueueData rear;
#define MAX_QUEUE_SIZE 200
	int size;
}LQueue,*PLQueue;

int CreateLQueue(PLQueue pqueue);
int EmptyLQueue(PLQueue pqueue);
int EnLQueue(PLQueue pqueue,char *data,int datasize);
int DnLQueue(PLQueue pqueue,char *data,int datasize);
void FreeLQueue(PLQueue pqueue);
void TestListQueue(PLQueue pqueue);

#endif
