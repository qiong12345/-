#pragma once

typedef int DataType;


typedef struct SNode
{
	DataType _data;
	struct SNode* _pNext;   // 指向下一个结点的地址
}Node, *PNode;


//////////////////////////////////////////////////////////
// List.h
void SListInit(PNode* pHead);
void SListPushBack(PNode* pHead, DataType data);
void SListPopBack(PNode* pHead);
void SListPushFront(PNode* pHead, DataType data);
void SListPopFront(PNode* pHead);
PNode SListFind(PNode pHead, DataType data);
void SListInsert(PNode* pHead, PNode pos, DataType data);
void SListErase(PNode* pHead, PNode pos);
int SListSize(PNode pHead);
int SListEmpty(PNode pHead);
void SListDestroy(PNode* pHead);


/////////////////////////////////////////////////////
//
void PrintSListFromTail2Head(PNode pHead);
void DeleteListNotTailNode(PNode pos);
void InesrtPosFront(PNode pos, DataType data);
PNode FindMiddleNode(PNode pHead);
PNode FindLastKNode(PNode pHead, int K);
void JosephCircle(PNode* pHead, const int M);
void ReverseSList(PNode* pHead);
PNode ReverseSListOP(PNode pHead);
void BubbleSort(PNode pHead);
PNode MergeSList(PNode pHead1, PNode pHead2);
int IsSListCross(PNode pHead1, PNode pHead2);
PNode GetCorssNode(PNode pHead1, PNode pHead2);
PNode IsListWithCircle(PNode pHead1);
PNode GetCircleEnter(PNode pHead1, PNode pMeetNode);
int GetCircleLen(PNode pMeetNode);
int IsSListCrossWithCircle(PNode pHead1, PNode pHead2);

////////////////////////////////////////////////////////
//List.c
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

PNode BuySListNode(DataType data)
{
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	if(NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}

	pNewNode->_data = data;
	pNewNode->_pNext = NULL;

	return pNewNode;
}

// pHead--->外部实参的地址
void SListInit(PNode* pHead)
{
	assert(pHead);
	*pHead = NULL;
}

void SListPushBack(PNode* pHead, DataType data)
{
	assert(pHead);

	if(NULL == *pHead)
		*pHead = BuySListNode(data);
	else
	{
		PNode pCur = *pHead;

#if 0
		// 找最后一个节点
		while(pCur->_pNext)
			pCur = pCur->_pNext;
#else
		PNode pPre = NULL;
		while(pCur)
		{
			pPre = pCur;
			pCur = pCur->_pNext;
		}

		pCur = pPre;
#endif

		pCur->_pNext = BuySListNode(data);
	}
}

void SListPopBack(PNode* pHead)
{
	// 断言链表是否存在
	assert(pHead);

	if(NULL == *pHead)  // 空链表
		return;
	else if(NULL == (*pHead)->_pNext)  // 一个节点
	{
		free(*pHead);
		*pHead = NULL;
	}
	else
	{
		// 链表中有多个结点
		// 找链表中的倒数第二个结点
#if 0
		PNode pCur = *pHead;
		while(pCur->_pNext->_pNext)
			pCur = pCur->_pNext;

		free(pCur->_pNext);
		pCur->_pNext = NULL;
#endif
		// 找最后一个节点
		PNode pTailNode = *pHead;
		PNode pPreTail = NULL;
		while(pTailNode->_pNext)
		{
			pPreTail = pTailNode;
			pTailNode = pTailNode->_pNext;
		}

		free(pTailNode);
		pPreTail->_pNext = NULL;
	}
}

void SListPushFront(PNode* pHead, DataType data)
{
	PNode pNewNode = NULL;
	assert(pHead);

	pNewNode = BuySListNode(data);
	pNewNode->_pNext = *pHead;
	*pHead = pNewNode;
}

void SListPopFront(PNode* pHead)
{
	PNode pDelNode = NULL;

	assert(pHead);
	if(NULL == *pHead)
		return;

	pDelNode = *pHead;
	*pHead = pDelNode->_pNext;
	free(pDelNode);
}

PNode SListFind(PNode pHead, DataType data)
{
	PNode pCur = pHead;
	while(pCur)
	{
		if(data == pCur->_data)
			return pCur;

		pCur = pCur->_pNext;
	}

	return NULL;
}

