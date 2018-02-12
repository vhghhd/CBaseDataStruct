#include "mysort.h"
#include "printmacro.h"
#include <stdlib.h>
#include <string.h>

static JudgeParam(const unsigned int len,const unsigned int start,const unsigned int end)
{
	if ( start > end || end > len )
	{
		MYPRINT("please check the param : start <= end <= len\n");
		return -1;
	}
	else
	{
		return 0;
	}
}

#define CHECK_MODE(mode,x1,x2) ((mode)==UP_MODE) ? ((x1) < (x2)) : ((x1) > (x2))
void Swap(SortDataType *Array,int first,int second)
{
	SortDataType temp = Array[first];
	Array[first] = Array[second];
	Array[second] = temp;
}

int Bubble_Sort(SortDataType *Array,CmpFun cmp,const unsigned int len,const unsigned int start,const unsigned int end,const unsigned char Mode)
{
	int ret = 0;
	if ( ( ret = JudgeParam(len,start,end) ) == 0 )
	{
		int i,j;
		for ( i = start ; i < end - 1 ; i++ )
		{
			for ( j = i + 1 ; j < end; j++ )
			{
				if ( cmp == NULL )
				{
					if ( CHECK_MODE(Mode,Array[j],Array[i]) )
					{
						Swap(Array,i,j);
					}
				}
				else
				{
					if ( cmp(Array,Mode,j,i) )
					{
						Swap(Array,i,j);
					}
				}
			}
		}
	}
	return ret;
}

int CockTail_Sort(SortDataType *Array,CmpFun cmp,const unsigned int len,const unsigned int start,const unsigned int end,const unsigned char Mode)
{
	int ret = 0;
	if ( ( ret = JudgeParam(len,start,end) ) == 0 )
	{
		int left = start;
		int right = end - 1;
		while ( left < right )
		{
			int i,j;
			for ( i = left ; i < right ; i++ )
			{
				if ( cmp == NULL )
				{
					if ( CHECK_MODE(Mode,Array[i+1],Array[i]) )
					{
						Swap(Array,i+1,i);
					}
				}
				else
				{
					if ( cmp(Array,Mode,i+1,i) )
					{
						Swap(Array,i+1,i);
					}
				}
			}
			right -= 1;
			for ( i = right ; i > left ; i-- )
			{
				if ( cmp == NULL )
				{
					if ( CHECK_MODE(Mode,Array[i],Array[i-1]) )
					{
						Swap(Array,i-1,i);
					}
				}
				else
				{
					if ( cmp(Array,Mode,i,i-1) )
					{
						Swap(Array,i-1,i);
					}
				}
			}
			left += 1;
		}
	}
	return ret;
}

int Selection_Sort(SortDataType *Array,CmpFun cmp,const unsigned int len,const unsigned int start,const unsigned int end,const unsigned char Mode)
{
	int ret = 0;
	if ( ( ret = JudgeParam(len,start,end) ) == 0 )
	{
		int i = 0;
		for ( i = start ; i < end - 1 ; i++ )
		{
			int min = i;
			int j = 0 ;
			for ( j = i + 1 ; j < end ; j ++ )
			{
				if ( cmp == NULL )
				{
					if ( CHECK_MODE(Mode,Array[j],Array[min]) )
					{
						min = j;
					}
				}
				else
				{
					if ( cmp(Array,Mode,j,min) )
					{
						min = j;
					}
				}
				if ( min != i )
				{
					Swap(Array,min,i);
				}
			}
		}
	}
	return ret;
}

int Insertion_Sort(SortDataType *Array,CmpFun cmp,const unsigned int len,const unsigned int start,const unsigned int end,const unsigned char Mode)
{
	int ret = 0;
	if ( ( ret = JudgeParam(len,start,end) ) == 0 )
	{

	}
	return ret;
}

