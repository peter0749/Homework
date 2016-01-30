#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i,n;
	int sum;
	while(scanf("%d",&n)!=EOF)
	{
		sum = 0;
		for(i=1;i<=n;i++)
			sum += i;
		printf("%d\n",sum);
	}

	return 0;	
}