void SListInsert(PNode* pHead, PNode pos, DataType data)
{
	PNode pPre = NULL;
	assert(pHead);
	if(NULL == *pHead || NULL == pos)
		return;

	pPre = *pHead;
	if(pos == *pHead)
		SListPushFront(pHead, data);
	else
	{
		while(pPre && pPre->_pNext != pos)
			pPre = pPre->_pNext;

		if(pPre)
		{
			PNode pNewNode = BuySListNode(data);
			pNewNode->_pNext = pos;
			pPre->_pNext = pNewNode;
		}
	}
}

void SListErase(PNode* pHead, PNode pos)
{
	assert(pHead);
	if(NULL == *pHead || NULL == pos)
		return;

	if(pos == *pHead)
		SListPopFront(pHead);
	else
	{
		PNode pPre = *pHead;
		while(pPre && pPre->_pNext != pos)
			pPre = pPre->_pNext;

		if(pPre)
		{
			pPre->_pNext = pos->_pNext;
			free(pos);
		}
	}
}

int SListSize(PNode pHead)
{
	PNode pCur = pHead;
	int count = 0;

	while(pCur)
	{
		count++;
		pCur = pCur->_pNext;
	}

	return count;
}

int SListEmpty(PNode pHead)
{
	return NULL == pHead;
}

void SListDestroy(PNode* pHead)
{
	PNode pDelNode = NULL;
	while(*pHead)
	{
		pDelNode = *pHead;
		*pHead = pDelNode->_pNext;
		free(pDelNode);
	}
}


//////////////////////////////////////////////////////////////
void PrintfSList(PNode pHead)
{
	PNode pCur = pHead;
	while(pCur)
	{
		printf("%d--->", pCur->_data);
		pCur = pCur->_pNext;
	}

	printf("NULL\n");
}

PNode SListBack(PNode pHead)
{
	PNode pCur = pHead;
	if(NULL == pHead)
		return NULL;

	while(pCur->_pNext)
		pCur = pCur->_pNext;

	return pCur;
}

////////////////////////////////////////////////////////////////////
// List interview
void PrintSListFromTail2Head(PNode pHead)
{
	if(pHead)
	{
		PrintSListFromTail2Head(pHead->_pNext);
		printf("%d ", pHead->_data);
	}
}

void DeleteListNotTailNode(PNode pos)
{
	PNode pDel = NULL;
	if(NULL == pos || NULL == pos->_pNext)
		return;

	pDel = pos->_pNext;
	pos->_pNext = pDel->_pNext;
	pos->_data = pDel->_data;
	free(pDel);
}

void InesrtPosFront(PNode pos, DataType data)
{
	PNode pNewNode = NULL;
	DataType temp;
	if(NULL == pos)
		return;

	pNewNode = BuySListNode(pos->_data);
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
	pos->_data = data;

#if 0
	pNewNode = BuySListNode(data);
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
	temp = pos->_data;
	pos->_data = pNewNode->_data;
	pNewNode->_data = temp;
#endif
}

PNode FindMiddleNode(PNode pHead)
{
	PNode pFast = pHead;
	PNode pSlow = pHead;

	while(pFast && pFast->_pNext)
	{
		pFast = pFast->_pNext->_pNext;
		pSlow = pSlow->_pNext;
	}

	return pSlow;
}

PNode FindLastKNode(PNode pHead, int K)
{
	PNode pFast = pHead;
	PNode pSlow = pHead;
	if(NULL == pHead || K <= 0)
		return NULL;

	// 让pFast先走K步
	while(K--)  //--K --- K-1
	{
		// K大于链表中结点的个数
		if(NULL == pFast)
			return NULL;

		pFast = pFast->_pNext;
	}

	// 让pSlow和pFast一起
	while(pFast)   //while(pFast->_pNext)
	{
		pFast = pFast->_pNext;
		pSlow = pSlow->_pNext;
	}

	return pSlow;
}

void JosephCircle(PNode* pHead, const int M)
{
	PNode pCur = NULL;
	PNode pDelNode = NULL;
	
	assert(pHead);
	if(NULL == *pHead)
		return;

	pCur = *pHead;
	while(pCur != pCur->_pNext)
	{
		// 1. 报数
		int count = M;
		while(--count)
			pCur = pCur->_pNext;

		// 2. 删除节点
		pDelNode = pCur->_pNext;
		pCur->_data = pDelNode->_data;
		pCur->_pNext = pDelNode->_pNext;
		free(pDelNode);
	}

	// 首节点有可能已经被删除
	*pHead = pCur;
}

