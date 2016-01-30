#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j;
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				if(j>0)
					printf(" ");
				printf("%d",comb(i,j));
			}
			printf("\n");
		}

	}

	return 0;
}

int comb(int n, int m)
{
	if(n==m || m==0)
		return 1;
	return comb(n-1,m) + comb(n-1,m-1);
}
