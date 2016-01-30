#define _SNAKE_H_H_H

//??��?�ɭ��j�p�A?��?�m?15*15
int const COL = 15;
int const ROW = 15;

//�D??
typedef struct Node
{
	int x;
	int y;
	struct Node *pre;
	struct Node *next;
}NODE, *pNODE;

//����
typedef struct Food
{
	int x;
	int y;
	char c;
}FOOD, *pFOOD;

//��l�ơA?�سD���Ĥ@?
pNODE InitSnake(void);

//��l�ƭ�����?
FOOD InitFood(void);

//�D??��?
int MoveSnake(pNODE pHead, char c);

//?�d??��?
char KbHit(char orient);

//�D�Y�쭹��?�z��?
pNODE SnakeEatFood(pNODE pHead, pFOOD pFood);

//���L��?�ɭ���?
void Print(pNODE pHead, FOOD food);

//��??���A?��?�s��?
void FreeMemory(pNODE *ppHead);

