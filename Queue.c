#include "Queue.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>


PListNode BuyListNode(QDataType data)
{
	PListNode pNewNode = (PListNode)malloc(sizeof(ListNode));
	if(NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}

	pNewNode->_data = data;
	pNewNode->_pNext = NULL;

	return pNewNode;
}

void QueueInit(Queue* q)
{
	assert(q);
	q->_pHead = q->_pTail = BuyListNode(0);
}

void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	q->_pTail->_pNext= BuyListNode(data);
	q->_pTail = q->_pTail->_pNext;
}


void QueuePop(Queue* q)
{
	PListNode pDelNode = NULL;
	assert(q);

	pDelNode = q->_pHead->_pNext;
	if(pDelNode)
	{
		if(NULL == pDelNode->_pNext)
			q->_pTail = q->_pHead;

		q->_pHead->_pNext = pDelNode->_pNext;
		free(pDelNode);
	}
}

int QueueSize(Queue* q)
{
	PListNode pCur;
	int count = 0;
	assert(q);

	pCur = q->_pHead->_pNext;
	while(pCur)
	{
		count++;
		pCur = pCur->_pNext;
	}

	return count;
}


int QueueEmpty(Queue* q)
{
	return NULL == q->_pHead->_pNext;
}

QDataType QueueFront(Queue* q)
{
	return q->_pHead->_pNext->_data;
}

QDataType QueueBack(Queue* q)
{
	return q->_pTail->_data;
}

void QueueDestroy(Queue* q)
{

}


void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));
	printf("back = %d\n", QueueSize(&q));

	QueuePop(&q);
	QueuePop(&q);
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));
	printf("back = %d\n", QueueSize(&q));
}