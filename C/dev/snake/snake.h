#define _SNAKE_H_H_H

//??游?界面大小，?里?置?15*15
int const COL = 15;
int const ROW = 15;

//蛇??
typedef struct Node
{
	int x;
	int y;
	struct Node *pre;
	struct Node *next;
}NODE, *pNODE;

//食物
typedef struct Food
{
	int x;
	int y;
	char c;
}FOOD, *pFOOD;

//初始化，?建蛇的第一?
pNODE InitSnake(void);

//初始化食物成?
FOOD InitFood(void);

//蛇??函?
int MoveSnake(pNODE pHead, char c);

//?查??按?
char KbHit(char orient);

//蛇吃到食物?理函?
pNODE SnakeEatFood(pNODE pHead, pFOOD pFood);

//打印游?界面函?
void Print(pNODE pHead, FOOD food);

//游??束，?放?存函?
void FreeMemory(pNODE *ppHead);

