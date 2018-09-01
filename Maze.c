#include "Maze.h"
#include "Stack.h"

#include <stdio.h>
#include <assert.h>

#if 0
void InitMaze(Maze* m, int map[][MAX_COL])
{
	int i, j;
	if(NULL == m)
		return;

	for(i = 0; i < MAX_ROW; ++i)
	{
		for(j = 0; j < MAX_COL; ++j)
			m->_map[i][j] = map[i][j];
	}
}

int IsValidEntry(Maze* m, Position entry)
{
	assert(m);
	if(0 == entry._x || entry._x == MAX_ROW-1 ||
		0 == entry._y || entry._y == MAX_COL-1 )
	{
		return 1 == m->_map[entry._x][entry._y];
	}

	return 0;
}

int IsPass(Maze* m, Position cur)
{
	if(1 == m->_map[cur._x][cur._y])
		return 1;

	return 0;
}

int IsExit(Maze* m, Position cur, Position entry)
{
	if(cur._x == entry._x && cur._y == entry._y)
		return 0;

	if(0 == cur._x || MAX_ROW-1 == cur._x ||
	   0 == cur._y || MAX_COL-1 == cur._y )
	{
		return 1;
	}

	return 0;
}

void PassMaze(Maze* m, Position entry, Stack* s)
{
	Position cur, next;
	if(!IsValidEntry(m, entry))
	{
		printf("非法的迷宫入口!!!\n");
		return;
	}

	StackPush(s, entry);

	while(!StackEmpty(s))  //s->top
	{
		cur = StackTop(s);
		m->_map[cur._x][cur._y] = 2;
		if(IsExit(m, cur, entry))
			return;

		// 上
		next = cur;
		next._x -= 1;
		if(IsPass(m, next))
		{
			StackPush(s, next);
			continue;
		}

		// 左
		next = cur;
		next._y -= 1;
		if(IsPass(m, next))
		{
			StackPush(s, next);
			continue;
		}

		// 右
		next = cur;
		next._y += 1;
		if(IsPass(m, next))
		{
			StackPush(s, next);
			continue;
		}

		// 下
		next = cur;
		next._x += 1;
		if(IsPass(m, next))
		{
			StackPush(s, next);
			continue;
		}


		// cur步走错
		StackPop(s);
		m->_map[cur._x][cur._y] = 3;
	}
}


void PrintMaze(Maze* m, int map[][MAX_COL])
{
	int i, j;
	if(NULL == m)
		return;

	for(i = 0; i < MAX_ROW; ++i)
	{
		for(j = 0; j < MAX_COL; ++j)
			printf("%d ", m->_map[i][j]);

		printf("\n");
	}
}
#endif

#if 0
void InitMaze(Maze* m, int map[][MAX_COL])
{
	int i, j;
	if(NULL == m)
		return;

	for(i = 0; i < MAX_ROW; ++i)
	{
		for(j = 0; j < MAX_COL; ++j)
			m->_map[i][j] = map[i][j];
	}
}

int IsValidEntry(Maze* m, Position entry)
{
	assert(m);
	if(0 == entry._x || entry._x == MAX_ROW-1 ||
		0 == entry._y || entry._y == MAX_COL-1 )
	{
		return 1 == m->_map[entry._x][entry._y];
	}

	return 0;
}

int IsPass(Maze* m, Position cur)
{
	if(1 == m->_map[cur._x][cur._y])
		return 1;

	return 0;
}

int IsExit(Maze* m, Position cur, Position entry)
{
	if(cur._x == entry._x && cur._y == entry._y)
		return 0;

	if(0 == cur._x || MAX_ROW-1 == cur._x ||
		0 == cur._y || MAX_COL-1 == cur._y )
	{
		return 1;
	}

	return 0;
}

int _PassMaze(Maze* m, Position entry, Position cur,Stack* s)
{
	if(IsPass(m, cur))
	{
		Position next;
		m->_map[cur._x][cur._y] = 2;
		if(IsExit(m, cur, entry))
			return 1;

		// 上
		next = cur;
		next._x -= 1;
		if(_PassMaze(m, entry, next, s))
			return 1;

		// 左
		next = cur;
		next._y -= 1;
		if(_PassMaze(m, entry, next, s))
			return 1;

		// 右
		next = cur;
		next._y += 1;
		if(_PassMaze(m, entry, next, s))
			return 1;
		
		// 下
		next = cur;
		next._x += 1;
		if(_PassMaze(m, entry, next, s))
			return 1;

		m->_map[cur._x][cur._y] = 3;
	}

	return 0;
}

void PassMaze(Maze* m, Position entry, Stack* s)
{
	if(!IsValidEntry(m, entry))
	{
		printf("迷宫的入口非法!!!\n");
		return;
	}

	_PassMaze(m, entry, entry, s);
}


void PrintMaze(Maze* m, int map[][MAX_COL])
{
	int i, j;
	if(NULL == m)
		return;

	for(i = 0; i < MAX_ROW; ++i)
	{
		for(j = 0; j < MAX_COL; ++j)
			printf("%d ", m->_map[i][j]);

		printf("\n");
	}
}


