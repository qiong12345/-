#pragma once

typedef int DataType;

typedef struct DLNode
{
	DataType _data;
	struct DLNode* _pNext;
	struct DLNode* _pPre;
}DLNode, *PDLNode;


#include <malloc.h>
#include <assert.h>
#include <stdio.h>

PDLNode BuyDHListNode(DataType data)
{
	PDLNode pNewNode = (PDLNode)malloc(sizeof(DLNode));
	if(NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}

	pNewNode->_pNext = NULL;
	pNewNode->_pPre = NULL;
	pNewNode->_data = data;

	return pNewNode;
}

void DListInit(PDLNode* pHead)
{
	assert(pHead);
	*pHead = BuyDHListNode(0);
}

void DListPushBack(PDLNode pHead, DataType data)
{
	PDLNode pTail = pHead;
	assert(pHead);

	while(pTail->_pNext)
		pTail = pTail->_pNext;

	pTail->_pNext = BuyDHListNode(data);
	pTail->_pNext->_pPre = pTail;
}

void DListInsert(PDLNode pos, DataType data)
{
	PDLNode pNewNode = NULL;
	if(NULL == pos)
		return;

	pNewNode = BuyDHListNode(data);
	pNewNode->_pNext = pos;
	pNewNode->_pPre = pos->_pPre;
	pNewNode->_pPre->_pNext = pNewNode;
	pos->_pPre = pNewNode;
}

void DListErase(PDLNode pos)
{
	if(NULL == pos)
		return;

	pos->_pPre->_pNext = pos->_pNext;
	if(pos->_pNext)
		pos->_pNext->_pPre = pos->_pPre;

	free(pos);
}

void PrintDList(PDLNode pHead)
{
	PDLNode pCur = NULL;
	assert(pHead);

	pCur = pHead->_pNext;
	while(pCur)
	{
		printf("%d--->", pCur->_data);
		pCur = pCur->_pNext;
	}

	printf("NULL\n");
}



void TestDList()
{
	PDLNode pHead;
	DListInit(&pHead);
	DListPushBack(pHead, 1);
	DListPushBack(pHead, 2);
	DListPushBack(pHead, 3);
	DListPushBack(pHead, 4);
	PrintDList(pHead);

	DListInsert(pHead->_pNext, 0);
	PrintDList(pHead);

	DListErase(pHead->_pNext);
	PrintDList(pHead);
}