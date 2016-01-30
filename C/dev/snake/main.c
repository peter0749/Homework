#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include  "snake.h"
//�D��?
int main(void)
{
	char orien = 'a', get_char;
	int game_over = 0;

	FOOD food = InitFood();
	pNODE head = InitSnake();

	while (1)
	{
		head = SnakeEatFood(head, &food);
		get_char = KbHit(orien);
		if (27 == get_char)
		{
			game_over = 1;
			break;
		}
		else
			orien = get_char;	
		game_over = MoveSnake(head, orien);
		if (game_over)
			break;
		
		system("cls");
		Print(head, food);
		Sleep(200); //ms?�A���?�j??
	}
	if (game_over)
	{
		printf("��??���I\n");

		FreeMemory(&head);
		if (NULL == head)
			printf("?�s?�񦨥\�I\n");
		else
			printf("?�s?��?�I\n");
	}
	getch();
	return 0;
}
//��l�ơA?�سD���Ĥ@?
pNODE InitSnake(void)
{
	pNODE pHead = (pNODE)malloc(sizeof(NODE));
	srand((unsigned)(time(NULL)+1));

	if (NULL == pHead)
	{
		printf("?�s���t��?�I\n");
		exit(-1);
	}
	
	pHead->x = rand() % ROW;
	pHead->y = rand() % COL;
	pHead->next = NULL;
	pHead->pre = NULL;

	return pHead;
}
//��l�ƭ�����?
FOOD InitFood(void)
{
	FOOD food;
	srand((unsigned)time(NULL));

	food.x = rand() % ROW;
	food.y = rand() % COL;
	food.c = 65 + rand()%26;

	return food;
}
//�D�Y�쭹��?�z��?
pNODE SnakeEatFood(pNODE pHead, pFOOD pFood)
{
	pNODE p_add = NULL, pt = NULL, rear = NULL;
	
	if (pFood->x == pHead->x && pFood->y == pHead->y)
	{
		p_add = (pNODE)malloc(sizeof(NODE));
		if (NULL == p_add)
		{
			printf("?�s���t��?�I\n");
			exit(-1);
		}

		pt = pHead;
		while (pt->next != NULL)
		{
			pt = pt->next;
		}
		p_add->pre = pt;
		p_add->next = NULL;
		pt->next = p_add;

		*pFood = InitFood();
		//��?�����X?�b�D����m�W
		pt = pHead;
		while (pt != NULL)
		{
			if (pFood->x == pHead->x && pFood->y == pHead->y)
			{
				*pFood = InitFood();
				break;
			}
			pt = pt->next;
		}
	}

	return pHead;
}
//?�d??��?
char KbHit(char orient)
{	
	char c;

	if (kbhit())
	{
		c = getch();	
		if (orient != 'd' && c == 'a')
		{
			orient = c;
		}
		else if (orient != 'a' && c == 'd')
		{
			orient = c;
		}
		else if (orient != 'w' && c == 's')
		{
			orient = c;
		}
		else if (orient != 's' && c == 'w')
		{
			orient = c;
		}
		else if (27 == c)
		{
			orient = c;
		}
	}

	return orient;
}
//�D??��?
int MoveSnake(pNODE pHead, char c)
{
	INT game_over = 0;
	pNODE pt = pHead;

	//?pt���V�D��
	while (pt->next != NULL)
	{
		pt = pt->next;
	}

	//?�D���V�V�D?�e?
	while(pt != pHead)
	{
		pt->x = pt->pre->x;
		pt->y = pt->pre->y;
		pt = pt->pre;
	}

	if ('d' == c)
	{
		pHead->x += 1;
		if (pHead->x >= ROW)
		{
			pHead->x -= ROW;
		}
	}

	if ('a' == c)
	{
		pHead->x -= 1;
		if (pHead->x < 0)
		{
			pHead->x += ROW;
		}
	}
	
	if ('s' == c)
	{
		pHead->y += 1;
		if (pHead->y >= COL)
		{
			pHead->y -= COL;
		}
	}

	if ('w' == c)
	{
		pHead->y -= 1;
		if (pHead->y < 0)
		{
			pHead->y += COL;
		}
	}

	//?�D?�I��D���A��??��
	pt = pHead->next;
	while (pt != NULL)
	{
		if (pt->x == pHead->x && pt->y == pHead->y)
		{
			game_over = 1;
		}
		pt = pt->next;
	}

	return game_over;
}
//���L��?�ɭ���?
void Print(pNODE pHead, FOOD food)
{
	int row = 0, col = 0, flag = 0;
	pNODE pt = NULL;

	printf("  ��V����X�X�W:w �U:s ��:a �k:d(Esc�h�X)\n  ");
	for (row=0; row<ROW; row++)
	{
		printf("�X");
	}
	putchar('\n');

	for (col=0; col<COL; col++)
	{
		printf(" |");
		for (row=0; row<ROW; row++)
		{
			pt = pHead;
			flag = 0;
			//���L�X�D
			while (pt != NULL)
			{
				if (row == pt->x && col == pt->y)
				{
					if (pt == pHead)
						printf("��");
					else
						printf("��");
					flag = 1;
					break;
				}
				pt = pt->next;
			}
			//���L�X������??�Ů�
			if (0 == flag)
			{
				if (row == food.x && col == food.y)
				{
					putchar(food.c);
					putchar(food.c);
					continue;
				}
				printf("  ");
			}		
		}
		printf("|");
		putchar('\n');
	}
	
	printf("  ");
	for (row=0; row<ROW; row++)
	{
		printf("�X");
	}
	putchar('\n');
}
//?��?�s��?
void FreeMemory(pNODE *ppHead)
{
	pNODE p_delete = NULL, pt = NULL;

	while (*ppHead != NULL)
	{
		pt = (*ppHead)->next;
		if (pt != NULL)
		{
			pt->pre = NULL;
		}	
		p_delete = *ppHead;
		free(p_delete);
		p_delete = NULL;
		*ppHead = pt;
	}
}