void TestMaze()
{
	int map[MAX_ROW][MAX_COL] = {
	{0, 0, 0, 0},
	{0, 1, 1, 1},
	{0, 1, 0, 0}};
	Stack s;
	Position entry;
	Maze m;
	InitMaze(&m, map);
	PrintMaze(&m, map);
	printf("\n");

	StackInit(&s);
	entry._x = 2;
	entry._y = 1;
	PassMaze(&m, entry, &s);
	PrintMaze(&m, map);
}
#endif

void InitMaze(Maze* m, int map[][MAX_COL])
{
	int i, j;
	if(NULL == m)
		return;

	for(i = 0; i < MAX_ROW; ++i)
	{
		for(j = 0; j < MAX_COL; ++j)
			m->_map[i][j] = map[i][j];
	}
}

int IsValidEntry(Maze* m, Position entry)
{
	assert(m);
	if(0 == entry._x || entry._x == MAX_ROW-1 ||
	   0 == entry._y || entry._y == MAX_COL-1 )
	{
		return 1 == m->_map[entry._x][entry._y];
	}

	return 0;
}

int IsNextPass(Maze* m, Position cur, Position next)
{
	if(next._x < 0 || next._x == MAX_ROW || next._y < 0 || next._y == MAX_COL)
		return 0;

	// 如果迷宫没有走过  next--->1
	// 如果迷宫next位置已经走过  next > cur
	if(1 == m->_map[next._x][next._y] ||
	   m->_map[next._x][next._y] > m->_map[cur._x][cur._y])
		return 1;

	return 0;
}

int IsExit(Maze* m, Position cur, Position entry)
{
	if(cur._x == entry._x && cur._y == entry._y)
		return 0;

	if(0 == cur._x || MAX_ROW-1 == cur._x ||
	   0 == cur._y || MAX_COL-1 == cur._y )
	{
		return 1;
	}

	return 0;
}

void _SaveShortPath(Stack* path, Stack* shortPath)
{
	int i = 0, size;
	assert(path);
	assert(shortPath);

	size = StackSize(path);
	for(; i < size; ++i)
		shortPath->_array[i] = path->_array[i];

	shortPath->_top = i;
}

void _PassMaze(Maze* m, Position entry, Position cur, Stack* path, Stack* shortPath)
{
	Position next;
	if(StackEmpty(path))
		m->_map[cur._x][cur._y] = 2;

	StackPush(path, cur);
	if(IsExit(m, cur, entry))
	{
		if(StackEmpty(shortPath) || StackSize(path) < StackSize(shortPath))
			_SaveShortPath(path, shortPath);

		StackPop(path);
		return;
	}

	// 上
	next = cur;
	next._x -= 1; 
	if(IsNextPass(m, cur, next))
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		_PassMaze(m, entry, next, path, shortPath);
	}

	// 左
	next = cur;
	next._y -= 1; 
	if(IsNextPass(m, cur, next))
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		_PassMaze(m, entry, next, path, shortPath);
	}

	// 右
	next = cur;
	next._y += 1; 
	if(IsNextPass(m, cur, next))
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		_PassMaze(m, entry, next, path, shortPath);
	}

	// 下
	next = cur;
	next._x += 1; 
	if(IsNextPass(m, cur, next))
	{
		m->_map[next._x][next._y] = m->_map[cur._x][cur._y] + 1;
		_PassMaze(m, entry, next, path, shortPath);
	}

	StackPop(path);
}

void PassMaze(Maze* m, Position entry, Stack* shortPath)
{
	Stack path;
	// 检测迷宫入口合法性
	if(!IsValidEntry(m, entry))
	{
		printf("迷宫入口非法!!!\n");
		return;
	}

	StackInit(&path);
	_PassMaze(m, entry, entry, &path, shortPath);
}


void PrintMaze(Maze* m, int map[][MAX_COL])
{
	int i, j;
	if(NULL == m)
		return;

	for(i = 0; i < MAX_ROW; ++i)
	{
		for(j = 0; j < MAX_COL; ++j)
			printf("%d ", m->_map[i][j]);

		printf("\n");
	}
}

void PrintPath(Stack* path)
{
	Position top;
	while(StackSize(path) > 1)
	{
		top = StackTop(path);
		printf("<---[%d, %d]", top._x, top._y);
		StackPop(path);
	}

	top = StackTop(path);
	printf("[%d, %d]", top._x, top._y);
}

void TestMaze()
{
	int map[MAX_ROW][MAX_COL] = {
		{0, 0, 0, 0},
		{0, 1, 1, 0},
		{0, 1, 1, 1},
		{0, 1, 0, 0}};

		Stack shortPath;
		Position entry;
		Maze m;
		InitMaze(&m, map);
		PrintMaze(&m, map);
		printf("\n");

		StackInit(&shortPath);
		entry._x = 3;
		entry._y = 1;
		PassMaze(&m, entry, &shortPath);
		PrintMaze(&m, map);
		PrintPath(&shortPath);
}