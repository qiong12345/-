#pragma once
#include <malloc.h>
#include <stdio.h>


typedef int DataType;

typedef struct SeqListD
{
     DataType* _array;
	 int _capacity;   // �ռ���ܴ�С
	 int _size;   // ��ЧԪ�صĸ���
}SeqListD, *PSeqListD;



///////////////////////////////////////////////////////////
// SeqListD.h
void SeqListDInit(PSeqListD ps, int capacity);
void SeqListDPushBack(PSeqListD ps, DataType data);
void SeqListDPopBack(PSeqListD ps);
void SeqListDInsert(PSeqListD ps, int pos, DataType data);
void SeqListDErase(PSeqListD ps, int pos);
int SeqListDSize(PSeqListD ps);
int SeqListDCapacity(PSeqListD ps);
int SeqListDEmpty(PSeqListD ps);
void SeqListDClear(PSeqListD ps);
void SeqListDDestroy(PSeqListD ps);

int CheckCapacity(PSeqListD ps);




///////////////////////////////////////////////////////////
// .c
void SeqListDInit(PSeqListD ps, int capacity)
{
	if(NULL == ps)
		return;

	ps->_array = (DataType*)malloc(capacity*sizeof(DataType));
	if(NULL == ps->_array)
	{
		printf("����ռ�ʧ��!!!\n");
		return;
	}

	ps->_capacity = capacity;
	ps->_size = 0;
}

// �������
// �߽�����
// �߼�����
void SeqListDPushBack(PSeqListD ps, DataType data)
{
	if(NULL == ps)
		return;

	if(!CheckCapacity(ps))
	{
		printf("����ʧ��!!!\n");
		return;
	}

	// ����Ԫ��
	ps->_array[ps->_size++] = data;
}

void SeqListDPopBack(PSeqListD ps)
{
	if(NULL == ps)
		return;

	if(SeqListDEmpty(ps))
		return;

	ps->_size--;
}

int CheckCapacity(PSeqListD ps)
{
	if(NULL == ps)
		return 0;

	if(ps->_size == ps->_capacity)
	{
		int newCapacity = ps->_capacity*2;
		ps->_array = (DataType*)realloc(ps->_array, newCapacity*sizeof(DataType));
		if(NULL == ps->_array)
			return 0;

		ps->_capacity = newCapacity;
	}

	return 1;
}

int SeqListDSize(PSeqListD ps)
{
	return ps->_size;
}

int SeqListDCapacity(PSeqListD ps)
{
	return ps->_capacity;
}

int SeqListDEmpty(PSeqListD ps)
{
	return 0 == ps->_size;
}

// ��˳����е�Ԫ����գ����ǲ��ı�ռ�Ĵ�С
void SeqListDClear(PSeqListD ps)
{
	ps->_size = 0;
}

void SeqListDDestroy(PSeqListD ps)
{
	if(ps && ps->_array)
	{
		free(ps->_array);
		ps->_capacity = 0;
		ps->_size = 0;
	}
}


void TestSeqListD()
{
	SeqListD s;
	SeqListDInit(&s, 5);
	SeqListDPushBack(&s, 1);
	SeqListDPushBack(&s, 2);
	SeqListDPushBack(&s, 3);
	SeqListDPushBack(&s, 4);
	SeqListDPushBack(&s, 5);
	printf("size = %d capacity = %d\n", SeqListDSize(&s), SeqListDCapacity(&s));
	
	SeqListDPushBack(&s, 6);
	printf("size = %d capacity = %d\n", SeqListDSize(&s), SeqListDCapacity(&s));


	SeqListDDestroy(&s);
}