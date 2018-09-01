#pragma once

typedef int DataType;

typedef struct SHListNode
{
	struct SHListNode* _pNext;
	DataType _data;
}SHLNode, *PSHLNode;


#include <malloc.h>
#include <assert.h>
#include <stdio.h>

PSHLNode BuySHListNode(DataType data)
{
	PSHLNode pNewNode = (PSHLNode)malloc(sizeof(SHLNode));
	if(NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}

	pNewNode->_pNext = NULL;
	pNewNode->_data = data;

	return pNewNode;
}

void SHListInit(PSHLNode* pHead)
{
	assert(pHead);
	*pHead = BuySHListNode(0);
}

void SHListPushBack(PSHLNode pHead, DataType data)
{
	PSHLNode pTail = pHead;
	assert(pHead);

	while(pTail->_pNext)
		pTail = pTail->_pNext;

	pTail->_pNext = BuySHListNode(data);
}

void SHListPopBack(PSHLNode pHead)
{
	PSHLNode pTail = pHead;
	assert(pHead);
	if(pHead->_pNext)
	{
		PSHLNode pPreTail = NULL;
		while(pTail->_pNext)
		{
			pPreTail = pTail;
			pTail = pTail->_pNext;
		}

		free(pTail);
		pPreTail->_pNext = NULL;
	}
}

void SHListPushFront(PSHLNode pHead, DataType data)
{
	PSHLNode pNewNode = NULL;
	assert(pHead);

	pNewNode = BuySHListNode(data);
	pNewNode->_pNext = pHead->_pNext;
	pHead->_pNext = pNewNode;
}

void SHListPopFront(PSHLNode pHead)
{
	assert(pHead);
	if(pHead->_pNext)
	{
		PSHLNode pDelNode = pHead->_pNext;
		pHead->_pNext = pDelNode->_pNext;
		free(pDelNode);
	}
}

void PrintSHList(PSHLNode pHead)
{
	PSHLNode pCur = NULL;
	assert(pHead);

	pCur = pHead->_pNext;
	while(pCur)
	{
		printf("%d--->", pCur->_data);
		pCur = pCur->_pNext;
	}

	printf("NULL\n");
}

void SHListClear(PSHLNode pHead)
{
	assert(pHead);
	while(pHead->_pNext)
	{
		PSHLNode pDelNode = pHead->_pNext;
		pHead->_pNext = pDelNode->_pNext;
		free(pDelNode);
	}
}

void SHListDestroy(PSHLNode* pHead)
{
	assert(pHead);
	SHListClear(*pHead);
	free(*pHead);
	*pHead = NULL;
}



void TestSHList()
{
	PSHLNode pHead;
	SHListInit(&pHead);
	SHListPushBack(pHead, 1);
	SHListPushBack(pHead, 2);
	SHListPushBack(pHead, 3);
	SHListPushBack(pHead, 4);
	PrintSHList(pHead);

	SHListPopBack(pHead);
	PrintSHList(pHead);

	SHListPushFront(pHead, 0);
	PrintSHList(pHead);


	SHListPopFront(pHead);
	PrintSHList(pHead);

	SHListDestroy(&pHead);
}