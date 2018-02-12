#ifndef __MY_SORT__
#define __MY_SORT__

#define MYSORT_TEST 1

typedef int SortDataType;

typedef int ( *CmpFun )(SortDataType * ,const unsigned int ,const unsigned int ,const unsigned int );

typedef int ( *SortFun )(SortDataType *,CmpFun,const unsigned int ,const unsigned int ,const unsigned int ,const unsigned char);

typedef struct MYSORTFUNS {
#define BUBBLE_SORT        0
#define COCKTAIL_SORT      1

#define SELECTION_SORT     2

#define INSERTION_SORT     3
#define BINARY_INSERT_SORT 4
#define SHELL_SORT		   5

#define MERGE_SORT		   6

#define HEAP_SORT		   7

#define QUICK_SORT         8
#define MY_SORT_FUNS_NUM   9
	SortFun sfun[MY_SORT_FUNS_NUM];
#define UP_MODE   1
#define DOWN_MODE 2
}MySortFun,*PMySortFun;


int Bubble_Sort(SortDataType *Array,CmpFun cmp,const unsigned int len,const unsigned int start,const unsigned int end,const unsigned char Mode);
int CockTail_Sort(SortDataType *Array,CmpFun cmp,const unsigned int len,const unsigned int start,const unsigned int end,const unsigned char Mode);
int Selection_Sort(SortDataType *Array,CmpFun cmp,const unsigned int len,const unsigned int start,const unsigned int end,const unsigned char Mode);
int Insertion_Sort(SortDataType *Array,CmpFun cmp,const unsigned int len,const unsigned int start,const unsigned int end,const unsigned char Mode);
int Binary_Insertion_Sort(SortDataType *Array,CmpFun cmp,const unsigned int len,const unsigned int start,const unsigned int end,const unsigned char Mode);
int Shell_Sort(SortDataType *Array,CmpFun cmp,const unsigned int len,const unsigned int start,const unsigned int end,const unsigned char Mode);
int Merge_Sort(SortDataType *Array,CmpFun cmp,const unsigned int len,const unsigned int start,const unsigned int end,const unsigned char Mode);
int Heap_Sort(SortDataType *Array,CmpFun cmp,const unsigned int len,const unsigned int start,const unsigned int end,const unsigned char Mode);
int Quick_Sort(SortDataType *Array,CmpFun cmp,const unsigned int len,const unsigned int start,const unsigned int end,const unsigned char Mode);

PMySortFun CreateMySortFuns();

#if MYSORT_TEST
void TestMySort();
#endif
#endif
