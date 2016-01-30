/*
 d[] for data,
 p[0]=0, p[i] = p[i-1] + d[i];
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100005

int DP[MAX] = {0};
int data[MAX] = {0};

void fix_input(int*,int*);
void cal_dp(int);
int search(int, int);

int main(void)
{
	int i, n, q;
	int min, max;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++)
		scanf("%d",&data[i]);
	cal_dp(n);
	while(q--)
	{
		scanf("%d %d",&min, &max);
		fix_input(&min,&max);
		printf("%d",search(min,max));
		if(q>0)
			printf("\n");
	}

	return 0;
}

int search(int min, int max)
{
	return DP[max] - DP[min-1];
}

void cal_dp(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		DP[i] = DP[i-1] + data[i];
	}
}

void fix_input(int *a,int *b)
{
	int temp;
	if(*a>*b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}
