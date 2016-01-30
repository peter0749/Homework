#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int input;
	int i, j;
	scanf("%d",&input);
	for(i=1;i<=input;i++)
	{
		printf("%d\n",i);
		for(j=1;j<=i;j++)
		{
			printf("%d\n",j);
		}
	}

	return 0;
}
