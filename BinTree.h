#pragma once

typedef char BTDataType;
typedef struct BinTreeNode
{
	struct BinTreeNode* _pLeft;
	struct BinTreeNode* _pRight;
	BTDataType _data;
}BTNode, *PBTNode;


#include <malloc.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "Queue.h"
#include "Stack.h"

PBTNode BuyBinTreeNode(BTDataType data)
{
	PBTNode pNewNode = (PBTNode)malloc(sizeof(BTNode));
	if(NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}

	pNewNode->_pLeft = NULL;
	pNewNode->_pRight = NULL;
	pNewNode->_data = data;
	return pNewNode;
}

void _CreateBinTree(PBTNode* pRoot, const BTDataType* array, int size, int* index, BTDataType invalid)
{
	assert(pRoot);
	assert(index);
	if(*index < size && invalid != array[*index])
	{
		// 创建根节点
		*pRoot = BuyBinTreeNode(array[*index]);

		// 创建根节点的左子树
		++(*index);
		_CreateBinTree(&(*pRoot)->_pLeft, array, size, index, invalid);

		// 创建根节点的右子树
		++(*index);
		_CreateBinTree(&(*pRoot)->_pRight, array, size, index, invalid);
	}
}


void PreOrder(PBTNode pRoot)
{
	if(pRoot)
	{
		printf("%c ", pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}

void PreOrderNor(PBTNode pRoot)
{
#if 0
	Stack s;
	if(NULL == pRoot)
		return;

	StackInit(&s);
	StackPush(&s, pRoot);

	while(!StackEmpty(&s))
	{
		PBTNode pCur = StackTop(&s);
		printf("%c ", pCur->_data);
		StackPop(&s);

		if(pCur->_pRight)
			StackPush(&s, pCur->_pRight);

		if(pCur->_pLeft)
			StackPush(&s, pCur->_pLeft);
	}
#endif

	Stack s;
	if(NULL == pRoot)
		return;

	StackInit(&s);
	StackPush(&s, pRoot);

	while(!StackEmpty(&s))
	{
		PBTNode pCur = StackTop(&s);
		StackPop(&s);

		while(pCur)
		{
			printf("%c ", pCur->_data);
			if(pCur->_pRight)
				StackPush(&s, pCur->_pRight);

			pCur = pCur->_pLeft;
		}
	}
}

void InOrder(PBTNode pRoot)
{
	if(pRoot)
	{
		InOrder(pRoot->_pLeft);
		printf("%c ", pRoot->_data);
		InOrder(pRoot->_pRight);
	}
}

void InOrderNor(BTNode* pRoot)
{
	BTNode* pCur = pRoot;
	Stack s;
	if(NULL == pRoot)
		return;

	StackInit(&s);
	while(pCur || !StackEmpty(&s))
	{
		// 找以pCur为根最左侧的结点，并保存路径中所遇到的所有的结点
		while(pCur)
		{
			StackPush(&s, pCur);
			pCur = pCur->_pLeft;
		}

		pCur = StackTop(&s);
		printf("%c ", pCur->_data);
		StackPop(&s);
		pCur = pCur->_pRight;
	}
}

void PostOrder(PBTNode pRoot)
{
	if(pRoot)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c ", pRoot->_data);
	}
}

void PostOrderNor(BTNode* pRoot)
{
	BTNode* pCur = pRoot;
	BTNode* pTop = NULL;
	// 标记最近访问过的结点
	BTNode* pPrev = NULL;
	Stack s;
	
	if(NULL == pRoot)
		return;

	StackInit(&s);

	while(pCur || !StackEmpty(&s))
	{
		// 找以pCur为根的树最左侧的结点，并保存所经过路径中的所有节点
		while(pCur)
		{
			StackPush(&s, pCur);
			pCur = pCur->_pLeft;
		}

		pTop = StackTop(&s);
		if(NULL == pTop->_pRight || pPrev == pTop->_pRight)
		{
			printf("%c ", pTop->_data);
			pPrev = pTop;
			StackPop(&s);
		}
		else
			pCur = pTop->_pRight;
	}
	
}

void LevelOrder(PBTNode pRoot)
{
	Queue q;
	if(NULL == pRoot)
		return;

	QueueInit(&q);
	QueuePush(&q, pRoot);

	while(!QueueEmpty(&q))
	{
		PBTNode pCur = QueueFront(&q);
		printf("%c ", pCur->_data);
		//QueuePop(&q);

		if(pCur->_pLeft)
			QueuePush(&q, pCur->_pLeft);

		if(pCur->_pRight)
			QueuePush(&q, pCur->_pRight);

		QueuePop(&q);
	}
}

void CreateBinTree(PBTNode* pRoot, const BTDataType* array, int size, BTDataType invalid)
{
	int index = 0;
	_CreateBinTree(pRoot, array, size, &index, invalid);
}

PBTNode CopyBinTree(PBTNode pRoot)
{
	PBTNode pNewRoot = NULL;
	if(pRoot)
	{
		pNewRoot = BuyBinTreeNode(pRoot->_data);

		// 拷贝根节点的左子树
		if(pRoot->_pLeft)
			pNewRoot->_pLeft = CopyBinTree(pRoot->_pLeft);

		// 拷贝根节点的右子树
		if(pRoot->_pRight)
			pNewRoot->_pRight = CopyBinTree(pRoot->_pRight);
	}

	return pNewRoot;
}

// 销毁
void DestroyBinTree(PBTNode *pRoot)
{
	assert(pRoot);
	if(*pRoot)
	{
		DestroyBinTree(&(*pRoot)->_pLeft);
		DestroyBinTree(&(*pRoot)->_pRight);
		free(*pRoot);
		*pRoot = NULL;
	}
}

void Swap(PBTNode* pLeft, PBTNode* pRight)
{
	PBTNode pTemp = NULL;
	assert(pLeft);
	assert(pRight);

	pTemp = *pLeft;
	*pLeft = *pRight;
	*pRight = pTemp;
}

void MirrorBinTree(PBTNode pRoot)
{
	if(pRoot)
	{
		Swap(&pRoot->_pLeft, &pRoot->_pRight);
		MirrorBinTree(pRoot->_pLeft);
		MirrorBinTree(pRoot->_pRight);
	}
}

void MirrorBinTreeNor(PBTNode pRoot)
{
	Queue q;

	if(NULL == pRoot)
		return;

	QueueInit(&q);
	QueuePush(&q, pRoot);

	while(!QueueEmpty(&q))
	{
		PBTNode pCur = QueueFront(&q);
		Swap(&pCur->_pLeft, &pCur->_pRight);

		if(pCur->_pLeft)
			QueuePush(&q, pCur->_pLeft);

		if(pCur->_pRight)
			QueuePush(&q, pCur->_pRight);

		QueuePop(&q);
	}
}

int BinTreeSize(PBTNode pRoot)
{
	if(NULL == pRoot)
		return 0;

	return BinTreeSize(pRoot->_pLeft) + BinTreeSize(pRoot->_pRight) + 1;
}

int GetLeafCount(PBTNode pRoot)
{
	if(NULL == pRoot)
		return 0;

	if(NULL == pRoot->_pLeft && NULL == pRoot->_pRight)
		return 1;

	return GetLeafCount(pRoot->_pLeft) + GetLeafCount(pRoot->_pRight);
}

int Height(PBTNode pRoot)
{
	int leftHeight, rightHeight;
	if(NULL == pRoot)
		return 0;

	leftHeight = Height(pRoot->_pLeft);
	rightHeight = Height(pRoot->_pRight);

	return leftHeight > rightHeight? leftHeight+1 : rightHeight + 1;
}

int GetKLevelNode(PBTNode pRoot, int K)
{
	if(NULL == pRoot || K < 1)
		return 0;

	if(1 == K)
		return 1;

	return GetKLevelNode(pRoot->_pLeft, K-1) + GetKLevelNode(pRoot->_pRight, K-1);
}

BTNode* Find(BTNode* pRoot, BTDataType data)
{
	BTNode* pRet = NULL;
	if(NULL == pRoot)
		return NULL;

	if(data == pRoot->_data)
		return pRoot;

	if(pRet = Find(pRoot->_pLeft, data))
		return pRet;

	return Find(pRoot->_pRight, data);

	return NULL;
}


int IsNodeInBinTree(BTNode* pRoot, BTNode* pNode)
{
	int ret = 0;
	if(NULL == pRoot || NULL == pNode)
		return 0;

	if(pRoot == pNode)
		return 1;

	if(ret = IsNodeInBinTree(pRoot->_pLeft, pNode))
		return ret;

	return IsNodeInBinTree(pRoot->_pRight, pNode);
}

int IsCompleteBinTree(BTNode* pRoot)
{
	Queue q;
	int flag = 0;
	if(NULL == pRoot)
		return 1;

	QueueInit(&q);
	QueuePush(&q, pRoot);

	while(!QueueEmpty(&q))
	{
		BTNode* pCur = QueueFront(&q);
		
		if(flag)
		{
			if(pCur->_pLeft || pCur->_pRight)
				return 0;
		}
		else
		{
			if(pCur->_pLeft && pCur->_pRight)
			{
				QueuePush(&q, pCur->_pLeft);
				QueuePush(&q, pCur->_pRight);
			}
			else if(pCur->_pLeft)
			{
				QueuePush(&q, pCur->_pLeft);
				flag = 1;
			}
			else if(pCur->_pRight)
				return 0;
			else
				flag = 1;
		}

		QueuePop(&q);
	}

	return 1;
}


void TestBinTree()
{
	const char* str = "ABD###CE##F";
	PBTNode pRoot = NULL;
	PBTNode pNewTree = NULL;
	CreateBinTree(&pRoot, str, strlen(str), '#');
	if(IsCompleteBinTree(pRoot))
		printf("是完全二叉树!\n");
	else
		printf("不是完全二叉树!\n");

	printf("PreOrder: ");
	PreOrder(pRoot);
	printf("\n");

	MirrorBinTree(pRoot);
	MirrorBinTreeNor(pRoot);

	printf("PreOrder: ");
	PreOrder(pRoot);
	printf("\n");
	
	printf("PreOrder: ");
	PreOrderNor(pRoot);
	printf("\n");

	printf("InOrder: ");
	InOrder(pRoot);
	printf("\n");

	printf("InOrderNor: ");
	InOrderNor(pRoot);
	printf("\n");

	printf("PostOrder: ");
	PostOrder(pRoot);
	printf("\n");

	printf("PostOrderNor: ");
	PostOrderNor(pRoot);
	printf("\n");

	printf("LevelOrder: ");
	LevelOrder(pRoot);
	printf("\n");

	pNewTree = CopyBinTree(pRoot);
	printf("PreOrder: ");
	PreOrder(pNewTree);
	printf("\n");

	printf("二叉树中结点的个数为：%d\n", BinTreeSize(pRoot));
	printf("二叉树中叶子结点的个数为：%d\n", GetLeafCount(pRoot));
	printf("二叉树中的高度为：%d\n", Height(pRoot));
	printf("二叉树中第3层结点的个数为：%d\n",GetKLevelNode(pRoot, 3));

	DestroyBinTree(&pRoot);
	DestroyBinTree(&pNewTree);
}