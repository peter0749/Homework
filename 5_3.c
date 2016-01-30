#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	int i,j;
	int num;
	int first;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&num);
		for(i=1;i<=num;i++)
		{
			first = 1;
			for(j=1;j<=i;j++)
			{
				if(first != 1)
				{
					printf(" %d",j);
				}
				else
				{
					printf("%d",j);
					first = 0;
				}
			}
			if(n == 0 && i == num)
				break;
			
			printf("\n");
		}
		if(n != 0)
		{
			printf("\n");
		}
	}
	
	return 0;
} 
