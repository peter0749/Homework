/*Enterence at mtx(2,2), Exit at mtx(n-1,n-1)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if 1
#define DEBUG
#endif
#define MAX 104

int min_step = 2147483640;

void clean_mtx(int mtx[MAX][MAX])
{
	int i, j;
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)	mtx[i][j] = -1;
	}
}

int mouse_go(int x, int y, int mtx[MAX][MAX], int n, int step)
{
/*Track down the path with numbers "2s", and record the steps with "step"*/
	if(step>=min_step)	return 0;		//Not a best solution
	if(mtx[y][x]!=1)		//Not a road
	{
		return 0;
	}
	if(x==n-1&&y==n-1)		//Arrived, Printout the solution for debugging
	{
#ifdef DEBUG
		mtx[y][x] = 2;
		printf("\n");
		printmtx(mtx,n);
		printf("\nstep: %d\n",step);
		mtx[y][x] = 1;
#endif
		if(step<min_step)	min_step = step;
		return 1;
	}

	mtx[y][x] = 2; //Track down the path on map

	if( mouse_go(x,y+1,mtx,n,step+1) + 	//Right
		mouse_go(x,y-1,mtx,n,step+1) + 	//Left
		mouse_go(x+1,y,mtx,n,step+1) + 	//Down
		mouse_go(x-1,y,mtx,n,step+1))		//Up
	{
		mtx[y][x] = 1;	//Recover the map
		return 1;		//At least one solution found.
	}
	else				//No solution, return 0
	{
		mtx[y][x] = 1;
		return 0;
	}
	
}
#ifdef DEBUG
void printmtx(int mtx[MAX][MAX], int n)
{
	int i, j;
	for(i=0;i<=n+1;i++)
	{
		printf("\n");
		for(j=0;j<=n+1;j++)
		{
			if(mtx[i][j]==1)
				printf(". ");
			else if(mtx[i][j]==2)
				printf("@ ");
			else if(mtx[i][j]==0)
				printf("# ");
			else
				printf("! ");
		}
	}
}
#endif
int main(void)
{
	int n;
	int i, j;
	char temp[MAX];
	int mtx[MAX][MAX];
	while((gets(temp))!=NULL)
	{
		min_step = 2147483640;
		clean_mtx(mtx);
		n = atoi(temp);
		for(i=1;i<=n;i++)
		{
			gets(temp);
			for(j=0;j<n;j++)
			{
				if(*(temp+j)=='#')
					mtx[i][j+1] = 0;
				else if(*(temp+j)=='.')
					mtx[i][j+1] = 1;
				else
					mtx[i][j+1] = -1;
			}
		}
#ifdef DEBUG
		printf("\nOrigin:\n");
		printmtx(mtx,n);
#endif
		if(mouse_go(2,2,mtx,n,1)==0)
			printf("No solution!\n");
		else
			printf("%d\n",min_step);
	}
	return 0;
}
