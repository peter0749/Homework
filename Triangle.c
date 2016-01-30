#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	int i ,j;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			for(j=n-i;j>0;j--)
			{
				printf(" ");
			}
			for(j=i;j>0;j--)
			{
				printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}