void ReverseSList(PNode* pHead)
{
	PNode pPre, pCur, pNext;
	assert(pHead);

	pPre = NULL;
	pCur = *pHead;
	while(pCur)
	{
		pNext = pCur->_pNext;
		pCur->_pNext = pPre;
		pPre = pCur;
		pCur = pNext;
	}

	*pHead = pPre;
}

PNode ReverseSListOP(PNode pHead)
{
	PNode pCur = pHead;
	PNode pNewHead = NULL;

	while(pHead)
	{
		pCur = pHead;
		pHead = pHead->_pNext;
		pCur->_pNext = pNewHead;
		pNewHead = pCur;
	}

	return pNewHead;
}

void BubbleSort(PNode pHead)
{
	PNode pCur, pPre, pTail = NULL;
	while(pHead != pTail)
	{
		int IsChange = 0;
		pPre = pHead;
		pCur = pPre->_pNext;

		while(pCur != pTail)
		{
			if(pPre->_data > pCur->_data)
			{
				DataType temp = pPre->_data;
				pPre->_data = pCur->_data;
				pCur->_data = temp;
				IsChange = 1;
			}

			pPre = pCur;
			pCur = pPre->_pNext;
		}

		if(!IsChange)
			return;

		pTail = pPre;
	}
}

PNode MergeSList(PNode pHead1, PNode pHead2)
{
	PNode pL1 = pHead1;
	PNode pL2 = pHead2;
	PNode pNewHead = NULL;
	PNode pTail = NULL;

	if(NULL == pHead1)
		return pHead2;

	if(NULL == pHead2)
		return pHead1;

	// 放置pNewHead
	if(pL1->_data < pL2->_data)
	{
		pNewHead = pL1;
		pL1 = pL1->_pNext;
	}
	else
	{
		pNewHead = pL2;
		pL2 = pL2->_pNext;
	}

	pTail = pNewHead;
	while(pL1 && pL2)
	{
		if(pL1->_data < pL2->_data)
		{
			pTail->_pNext = pL1;
			pL1 = pL1->_pNext;
		}
		else
		{
			pTail->_pNext = pL2;
			pL2 = pL2->_pNext;
		}

		pTail = pTail->_pNext;
	}

	if(pL1)
		pTail->_pNext = pL1;
	else
		pTail->_pNext = pL2;

	return pNewHead;
}

int IsSListCross(PNode pHead1, PNode pHead2)
{
	PNode pTail1 = pHead1, pTail2 = pHead2;
	if(NULL == pHead1 || NULL == pHead2)
		return 0;

	while(pTail1->_pNext)
		pTail1 = pTail1->_pNext;

	while(pTail2->_pNext)
		pTail2 = pTail2->_pNext;

	return pTail1 == pTail2;
}

PNode GetCorssNode(PNode pHead1, PNode pHead2)
{
	int size1 = 0, size2 = 0;
	PNode pCur1 = pHead1, pCur2 = pHead2;
	int gap = 0;
	if(!IsSListCross(pHead1, pHead2))
		return NULL;

	// 求两个链表中结点的个数
	while(pCur1)
	{
		size1++;
		pCur1 = pCur1->_pNext;
	}

	while(pCur2)
	{
		size2++;
		pCur2 = pCur2->_pNext;
	}

	gap = size1 - size2;
	pCur1 = pHead1;
	pCur2 = pHead2;
	if(gap > 0)
	{
		while(gap--)
			pCur1 = pCur1->_pNext;
	}
	else
	{
		while(gap++)
			pCur2 = pCur2->_pNext;
	}

	while(pCur1 != pCur2)
	{
		pCur1 = pCur1->_pNext;
		pCur2 = pCur2->_pNext;
	}

	return pCur1;
}

PNode IsListWithCircle(PNode pHead)
{
	PNode pFast = pHead;
	PNode pSlow = pHead;

	while(pFast && pFast->_pNext)
	{
		pFast = pFast->_pNext->_pNext;
		pSlow = pSlow->_pNext;

		if(pFast == pSlow)
			return pFast;
	}

	return NULL;
}

PNode GetCircleEnter(PNode pHead, PNode pMeetNode)
{
	PNode pH = pHead;
	PNode pM = pMeetNode;

	if(NULL == pHead || NULL == pMeetNode)
		return NULL;

	while(pH != pM)
	{
		pH = pH->_pNext;
		pM = pM->_pNext;
	}

	return pM;
}

