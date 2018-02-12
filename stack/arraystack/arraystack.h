#ifndef __ARRAY_STACK__
#define __ARRAY_STACK__

#define ARRAY_TEST 1

typedef int DataType;

typedef struct ARRAYSTACK {
	DataType *data;
	unsigned int len;
	unsigned int size;
}ArrayStack,*PArrayStack;

PArrayStack CreateArrayStack(const unsigned long size);
int FreeArrayStack(PArrayStack pstack);

int PushArrayStack(PArrayStack pstack,const DataType data);
int PopArrayStack(PArrayStack pstack,DataType *data);

#if ARRAY_TEST
void ArrayStackTest();
#endif
#endif
