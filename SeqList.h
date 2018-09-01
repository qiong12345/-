#pragma once


typedef int DataType;
#define MAX_SIZE 10

typedef struct SeqList
{
	DataType _array[MAX_SIZE];
	int _size;   // ��ʾ˳�������ЧԪ�صĸ���
}SeqList, *PSeqList;

//typedef struct SeqList SeqList;
typedef struct SeqList* PSeqList;
/////////////////////////////////////////////////////////////////////
// SeqList.h

// ˳���ĳ�ʼ��
void SeqListInit(PSeqList ps);

// ˳����β��
void SeqListPushBack(PSeqList ps, DataType data);

// ˳����βɾ
void SeqListPopBack(PSeqList ps);

// ˳����ͷ��
void SeqListPushFront(PSeqList ps, DataType data);

// ˳����ͷɾ
void SeqListPopFront(PSeqList ps);

// ˳���posλ�ò���Ԫ��data
void SeqListInsert(PSeqList ps, int pos, DataType data);

// ɾ��˳���posλ��Ԫ��
void SeqListErase(PSeqList ps, int pos);

// �Ƴ�˳����е�һ��ֵΪdata��Ԫ��
void Remove(PSeqList ps, DataType data);

// �Ƴ�˳���������ֵΪdata��Ԫ��
void RemoveAll(PSeqList ps, DataType data);

// ��˳����в���ֵΪdata��Ԫ�أ��ҵ����ظ�Ԫ����˳����е�λ�ã����򷵻�-1
int SeqListFind(PSeqList ps, DataType data);

// ��ȡ˳�����Ԫ�صĸ���
int SeqListSize(PSeqList ps);



//////////////////////////////////////////////////
//��������
// ��ӡ˳���
void PrintSeqList(PSeqList ps);

// ʹ��ð�������˳����е�Ԫ�ؽ�������
void BubbleSort(PSeqList ps);

// ʹ��ѡ�������˳����е�Ԫ�ؽ�������
void SelectSort(PSeqList ps);









///////////////////////////////////////////////////////////////////
// SeqList.c
#include <stdio.h>
#include <assert.h>
void SeqListInit(PSeqList ps)
{
	if(ps)
		ps->_size = 0;
}

// 1. �������
// 2. �߽���������
// 3. �߼�����
void SeqListPushBack(PSeqList ps, DataType data)
{
#if 0
	if(NULL == ps)
		return;

	if(ps->_size == MAX_SIZE)
	{
		printf("˳�������!!!\n");
		return;
	}

	ps->_array[ps->_size++] = data;
	//ps->_size++;
#else
	if(NULL == ps)
		return;

	SeqListInsert(ps, ps->_size, data);
#endif
}

void SeqListPopBack(PSeqList ps)
{
#if 0
	if(NULL == ps)
		return;

	if(0 == ps->_size)
	{
		printf("˳����ѿ�!!!\n");
		return;
	}

	--ps->_size;
#else

	if(NULL == ps)
		return;

	SeqListErase(ps, ps->_size-1);
#endif
}

void SeqListPushFront(PSeqList ps, DataType data)
{
#if 0
	int i = 0;
	if(NULL == ps)
		return;

	// ���˳����Ƿ���
	if(MAX_SIZE == ps->_size)
	{
		printf("˳�������!!!\n");
		return;
	}

#if 0
	// ����Ԫ��
	for(i = ps->_size; i > 0; --i)
	{
		ps->_array[i] = ps->_array[i-1];
	}
#else

	// ����Ԫ��
	for(i = ps->_size-1; i >= 0; --i)
	{
		ps->_array[i+1] = ps->_array[i];
	}

#endif

	// ����Ԫ��
	ps->_array[0] = data;
	ps->_size++;
#else
	SeqListInsert(ps, 0, data);
#endif
}

void SeqListPopFront(PSeqList ps)
{
#if 0
	int i = 0;
	if(NULL == ps)
		return;

	if(0 == ps->_size)
	{
		printf("˳����ѿ�!!!\n");
		return;
	}

	// ����Ԫ��
	for(; i < ps->_size - 1; ++i)
	{
		ps->_array[i] = ps->_array[i+1];
	}

	ps->_size--;
#else

	SeqListErase(ps, 0);
#endif
}

void SeqListInsert(PSeqList ps, int pos, DataType data)
{
	int i = 0;
	// if((pos >= 0 && pos <= ps->_size) || NULL == ps)
	if(NULL == ps || !(pos >= 0 && pos <= ps->_size))
		return;

	if(MAX_SIZE == ps->_size)
	{
		printf("˳����������޷�����!!!\n");
		return;
	}

	for(i = ps->_size-1; i >= pos; --i)
		ps->_array[i+1] = ps->_array[i];

	ps->_array[pos] = data;
	ps->_size++;
}

void SeqListErase(PSeqList ps, int pos)
{
	int i = pos;
	if(NULL == ps || !(pos >= 0 && pos < ps->_size))
		return;

	if(0 == ps->_size)
	{
		printf("˳����ѿգ��޷�ɾ��!!!\n");
		return;
	}

	for(; pos < ps->_size-1; ++pos)
		ps->_array[pos] = ps->_array[pos+1];

	ps->_size--;
}

