#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int poly(int n, int a[], int c[]);

int main(void)
{
	int term;
	int input[MAX] = {0}, ans[MAX] = {0};
	int d, i, n;
	scanf("%d",&term);
	while(term--)
	{
		n = 0;
		memset(ans,0x00,sizeof(int)*MAX);
		ans[0] = 1;
		for(i=2;i>=0;i--)
			scanf("%d",&input[i]);
		scanf("%d",&d);
		for(i=0;i<d;i++)
			n = poly(n,input,ans);
		for(i=n;i>=1;i--)
			printf("%d ",ans[i]);
		printf("%d\n",ans[i]);
	}
	return 0;
}

int poly(int n, int a[], int c[])
{
	int i, j;
	int temp[MAX];
	for(i=0;i<=n;i++)
	{
		temp[i] = c[i];
		c[i] = 0;
	}
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=n;j++)
			c[i+j] += temp[j] * a[i];
	}
	return n+2;
}
