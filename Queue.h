#pragma once

//typedef int SDataType;

extern struct BinTreeNode;

typedef struct BinTreeNode* QDataType;

typedef struct ListNode
{
	struct ListNode* _pNext;
	QDataType _data;
}ListNode, *PListNode;

typedef struct Queue
{
	PListNode _pHead;
	PListNode _pTail;
}Queue;


void QueueInit(Queue* q);
void QueuePush(Queue* q, QDataType data);
void QueuePop(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
QDataType QueueFront(Queue* q);
QDataType QueueBack(Queue* q);
void QueueDestroy(Queue* q);




////////////////////////////////////////////
//
void TestQueue();