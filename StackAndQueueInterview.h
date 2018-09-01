#pragma once

#include "Stack.h"


#if 0

typedef struct MinStack
{
	Stack _s;
}MinStack;


void MinStackInit(MinStack* s)
{
	StackInit(&s->_s);
}

void MinStackPush(MinStack* s, MinSDataType data)
{
#if 0
	SElem elem;
	elem._data = elem._minData = data;
	if(StackEmpty(&s->_s))
		StackPush(&s->_s, elem);
	else
	{
		SElem top = StackTop(&s->_s);
		if(data > top._minData)
			elem._minData = top._minData;

		StackPush(&s->_s, elem);
	}
#endif

	SElem elem;

	if(s->_s._top == MAX_SIZE)
		return;

	elem._data = elem._minData = data;
	if(!StackEmpty(&s->_s))
	{
		SElem top = StackTop(&s->_s);
		if(data > top._minData)
			elem._minData = top._minData;
	}

	StackPush(&s->_s, elem);
}

void MinStackPop(MinStack* s)
{
	if(!StackEmpty(&s->_s))
		StackPop(&s->_s);
}

int MinStackSize(MinStack* s)
{
	return StackSize(&s->_s);
}

int MinStackEmpty(MinStack* s)
{
	return StackEmpty(&s->_s);
}

MinSDataType MinStackTop(MinStack* s)
{
	return StackTop(&s->_s)._data;
}

MinSDataType MinStackMinData(MinStack* s)
{
	return StackTop(&s->_s)._minData;
}
#endif

#if 0
typedef struct MinStack
{
	Stack _sdata; // 数据
	Stack _sMinData; // 最小值
}MinStack;


void MinStackInit(MinStack* s)
{
	StackInit(&s->_sdata);
	StackInit(&s->_sMinData);
}

void MinStackPush(MinStack* s, MinSDataType data)
{
	if(StackSize(&s->_sdata) == MAX_SIZE)
		return;

	// minData
	if(StackEmpty(&s->_sdata))
		StackPush(&s->_sMinData, data);
	else
	{
		MinSDataType minData = StackTop(&s->_sMinData);
		if(data <= minData)
		{
			minData = data;
			StackPush(&s->_sMinData, minData);
		}
	}

	// data
	StackPush(&s->_sdata, data);
}

void MinStackPop(MinStack* s)
{
	if(!StackEmpty(&s->_sdata))
	{
		MinSDataType data = StackTop(&s->_sdata);
		if(data == StackTop(&s->_sMinData))
			StackPop(&s->_sMinData);

		StackPop(&s->_sdata);
	}
}

int MinStackSize(MinStack* s)
{
	return StackSize(&s->_sdata);
}

int MinStackEmpty(MinStack* s)
{
	return StackEmpty(&s->_sdata);
}

MinSDataType MinStackTop(MinStack* s)
{
	return StackTop(&s->_sdata);
}

MinSDataType MinStackMinData(MinStack* s)
{
	return StackTop(&s->_sMinData);
}

#include <stdio.h>
void TestMinStack()
{
	MinStack s;
	MinStackInit(&s);
	MinStackPush(&s, 3);
	MinStackPush(&s, 2);
	MinStackPush(&s, 4);
	MinStackPush(&s, 5);
	MinStackPush(&s, 1);
	MinStackPush(&s, 6);

	printf("size = %d\n", MinStackSize(&s));
	printf("top = %d\n", MinStackTop(&s));
	printf("minData = %d\n", MinStackMinData(&s));

	MinStackPop(&s);
	MinStackPop(&s);
	printf("size = %d\n", MinStackSize(&s));
	printf("top = %d\n", MinStackTop(&s));
	printf("minData = %d\n", MinStackMinData(&s));
}
#endif

#if 0
typedef struct QueueBy2Stack
{
	Stack _s1;
	Stack _s2;
}QueueBy2Stack;


#include <assert.h>
#include <stdio.h>
void QueueBy2StackInit(QueueBy2Stack* q)
{
	StackInit(&q->_s1);
	StackInit(&q->_s2);
}

int QueueBy2StackEmpty(QueueBy2Stack* q)
{
	return StackEmpty(&q->_s1) && StackEmpty(&q->_s2);
}

void QueueBy2StackPush(QueueBy2Stack* q, QDataType data)
{
	StackPush(&q->_s1, data);
}

void QueueBy2StackPop(QueueBy2Stack* q)
{
	if(QueueBy2StackEmpty(q))
		return;

	if(StackEmpty(&q->_s2))
	{
		while(!StackEmpty(&q->_s1))
		{
			StackPush(&q->_s2, StackTop(&q->_s1));
			StackPop(&q->_s1);
		}
	}

	StackPop(&q->_s2);
}

