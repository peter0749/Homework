#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

int cmp(char *a, char *b,int flag, int n);

int main(void)
{
	char n[MAX], m[MAX];
	int i;
	int sum, len, nlen;
	while(scanf("%s %s",n,m)!=EOF)
	{
		sum = 0;
		nlen = strlen(n);
		len = strlen(m) - nlen;
		for(i=0;i<=len;i++)
		{
			sum += cmp(m,n,i,nlen);
		}
		printf("%d\n",sum);
	}

	return 0;
}

int cmp(char *a, char *b,int flag, int n)
{
	while(n--)
	{
		if(*(a+flag+n) != *(b+n))
			return 0;
	}
	return 1;
}
