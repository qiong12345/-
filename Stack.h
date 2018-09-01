#pragma once

/*typedef int MinSDataType;*/

//typedef int QDataType;
//typedef QDataType DataType;
//typedef int DataType;
//typedef char DataType;

#define  MAX_SIZE 100

extern struct BinTreeNode;
typedef struct BinTreeNode* DataType;

typedef struct Stack
{
	DataType _array[MAX_SIZE];
	int _top;
}Stack;

void StackInit(Stack* s);
void StackPush(Stack* s, DataType data);
void StackPop(Stack* s);
DataType StackTop(Stack* s);
int StackSize(Stack* s);
int StackEmpty(Stack* s);


//////////////////////////////////////////////
//
void TestStack();
void TestMatchBrackets();
void TestRPN();