#include "Stack.h"
#include <assert.h>
#include <stdio.h>

void StackInit(Stack* s)
{
	assert(s);
	s->_top = 0;
}

void StackPush(Stack* s, DataType data)
{
	assert(s);
	if(s->_top == MAX_SIZE)
	{
		printf("Õ»ÒÑÂú!!!\n");
		return;
	}

	s->_array[s->_top] = data;
	s->_top++;
}

void StackPop(Stack* s)
{
	assert(s);
	if(StackEmpty(s))
	{
		printf("Õ»ÒÑ¿Õ!!!\n");
		return;
	}

	s->_top--;
}


DataType StackTop(Stack* s)
{
	assert(s);
	return s->_array[s->_top - 1];
}

int StackSize(Stack* s)
{
	assert(s);
	return s->_top;
}

int StackEmpty(Stack* s)
{
	assert(s);
	return 0 == s->_top;
}

#if 0
void TestStack()
{
	Stack s;
	StackInit(&s);

	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	printf("size = %d\n", StackSize(&s));
	printf("top = %d\n", StackTop(&s));

	StackPop(&s);
	printf("size = %d\n", StackSize(&s));
	printf("top = %d\n", StackTop(&s));
}

int IsBracket(char ch)
{
	if(('(' == ch || ')' == ch) ||
	   ('[' == ch || ']' == ch) ||
	   ('{' == ch || '}' == ch))
	{
		return 1;
	}

	return 0;
}

#include <string.h>
int MatchBrackets(const char* pStr)
{
	int len = 0, i = 0;
	Stack s;
	if(NULL == pStr)
		return 1;

	StackInit(&s);
	len = strlen(pStr);
	for(; i < len; ++i)
	{
		if(IsBracket(pStr[i]))
		{
			if('(' == pStr[i] || '[' == pStr[i] || '{' == pStr[i])
				StackPush(&s, pStr[i]);
			else
			{
				if(StackEmpty(&s))
				{
					printf("ÓÒÀ¨ºÅ±È×óÀ¨ºÅ¶à!!!\n");
					return 0;
				}
				else
				{
					// ÓÃµ±Ç°À¨ºÅºÍÕ»¶¥ÔªËØÆ¥Åä
					char top = StackTop(&s);
					if('(' == top && ')' == pStr[i] ||
						'[' == top && ']' == pStr[i] ||
						'{' == top && '}' == pStr[i])
					{
						StackPop(&s);
					}
					else
					{
						printf("×óÓÒÀ¨ºÅ´ÎÐòÆ¥ÅäÓÐÎó!!!\n");
						return 0;
					}
				}
			}
		}
	}

	if(!StackEmpty(&s))
	{
		printf("×óÀ¨ºÅ±ÈÓÒÀ¨ºÅ¶à!!!\n");
		return 0;
	}

	printf("À¨ºÅÆ¥ÅäÕýÈ·:)!!!\n");
	return 1;
}

void TestMatchBrackets()
{
	char a[] = "(())abc{[(])}";
	char b[] = "(()))abc{[]}";
	char c[] = "(()()abc{[]}";
	char d[] = "(())abc{[]()}";

	MatchBrackets(a);
	MatchBrackets(b);
	MatchBrackets(c);
	MatchBrackets(d);
}


typedef enum{ADD, SUB, MUL, DIV, DATA}OPERATOR;

typedef struct Cell
{
	OPERATOR _op;
	int _data;
}Cell;

int CalcRPN(const Cell* RPN, int size)
{
	int i;
	Stack s;
	StackInit(&s);
	for(i = 0; i < size; ++i)
	{
		if(DATA == RPN[i]._op)
			StackPush(&s, RPN[i]._data);
		else
		{
			int left, right;
			right = StackTop(&s);
			StackPop(&s);
			left = StackTop(&s);
			StackPop(&s);

			switch(RPN[i]._op)
			{
			case ADD:
				StackPush(&s, left+right);
				break;
			case SUB:
				StackPush(&s, left - right);
				break;
			case MUL:
				StackPush(&s, left * right);
				break;
			case DIV:
				if(0 == right)
				{
					printf("³ý·¨³ýÊýÎª0·Ç·¨!!!\n");
					return 0;
				}

				StackPush(&s, left / right);
				break;
			}
		}
	}

	return StackTop(&s);
}

void TestRPN()
{
	Cell RPN[] = {{DATA, 12}, {DATA, 3}, {DATA, 4}, {ADD, 0},
	              {MUL,   0}, {DATA, 6}, {SUB,  0}, {DATA,8}, 
	              {DATA,  2}, {DIV,  0}, {ADD,  0}};

	CalcRPN(RPN, sizeof(RPN)/sizeof(RPN[0]));
}
#endif