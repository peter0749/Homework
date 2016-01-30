#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define MAX 20

int maze[MAX][MAX] = {0};

int recu(int exit, int y, int x)
{
	if(x==exit && y==exit)
	{
		maze[y][x] = 2;
		return 1;
	}
	if(maze[y][x]==0)
	{
		maze[y][x] = 2;
		if( ( recu(exit,y,x+1)||recu(exit,y+1,x)||	\
		recu(exit,y,x-1)||recu(exit,y-1,x) ) )
			return 1;
		maze[y][x] = 0;
		return 0;
	}
	
	return 0;
}

int main(void)
{
	char temp[1000];
	char *ptr;
	int i = 0, j = 0;
	int dim = 0;
	while((gets(temp))!=NULL)
	{
		i = j = dim = 0;
		ptr = strtok(temp," \n");
		while(ptr!=NULL)
		{
			maze[0][j++] = atoi(ptr);
			ptr = strtok(NULL," \n");
		}
		dim = j;
		for(i=1;i<dim;i++)
		{
			for(j=0;j<dim;j++)
				scanf("%d",&maze[i][j]);
		}
		
		if(recu(dim-2,1,1))
		{
			for(i=0;i<dim;i++)
			{
				for(j=0;j<dim-1;j++)
				{
					if(maze[i][j]==2)
						printf("# ",maze[i][j]);
					else
						printf("%d ",maze[i][j]);
				}
				if(maze[i][j]==2)
						printf("#\n",maze[i][j]);
				else
						printf("%d\n",maze[i][j]);
			}
		}
	}
	
	return 0;
} 
