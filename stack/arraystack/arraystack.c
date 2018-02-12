#include "arraystack.h"
#include "printmacro.h"
#include <stdlib.h>
#include <string.h>

static int IsArrayStackEmpty(PArrayStack pstack)
{
	return ( 0 == pstack->len );
}

static int IsArrayStackFull(PArrayStack pstack)
{
	return ( pstack->size <= pstack->len );
}

PArrayStack CreateArrayStack(const unsigned long size)
{
	PArrayStack pstack = (PArrayStack)malloc(sizeof(ArrayStack));
	memset(pstack,0,sizeof(pstack));
	pstack->len = 0;
	pstack->size = size;
	pstack->data = (DataType *)malloc(sizeof(DataType)*pstack->size);
	memset(pstack->data,0,sizeof(DataType)*pstack->size);
	return pstack;
}

int FreeArrayStack(PArrayStack pstack)
{
	memset(pstack->data,0,sizeof(DataType)*pstack->size);
	free(pstack->data);
	memset(pstack,0,sizeof(pstack));
	free(pstack);
}

int PushArrayStack(PArrayStack pstack,const DataType data)
{
	if ( IsArrayStackFull(pstack) )
	{
		MYPRINT("ArrayStack is Full\n");
		return -1;
	}
	else
	{
		memcpy(pstack->data+pstack->len,&data,sizeof(data));
		pstack->len += 1;
		return 0;
	}
}

int PopArrayStack(PArrayStack pstack,DataType *data)
{
	if ( IsArrayStackEmpty(pstack) )
	{
		MYPRINT("ArrayStack is Empty\n");
		return -1;
	}
	else
	{
		pstack->len -= 1;
		memcpy(data,pstack->data+pstack->len,sizeof(data));
		return 0;
	}
}

#if ARRAY_TEST
void PrintArrayStack(PArrayStack pstack)
{
	printf("*****************************\n");
	MYPRINT("pstack len:%d\n",pstack->len);
	MYPRINT("pstack size:%d\n",pstack->size);
	int i;
	for ( i = 0 ; i < pstack->size ; i++ )
	{
		printf("%d ",pstack->data[i]);
	}
	printf("\n");
	printf("*****************************\n");
}

void ArrayStackTest()
{
	int size = 10;
	PArrayStack pstack = CreateArrayStack(size);
	int i = 0;
	int j = 0;
	for ( i = 0 ; i < 12 ; i++ )
	{
		PushArrayStack(pstack,i+1);
		PrintArrayStack(pstack);
	}
	for ( i = 0 ; i < 3 ; i++ )
	{
		PopArrayStack(pstack,&j);
		printf("j = %d\n",j);
	}
	for ( i = 0 ; i < 5 ; i++ )
	{
		PushArrayStack(pstack,i);
		PrintArrayStack(pstack);
	}
	for ( i = 0 ; i < size + 3 ; i++ )
	{
		PopArrayStack(pstack,&j);
		printf("j = %d\n",j);
	}
	FreeArrayStack(pstack);
}
#endif
