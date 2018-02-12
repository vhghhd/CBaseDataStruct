#ifndef __ARRAY_LIST__
#define __ARRAY_LIST__

#define TEST_ARRAYLIST 1
#define GET_ARRAY_SIZE(n) (1<<n)
typedef int DataType;

typedef struct ARRAYLIST {
	DataType *data;
	unsigned int front;
	unsigned int rear;
	unsigned int size;
}ArrayList,*PArrayList;

PArrayList CreateArrayList(unsigned int size);
int FreeArrayList(PArrayList plist);

int EnArrayList(PArrayList plist,DataType data);
int DeArrayList(PArrayList plist,DataType *data);

#if TEST_ARRAYLIST
void TestArrayList();
#endif
#endif
