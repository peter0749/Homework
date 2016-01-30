#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	int input;
	int i;
	int count;
	scanf("%d",&n);
	while(n--)
	{
		count = 0;
		scanf("%d",&input);
		for(i=2;i<=input;i++)
		{
			if(input % i == 0)
			{
				do
				{
					input /= i;
					count++; 
					
				}while(input % i == 0);
				if(n == 0 && input == 1)
					printf("%d\n%d",i,count);
				else
					printf("%d\n%d\n",i,count);
			}
			count = 0;
		}
		
		if(n > 0)
			printf("\n");
		
	}
	
	return 0;
} 