int Binary_Insertion_Sort(SortDataType *Array,CmpFun cmp,const unsigned int len,const unsigned int start,const unsigned int end,const unsigned char Mode)
{
	int ret = 0;
	if ( ( ret = JudgeParam(len,start,end) ) == 0 )
	{

	}
	return ret;
}

int Shell_Sort(SortDataType *Array,CmpFun cmp,const unsigned int len,const unsigned int start,const unsigned int end,const unsigned char Mode)
{
	int ret = 0;
	if ( ( ret = JudgeParam(len,start,end) ) == 0 )
	{

	}
	return ret;
}

int Merge_Sort(SortDataType *Array,CmpFun cmp,const unsigned int len,const unsigned int start,const unsigned int end,const unsigned char Mode)
{
	int ret = 0;
	if ( ( ret = JudgeParam(len,start,end) ) == 0 )
	{

	}
	return ret;
}

int Heap_Sort(SortDataType *Array,CmpFun cmp,const unsigned int len,const unsigned int start,const unsigned int end,const unsigned char Mode)
{
	int ret = 0;
	if ( ( ret = JudgeParam(len,start,end) ) == 0 )
	{

	}
	return ret;
}

int Quick_Sort(SortDataType *Array,CmpFun cmp,const unsigned int len,const unsigned int start,const unsigned int end,const unsigned char Mode)
{
	int ret = 0;
	if ( ( ret = JudgeParam(len,start,end) ) == 0 )
	{

	}
	return ret;
}

PMySortFun CreateMySortFuns()
{
	PMySortFun pmysortfun = (PMySortFun)malloc(sizeof(MySortFun)); 

	pmysortfun->sfun[BUBBLE_SORT] = Bubble_Sort;
	pmysortfun->sfun[COCKTAIL_SORT] = CockTail_Sort;
	pmysortfun->sfun[SELECTION_SORT] = Selection_Sort;
	pmysortfun->sfun[INSERTION_SORT] = Insertion_Sort;
	pmysortfun->sfun[BINARY_INSERT_SORT] = Binary_Insertion_Sort;
	pmysortfun->sfun[SHELL_SORT] = Shell_Sort;
	pmysortfun->sfun[MERGE_SORT] = Merge_Sort;
	pmysortfun->sfun[HEAP_SORT] = Heap_Sort;
	pmysortfun->sfun[QUICK_SORT] = Quick_Sort;

	return pmysortfun;
}

int FreeMySortFuns(PMySortFun pmysortfun)
{
	memset(pmysortfun,0,sizeof(MySortFun));
	free(pmysortfun);
}

#if MYSORT_TEST
int MyCmpFun(SortDataType * pdata,const unsigned int Mode,const unsigned int first,const unsigned int second)
{
	return 0;
}

void PrintData(SortDataType *pdata,const int len)
{
	int i;
	for ( i = 0 ; i < len ; i++ )
	{
		printf("%d ",pdata[i]);
	}
	printf("\n");
}

void TestMySort()
{
#define DATALEN 10
	SortDataType data[DATALEN] = {2,1,4,5,9,5,6,7,2,0};
	PMySortFun psortfuns = CreateMySortFuns();
	//psortfuns->sfun[BUBBLE_SORT](data,NULL,DATALEN,0,DATALEN,UP_MODE);
	psortfuns->sfun[COCKTAIL_SORT](data,NULL,DATALEN,0,DATALEN,UP_MODE);
	//psortfuns->sfun[SELECTION_SORT](data,NULL,DATALEN,0,DATALEN,UP_MODE);
	PrintData(data,DATALEN);
	//psortfuns->sfun[BUBBLE_SORT](data,NULL,DATALEN,0,DATALEN,DOWN_MODE);
	//psortfuns->sfun[COCKTAIL_SORT](data,NULL,DATALEN,0,DATALEN,DOWN_MODE);
	psortfuns->sfun[SELECTION_SORT](data,NULL,DATALEN,0,DATALEN,DOWN_MODE);
	PrintData(data,DATALEN);
}
#endif
