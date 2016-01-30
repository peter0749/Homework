#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 105

int map_in[MAX][MAX] = {{0}};
int map_out[MAX][MAX] = {{0}};

void printout(int n, int m);

int main(void)
{
	//freopen("testout.txt","w+",stdout);

	int i, j;
	int m,n;
	int term;
	scanf("%d",&term);
	while(term--)
	{
		memset(map_out,0x00,sizeof(int)*MAX*MAX);
		memset(map_in,-1,sizeof(int)*MAX*MAX);
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				scanf("%d",&map_in[i+1][j+1]);
		}
		printout(n,m);
		if(term>0)
			printf("\n");
	}
	return 0;
}

void printout(int n, int m)
{
	int ok;
	int i, j;
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<m+1;j++)
		{
			if(map_in[i][j]==1)
			{
				ok = 0;
				if(map_in[i+1][j]==0)
					ok = 1;
				else if(map_in[i-1][j]==0)
					ok = 1;
				else if(map_in[i][j+1]==0)
					ok = 1;
				else if(map_in[i][j-1]==0)
					ok = 1;
				else
					ok = 0;
				if(ok == 1)
					map_out[i-1][j-1] = 1;
			}
		}
	}
#if 0
	for(i=0;i<n;i++)		/*For debugging*/
	{
		for(j=0;j<m;j++)
			printf("%d",map_out[i][j]);
		printf("\n");
	}
#endif
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(map_out[i][j]==1)
				printf("0");
			else
				printf("_");
		}
		printf("\n");
	}
}