int GetCircleLen(PNode pMeetNode)
{
	int count = 1;
	PNode pCur = pMeetNode;
	if(NULL == pMeetNode)
		return 0;

	while(pCur->_pNext != pMeetNode)
	{
		count++;
		pCur = pCur->_pNext;
	}

	return count;
}

int IsSListCrossWithCircle(PNode pHead1, PNode pHead2)
{
	// 1. 判断两个链表是否带环
	PNode pMeetNode1 = IsListWithCircle(pHead1);
	PNode pMeetNode2 = IsListWithCircle(pHead2);

	// 两个链表都不带环
	if(NULL == pMeetNode1 && NULL == pMeetNode2)
	{
		PNode pTail1 = pHead1;
		PNode pTail2 = pHead2;

		while(pTail1->_pNext)
			pTail1 = pTail1->_pNext;

		while(pTail2->_pNext)
			pTail2 = pTail2->_pNext;

		if(pTail1 == pTail2)
			return 1;
	}
	else if(pMeetNode1 && pMeetNode2)  // 两个链表均带环
	{
		PNode pCur = pMeetNode1;
		while(pCur->_pNext != pMeetNode1)
		{
			if(pCur == pMeetNode2)
				return 2;

			pCur = pCur->_pNext;
		}

		if(pCur == pMeetNode2)
			return 2;
	}

	return 0;
}

////////////////////////////////////////////////
// 复杂链表的赋值
typedef struct CSListNode
{
	struct CSListNode* _pNext;
	struct CSListNode* _pRandom;
	DataType _data;
}CSListNode, *PCSListNode;

PCSListNode BuyComplexSListNode(DataType data)
{
	PCSListNode pNewNode = (PCSListNode)malloc(sizeof(CSListNode));
	if(NULL == pNewNode)
		assert(0);

	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	pNewNode->_pRandom = NULL;

	return pNewNode;
}

PCSListNode CopyComplexSList(PCSListNode pHead)
{
	// 1. 在原链表每个结点后插入值相同的新节点
	PCSListNode pCur = pHead;
	PCSListNode pNewNode;
	PCSListNode pNewHead = NULL;

	if(NULL == pHead)
		return NULL;

	while(pCur)
	{
		pNewNode = BuyComplexSListNode(pCur->_data);
		pNewNode->_pNext = pCur->_pNext;
		pCur->_pNext = pNewNode;
		pCur = pNewNode->_pNext;
		
	}

	// 2. 给新节点的随机指针域赋值
	pCur = pHead;
	while(pCur)
	{
		pNewNode = pCur->_pNext;
		if(pCur->_pRandom)
			pNewNode->_pRandom = pCur->_pRandom->_pNext;

		pCur = pNewNode->_pNext;
	}

	// 3. 将新插入结点从原链表中拆下来
	pNewHead = pHead->_pNext;
	pCur = pHead;
	while(pCur->_pNext)
	{
		pNewNode = pCur->_pNext;
		pCur->_pNext = pNewNode->_pNext;
		pCur = pNewNode;
	}

	return pNewHead;
}

void TestComplexSList()
{
	CSListNode node1, node2, node3, node4;
	PCSListNode pHead;
	node1._data = 1;
	node1._pNext = &node2;
	node1._pRandom = &node3;

	node2._data = 2;
	node2._pNext = &node3;
	node2._pRandom = &node1;

	node3._data = 3;
	node3._pNext = &node4;
	node3._pRandom = &node3;

	node4._data = 4;
	node4._pNext = NULL;
	node4._pRandom = NULL;

	pHead = CopyComplexSList(&node1);
}




// PushBack/PopBack/PushFront/PopFront
void TestList1()
{
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	PrintfSList(pHead);
	PrintSListFromTail2Head(pHead);

	SListPopBack(&pHead);
	PrintfSList(pHead);

	SListPushFront(&pHead, 0);
	PrintfSList(pHead);

	SListPopFront(&pHead);
	PrintfSList(pHead);
	SListDestroy(&pHead);
}

void TestInsertAndErase()
{
	PNode pHead, pos;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	PrintfSList(pHead);

	pos = SListFind(pHead, 3);
	SListInsert(&pHead, pos, 6);
	PrintfSList(pHead);

	pos = SListFind(pHead, 6);
	SListErase(&pHead, pos);
	PrintfSList(pHead);

	pos = SListFind(pHead, 3);
	DeleteListNotTailNode(pos);
	PrintfSList(pHead);

	pos = SListFind(pHead, 4);
	InesrtPosFront(pos, 3);
	PrintfSList(pHead);
	SListDestroy(&pHead);
}