QDataType QueueBy2StackFront(QueueBy2Stack* q)
{
	assert(!QueueBy2StackEmpty(q));

	if(StackEmpty(&q->_s2))
	{
		while(!StackEmpty(&q->_s1))
		{
			StackPush(&q->_s2, StackTop(&q->_s1));
			StackPop(&q->_s1);
		}
	}

	return StackTop(&q->_s2);
}

QDataType QueueBy2StackBack(QueueBy2Stack* q)
{
	assert(!QueueBy2StackEmpty(q));

	if(StackEmpty(&q->_s1))
	{
		while(!StackEmpty(&q->_s2))
		{
			StackPush(&q->_s1, StackTop(&q->_s2));
			StackPop(&q->_s2);
		}
	}

	return StackTop(&q->_s1);
}

int QueueBy2StackSize(QueueBy2Stack* q)
{
	return StackSize(&q->_s1) + StackSize(&q->_s2);
}

void TestQueueBy2Stack()
{
	QueueBy2Stack q;
	QueueBy2StackInit(&q);

	QueueBy2StackPush(&q, 1);
	QueueBy2StackPush(&q, 2);
	QueueBy2StackPush(&q, 3);
	printf("size = %d\n", QueueBy2StackSize(&q));
	printf("front = %d\n", QueueBy2StackFront(&q));
	printf("back = %d\n", QueueBy2StackBack(&q));

	QueueBy2StackPop(&q);
	QueueBy2StackPop(&q);
	printf("size = %d\n", QueueBy2StackSize(&q));
	printf("front = %d\n", QueueBy2StackFront(&q));
	printf("back = %d\n", QueueBy2StackBack(&q));

	QueueBy2StackPush(&q, 5);
	QueueBy2StackPush(&q, 6);
	printf("size = %d\n", QueueBy2StackSize(&q));
	printf("front = %d\n", QueueBy2StackFront(&q));
	printf("back = %d\n", QueueBy2StackBack(&q));
}
#endif

#if 0
#include "Queue.h"
#include <stdio.h>
#include <assert.h>

typedef struct StackBy2Queue
{
	Queue _q1;
	Queue _q2;
}StackBy2Queue;

void StackBy2QueueInit(StackBy2Queue* s)
{
	QueueInit(&s->_q1);
	QueueInit(&s->_q2);
}

int StackBy2QueueEmpty(StackBy2Queue* s)
{
	return QueueEmpty(&s->_q1) && QueueEmpty(&s->_q2);
}

void StackBy2QueuePush(StackBy2Queue* s, SDataType data)
{
	if(QueueEmpty(&s->_q1))
		QueuePush(&s->_q2, data);
	else
		QueuePush(&s->_q1, data);
}

void StackBy2QueuePop(StackBy2Queue* s)
{
	if(!StackBy2QueueEmpty(s))
	{
		if(!QueueEmpty(&s->_q1))
		{
			while(QueueSize(&s->_q1) > 1)
			{
				QueuePush(&s->_q2, QueueFront(&s->_q1));
				QueuePop(&s->_q1);
			}

			QueuePop(&s->_q1);
		}
		else
		{
			while(QueueSize(&s->_q2)>1)
			{
				QueuePush(&s->_q1, QueueFront(&s->_q2));
				QueuePop(&s->_q2);
			}

			QueuePop(&s->_q2);
		}
	}
}

SDataType StackBy2QueueTop(StackBy2Queue* s)
{
	assert(!StackBy2QueueEmpty(s));

	if(!QueueEmpty(&s->_q1))
		return QueueBack(&s->_q1);
	else
		return QueueBack(&s->_q2);
}

int StackBy2QueueSize(StackBy2Queue* s)
{
	return QueueSize(&s->_q1) + QueueSize(&s->_q2);
}

void StackBy2QueueDestroy(StackBy2Queue* s)
{
	QueueDestroy(&s->_q1);
	QueueDestroy(&s->_q2);
}


void TestStackBy2Queue()
{
	StackBy2Queue s;
	StackBy2QueueInit(&s);
	StackBy2QueuePush(&s, 1);
	StackBy2QueuePush(&s, 2);
	StackBy2QueuePush(&s, 3);
	StackBy2QueuePush(&s, 4);

	printf("size = %d\n", StackBy2QueueSize(&s));
	printf("size = %d\n", StackBy2QueueTop(&s));
	
	StackBy2QueuePop(&s);
	StackBy2QueuePop(&s);
	printf("size = %d\n", StackBy2QueueSize(&s));
	printf("size = %d\n", StackBy2QueueTop(&s));

	StackBy2QueuePush(&s, 5);
	printf("size = %d\n", StackBy2QueueSize(&s));
	printf("size = %d\n", StackBy2QueueTop(&s));

	StackBy2QueueDestroy(&s);
}
#endif

