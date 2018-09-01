#pragma once

typedef struct Position
{
	int _x;
	int _y;
}Position;

#define MAX_ROW 4
#define MAX_COL 4
//#include "Stack.h"

extern struct Stack;
typedef struct Stack Stack;

typedef struct Maze
{
	int _map[MAX_ROW][MAX_COL];
}Maze;


///////////////////////////////////////////////////
// Maze.h
void InitMaze(Maze* m, int map[][MAX_COL]);
void PrintMaze(Maze* m, int map[][MAX_COL]);
int IsPass(Maze* m, Position cur);
int IsValidEntry(Maze* m, Position entry);
int IsExit(Maze* m, Position cur, Position entry);
void PassMaze(Maze* m, Position entry, Stack* s);



//////////////////////////////////////////////////
// Maze.c
void TestMaze();

