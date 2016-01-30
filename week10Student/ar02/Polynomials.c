#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

int f_add(int n, int a[], int c[]);

int main(void)
{
	//freopen("ar02_test.in","r",stdin);
	//freopen("testout.txt","w+",stdout);
	int ncase;
	int i, n, d;
	int a[MAX] = {0}, c[MAX] = {0};
	scanf("%d",&ncase);
	while(ncase--)
	{
		memset(c,0x00,sizeof(int)*MAX);
		c[0] = 1; c[1] = 0; c[2] = 0;
		scanf("%d %d %d %d",&a[2],&a[1],&a[0],&d);
		n = 0;
		for(i=0;i<d;i++)
			n = f_add(n,a,c);
		for(i=n;i>=1;i--)
			printf("%d ",c[i]);
		printf("%d\n",c[i]);
	}

	return 0;
}

int f_add(int n, int a[], int c[])
{
	int i ,j;
	int temp[MAX];
	for(i=0;i<=n;i++)
	{
		temp[i] = c[i];
		c[i] = 0;
	}
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=n;j++)
			c[i+j] += temp[j]*a[i];
	}
	return n+2;
}