void Remove(PSeqList ps, DataType data)
{
	SeqListErase(ps, SeqListFind(ps, data));
}

void RemoveAll(PSeqList ps, DataType data)
{
	// 1. SeqListFind--SeqListErase==��O(N^2)
#if 0 
	int pos = 0;

	while(-1 != (pos = SeqListFind(ps, data)))
		SeqListErase(ps, pos);
#endif

	// 2.--->O(N)---�ռ临�Ӷȣ�O(N)
	// �����������飬����Ϊdata��Ԫ��ȫ���ŵ��¿ռ��У�
	// ���¿ռ��е�Ԫ�ؿ�����˳�����

	// 3
	int count = 0;
	int i = 0;
	for(; i < ps->_size; ++i)
	{
		if(ps->_array[i] == data)
			count++;
		else
			ps->_array[i - count] = ps->_array[i];
	}

	ps->_size -= count;
}


int SeqListFind(PSeqList ps, DataType data)
{
	int i = 0;
	if(NULL == ps)
		return;

	for(; i < ps->_size; ++i)
	{
		if(ps->_array[i] == data)
			return i;
	}

	return -1;
}

int SeqListSize(PSeqList ps)
{
	if(NULL == ps)
	{
		assert(0);
		return 0;
	}

	return ps->_size;
}



//////////////////////////////////////////////////
void PrintSeqList(PSeqList ps)
{
	int i = 0;
	if(NULL == ps)
		return;

	for(; i < ps->_size; ++i)
		printf("%d ", ps->_array[i]);

	printf("\n");
}

void Swap(int* pLeft, int* pRight)
{
	int temp = *pLeft;
	*pLeft = *pRight;
	*pRight = temp;
}

void BubbleSort(PSeqList ps)
{
	int i = 0;
	int j = 0;
	int IsChange = 0;

	for(; i < ps->_size-1; ++i)   // ð�ݵ�����
	{
		IsChange = 0;
		for(j = 0; j < ps->_size -1 - i; ++j)   //����ð�ݵķ���
		{
			if(ps->_array[j] > ps->_array[j+1])
			{
				Swap(&ps->_array[j], &ps->_array[j+1]);
				IsChange = 1;
			}
		}

		if(!IsChange)
			return;
	}
}

// >
int Greater(int left, int right)
{
	return left > right;
}

int Less(int left, int right)
{
	return left < right;
}

typedef int (*Compare)(int left, int right);

// 1. ָ��
// 2. ����

// ȱ�ݣ�
void SelectSort(PSeqList ps,  Compare com)
{
	int i = 0;
	int j = 0;
	int maxPos = 0;

	for(; i < ps->_size - 1; ++i)
	{
		maxPos = 0;
		for(j = 1; j < ps->_size - i; ++j)
		{
			if(com(ps->_array[j], ps->_array[maxPos]))
				maxPos = j;
		}

		if(maxPos != ps->_size - 1 - i)
			Swap(&ps->_array[maxPos], &ps->_array[ps->_size- i-1]);
	}
}

// ?
void SelectSortOP(PSeqList ps)
{
	int begin= 0;
	int end = ps->_size-1;
	int j = 0;
	int maxPos = 0;
	int minPos = 0;

	while(begin < end)
	{
		maxPos = begin;
		minPos = begin;
		for(j = begin+1; j <= end; ++j)
		{
			if(ps->_array[j] > ps->_array[maxPos])
				maxPos = j;

			if(ps->_array[j] < ps->_array[minPos])
				minPos = j;
		}

		if(maxPos != end)
			Swap(&ps->_array[maxPos], &ps->_array[end]);
		
		if(minPos == end)
			minPos = maxPos;

		if(minPos != begin)
			Swap(&ps->_array[minPos], &ps->_array[begin]);

		begin++;
		end--;
	}
}




//////////////////////////////////////////////////////////////////////
// testSeqList
void TestSeqList()
{
	SeqList s;
	SeqListInit(&s);
}

void TestSeqListPushPop()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	printf("size = %d\n", SeqListSize(&s));
	PrintSeqList(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	printf("size = %d\n", SeqListSize(&s));
	PrintSeqList(&s);

	SeqListPushFront(&s, 0);
	printf("size = %d\n", SeqListSize(&s));
	PrintSeqList(&s);

	SeqListPopFront(&s);
	printf("size = %d\n", SeqListSize(&s));
	PrintSeqList(&s);
}


void TestSeqListInsertorErase()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	printf("size = %d\n", SeqListSize(&s));
	PrintSeqList(&s);

	SeqListInsert(&s, 3, 6);
	printf("size = %d\n", SeqListSize(&s));
	PrintSeqList(&s);

	SeqListErase(&s, 3);
	printf("size = %d\n", SeqListSize(&s));
	PrintSeqList(&s);
}

void TestSeqListRemoveAll()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 2);
	printf("size = %d\n", SeqListSize(&s));
	PrintSeqList(&s);

	RemoveAll(&s, 2);
	printf("size = %d\n", SeqListSize(&s));
	PrintSeqList(&s);
}

void TestSeqListSelect()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 3);
	PrintSeqList(&s);

	SelectSortOP(&s);

	PrintSeqList(&s);
}