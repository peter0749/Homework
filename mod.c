#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int first = 1;
	int x, y, N;
	int base;
	int i;
	while(1)
	{
		base = 1;
		if(first == 1)
		{
			first = 0;
		}
		else
		{
			printf("\n");
		}
		
		scanf("%d",&x);
		if(x == 0)
			exit(0);
		
		scanf("%d %d",&y,&N);
		
		while(x > N)
		{
			x %= N;
		}		
		
		if(y == 0)
			{
				printf("1");
				continue;
			}
		
		for(i=0;i<y;i++)
		{
			
			base *= x;
		}
		base %= N;
		
		printf("%d",base);
		
	}
	
	return 0;
}
