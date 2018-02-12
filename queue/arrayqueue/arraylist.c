#include "arraylist.h"
#include "printmacro.h"
#include <stdlib.h>
#include <string.h>

static int IsArrayListEmpty(PArrayList plist)
{
	return ( plist->front == plist->rear );
}

static int IsArrayListFull(PArrayList plist)
{
	return ( plist->front == ( ( plist->rear + 1 ) & ( plist->size - 1 ) ) );
}

PArrayList CreateArrayList(const unsigned int size)
{
	PArrayList plist = (PArrayList)malloc(sizeof(ArrayList));
	memset(plist,0,sizeof(plist));
	plist->front = 0;
	plist->rear = 0;
	plist->size = GET_ARRAY_SIZE(size);
	plist->data = (DataType *)malloc(sizeof(DataType)*plist->size);
	return plist;
}

int FreeArrayList(PArrayList plist)
{
	memset(plist->data,0,sizeof(DataType)*plist->size);
	free(plist->data);
	memset(plist,0,sizeof(plist));
	free(plist);
}

int EnArrayList(PArrayList plist,const DataType data)
{
	if ( IsArrayListFull(plist) )
	{
		MYPRINT("ArrayList is Full\n");
		return -1;
	}
	else
	{
		memcpy(plist->data+plist->rear,&data,sizeof(data));
		plist->rear = ( plist->rear + 1 ) & ( plist->size - 1 );
		return 0;
	}
}

int DeArrayList(PArrayList plist,DataType *data)
{
	if ( IsArrayListEmpty(plist) )
	{
		MYPRINT("ArrayList is Empty\n");
		return -1;
	}
	else
	{
		memcpy(data,plist->data+plist->front ,sizeof(data));
		plist->front = ( plist->front + 1 ) & ( plist->size - 1 );
		return 0;
	}
}

#if TEST_ARRAYLIST
static void PrintArrayList(PArrayList plist)
{
	printf("*******************************\n");
	MYPRINT("plist size:%d\n",plist->size);
	MYPRINT("plist front:%d\n",plist->front);
	MYPRINT("plist rear:%d\n",plist->rear);
	printf("*******************************\n");
}

void TestArrayList()
{
	int size = 2;
	PArrayList plist = CreateArrayList(size);

	int i = 0;
	int j = 0;
	for ( i = 0 ; i < 8 ; i++ )
	{
		EnArrayList(plist,i);
		PrintArrayList(plist);
	}
	for ( i = 0 ; i < 5 ; i++ )
	{
		DeArrayList(plist,&j);
		PrintArrayList(plist);
		printf("j=%d\n",j);
	}
	for ( i = 0 ; i < 8 ; i++ )
	{
		EnArrayList(plist,i);
		PrintArrayList(plist);
	}
	FreeArrayList(plist);
}
#endif
