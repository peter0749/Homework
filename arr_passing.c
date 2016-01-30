#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

void bubble_sort(char (*arr)[5][20], int score[]);

int main(void)
{
	int i;
	int score[MAX] = {45,12,78,89,12};
	char name[MAX][20] ={"Andy","Marry","Peter","Jack","Jason"};
	for(i=0;i<MAX;i++)
	{
		printf("%s\t%d\n",name+i,score[i]);
	}
	bubble_sort(&name, score);
	for(i=0;i<MAX;i++)
	{
		printf("%s\t%d\n",name+i,score[i]);
	}


	return 0;
}

void bubble_sort(char (*arr)[5][20], int score[])
{
	int i, j;
	for(i=0;i<5;i++)
		printf("%s\n",(*arr)[i]);
	
	int temp;
	char ch[100];
	for(i=MAX-2;i>=0;i--)
	{
		for(j=0;j<=i;j++)
		{
			if(score[j]>score[j+1])
			{
				temp = score[j];
				score[j] = score[j+1];
				score[j+1] = temp;
				strcpy(ch, (*arr)[j]);
				strcpy((*arr)[j],(*arr)[j+1]);
				strcpy((*arr)[j+1],ch);
			}
		}
	}
}
