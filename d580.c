#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int bitmap[MAX][MAX] = {{0}};

int ch_dir(int);

int main(void)
{
	/*freopen("out.txt","w",stdout);*/
	int fail_count;
	int t;
	int i,j,k;
	int dir;
	int n;
	scanf("%d",&t);
	while(t--)
	{
		fail_count = 0;
		scanf("%d",&n);
		i = j = (n-1)/2;
		k = 1;
		dir = 1;
		while(1)
		{
			if(fail_count > 1)
			{
				bitmap[i][j] = k;
				break;
			}
			switch(dir)
			{
				case 1:
					if(j+1>n-1 || bitmap[i][j+1]!=0)
					{
						dir = ch_dir(dir);
						fail_count++;
					}
					else
					{
						bitmap[i][j++] = k++;
						fail_count = 0;
					}
					break;
				case 2:
					if(i+1>n-1 || bitmap[i+1][j]!=0)
					{
						dir = ch_dir(dir);
						fail_count++;
					}
					else
					{
						bitmap[i++][j] = k++;
						fail_count = 0;
					}
					break;
				case 3:
					if(j-1<0 || bitmap[i][j-1]!=0)
					{
						dir = ch_dir(dir);
						fail_count++;
					}
					else
					{
						bitmap[i][j--] = k++;
						fail_count =0;
					}
					break;
				case 4:
					if(i-1<0 || bitmap[i-1][j]!=0)
					{
						dir = ch_dir(dir);
						fail_count++;
					}
					else
					{
						bitmap[i--][j] = k++;
						fail_count = 0;
					}
					break;
			}
		}
		for(k=0;k<n;k++)
		{
			for(dir=0;dir<n-1;dir++)
				printf("%4d ",bitmap[k][dir]);
			printf("%4d",bitmap[k][dir]);
			printf("\n");
		}
		memset(bitmap,0x00,sizeof(int)*MAX*MAX);
	}
	if(t>0)	printf("\n");
	return 0;
}

int ch_dir(int dir)
{
		return dir > 1 ? dir-1 : 4;
}