#include "Stack.h"
int InOutStackIsValid(int* InOrder, int InSize, int* OutOrder, int OutSize)
{
	Stack s;
	int InIdx = 0, OutIdx = 0;
	// 入栈和出栈元素的个数必须相同
	if(InSize != OutSize)
		return 0;

	StackInit(&s);
	while(OutIdx < OutSize)
	{
		while(StackEmpty(&s) || StackTop(&s) != OutOrder[OutIdx])
		{
			if(InIdx < InSize)
				StackPush(&s, InOrder[InIdx++]);
			else
				return 0;
		}

		StackPop(&s);
		OutIdx++;
	}

	return 1;
}

#if 0
#include <stdio.h>

void TestInOutStackIsValid()
{
	int InOrder[] = {1,2,3,4,5};
	int OutOrder[] = {4,5,3,1,2};
	if(InOutStackIsValid(InOrder, sizeof(InOrder)/sizeof(InOrder[0]),
		                 OutOrder, sizeof(OutOrder)/sizeof(OutOrder[0])))
	{
		printf("入栈和出栈顺序合法!!!\n");
	}
	else
	{
		printf("入栈和出栈顺序非法!!!\n");
	}
}
#endif

typedef int DataType;
#define  MAX_SIZE  10

typedef struct SharedStack
{
     DataType _array[MAX_SIZE];
	 int _top1;
	 int _top2;
}SharedStack;

#include <assert.h>
void SharedStackInit(SharedStack* s)
{
	s->_top1 = 0;   // 栈1占用偶数空间
	s->_top2 = 1;   // 栈2占用基数空间
}

void SharedStackPush(SharedStack* s, int which, DataType data)
{
	assert(1 == which || 2 == which);
	if(1 == which)
	{
		if(s->_top1 < MAX_SIZE)
		{
			s->_array[s->_top1] = data;
			s->_top1 += 2;
		}
	}
	else
	{
		if(s->_top2 < MAX_SIZE)
		{
			s->_array[s->_top2] = data;
			s->_top2 += 2;
		}
	}
}

int SharedStackEmpty(SharedStack* s, int which)
{
	assert(1 == which || 2 == which);
	if(1 == which)
		return 0 == s->_top1;
	else
		return 1 == s->_top2;
}

void SharedStackPop(SharedStack* s, int which)
{
	assert(1 == which || 2 == which);
	if(1 == which)
	{
		if(!SharedStackEmpty(s, 1))
			s->_top1 -= 2;
	}
	else
	{
		if(!SharedStackEmpty(s, 2))
			s->_top2 -= 2;
	}
}

DataType SharedStackTop(SharedStack* s, int which)
{
	assert(1 == which || 2 == which);
	if(1 == which)
	{
		assert(!SharedStackEmpty(s, 1));
		return s->_array[s->_top1-2];
	}
	else
	{
		assert(!SharedStackEmpty(s, 2));
		return s->_array[s->_top2-2];
	}
}

int SharedStackSize(SharedStack* s, int which)
{
	assert(1 == which || 2 == which);
	if(1 == which)
		return (s->_top1>>1);
	else
		return (s->_top2>>1);
}

#include <stdio.h>
void TestSharedStack()
{
	SharedStack s;
	SharedStackInit(&s);

	SharedStackPush(&s, 1, 0);
	SharedStackPush(&s, 1, 2);
	SharedStackPush(&s, 1, 4);
	SharedStackPush(&s, 1, 6);

	SharedStackPush(&s, 2, 1);
	SharedStackPush(&s, 2, 3);
	SharedStackPush(&s, 2, 5);

	printf("stack1 size = %d", SharedStackSize(&s, 1));
	printf("stack1 top = %d", SharedStackTop(&s, 1));

	printf("stack2 size = %d", SharedStackSize(&s, 2));
	printf("stack2 top = %d", SharedStackTop(&s, 2));

	SharedStackPop(&s, 1);
	SharedStackPop(&s, 2);
	printf("stack1 size = %d", SharedStackSize(&s, 1));
	printf("stack1 top = %d", SharedStackTop(&s, 1));

	printf("stack2 size = %d", SharedStackSize(&s, 2));
	printf("stack2 top = %d", SharedStackTop(&s, 2));
}