void TestFindMiddleAndLastK()
{
	PNode pHead, pos;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	//SListPushBack(&pHead, 5);
	PrintfSList(pHead);

	pos = FindMiddleNode(pHead);
	if(pos)
		printf("中间结点为%d\n", pos->_data);
	else
		printf("查找有误!!!\n");

	pos = FindLastKNode(pHead, 2);
	if(pos)
		printf("倒数第%d个结点为%d\n", 2, pos->_data);
	else
		printf("查找有误!!!\n");

	pos = FindLastKNode(pHead, 10);
	if(pos)
		printf("查找有误!!!\n");
	else
		printf("倒数第%d个结点没有\n", 10);
}

void TestJosephCircle()
{
	PNode pHead, pos;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	PrintfSList(pHead);

	// 构环
	SListBack(pHead)->_pNext = pHead;

	JosephCircle(&pHead, 3);

	// 解环
	pHead->_pNext = NULL;
}

void TestSListReverse()
{
	PNode pHead, pos;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	PrintfSList(pHead);

	ReverseSList(&pHead);
	PrintfSList(pHead);

	pHead = ReverseSListOP(pHead);
	PrintfSList(pHead);
}

void TestBubbleSort()
{
	PNode pHead, pos;
	SListInit(&pHead);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 4);
	PrintfSList(pHead);

	BubbleSort(pHead);
	PrintfSList(pHead);
}

void TestMergeSList()
{
	PNode pHead1, pHead2;
	SListInit(&pHead1);
	SListPushBack(&pHead1, 1);
	SListPushBack(&pHead1, 3);
	SListPushBack(&pHead1, 6);
	SListPushBack(&pHead1, 8);
	PrintfSList(pHead1);

	SListInit(&pHead2);
	SListPushBack(&pHead2, 2);
	SListPushBack(&pHead2, 3);
	SListPushBack(&pHead2, 5);
	SListPushBack(&pHead2, 7);
	PrintfSList(pHead2);

	pHead1 = MergeSList(pHead1, pHead2);
	PrintfSList(pHead1);
}

void TestSListCross()
{
	PNode pHead1, pHead2;
	SListInit(&pHead1);
	SListPushBack(&pHead1, 1);
	SListPushBack(&pHead1, 3);
	SListPushBack(&pHead1, 6);
	SListPushBack(&pHead1, 8);
	PrintfSList(pHead1);

	SListInit(&pHead2);
	SListPushBack(&pHead2, 2);
	SListPushBack(&pHead2, 5);
	SListPushBack(&pHead2, 7);

	SListBack(pHead2)->_pNext = SListFind(pHead1, 3);
	PrintfSList(pHead2);

	if(IsSListCross(pHead1, pHead2))
	{
		PNode pRet = GetCorssNode(pHead1, pHead2);
		printf("相交: %d \n", pRet->_data);
	}
	else
		printf("不相交!!!\n");
}

void TestSListCrossWithCircle()
{
	PNode pHead1, pHead2, pEnterNode, pMeetNode;
	int ret = 0;
	SListInit(&pHead1);
	SListPushBack(&pHead1, 1);
	SListPushBack(&pHead1, 2);
	SListPushBack(&pHead1, 3);
	SListPushBack(&pHead1, 4);
	SListPushBack(&pHead1, 5);
	SListPushBack(&pHead1, 6);
	SListPushBack(&pHead1, 7);
	SListPushBack(&pHead1, 8);
	
	SListBack(pHead1)->_pNext = SListFind(pHead1, 5);
	pMeetNode = IsListWithCircle(pHead1);
	pEnterNode = GetCircleEnter(pHead1, pMeetNode);
	if(pEnterNode)
	{
		printf("环的长度为：%d\n", GetCircleLen(pMeetNode));
		printf("环的入口点为：%d\n", pEnterNode->_data);
	}
	SListInit(&pHead2);
	SListPushBack(&pHead2, 1);
	SListPushBack(&pHead2, 2);
	SListPushBack(&pHead2, 3);
	SListBack(pHead2)->_pNext = SListFind(pHead1, 2);

	ret = IsSListCrossWithCircle(pHead1, pHead2);
	if(1 == ret)
		printf("两个链表不带环相交!!!\n");
	else if(2 == ret)
		printf("两个链表军带环相交!!!\n");
	else
		printf("两个链表不相交!!!\n");
}