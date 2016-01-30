#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str[1000001] = {0};

int main(void)
{
	int n;
	int i;
	int ok;
	int first;
	while(scanf("%d",&n)!=EOF)
	{
		first = 1;
		ok = 0;
		for(i=2;i<=n;i++)
		{
			while(n%i == 0)
			{
				ok = 1;
				n /= i;
				str[i]++;
			}
		}
		/*
		for(i=2;i<=10;i++)
			printf("--%d\n",str[i]);
		*/
		if(ok == 0)
			printf("%d",n);
		else
		{
			for(i=2;i<=1000000;i++)
			{
				if(str[i]!=0)
				{
					if(first == 0)
						printf(" * ");
					first = 0;
					if(str[i] == 1)
						printf("%d",i);
					else
						printf("%d^%d",i,str[i]);
				}
			}
		}
		printf("\n");
		memset(str,0x00,sizeof(int)*1000001);
	}
	return 0;
}
