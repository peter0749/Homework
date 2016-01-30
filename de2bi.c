#include <stdio.h>
#include <stdlib.h>
#define T 2
#define MAXdig 32

int main(void)
{
	char dig[MAXdig];
	int i, j;
	int count;

	while(scanf("%d",&i)!=EOF)
	{
		if(i == 0)
		{
			printf("0\n");
			continue;
		}
		count = 0;
		j=0;
		while(i != 0)
		{
			dig[j++] = i % T + '0';
			i /= T;
		}
		j--;
		for(i=j;i>=0;i--)
			printf("%c",dig[i]);
		printf("\n");
	}
	return 0;
}
