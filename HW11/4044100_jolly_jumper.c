#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100000

void sort(int *p, int n);
void asub(int *data, int *sum, int n);
int cond(int *sum, int n);

int main(void)
{
	int term, n;
	int i;
	int data[MAX] = {0}, sub[MAX] = {0};
	scanf("%d\n",&term);
	while(term--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf(" %d",&data[i]);
		asub(data,sub,n);
		printf(cond(sub,n-1) ? "Jolly":"Not jolly");
		if(term > 0)
			printf("\n");
	}

	return 0;
}

void sort(int *p, int n)
{
	int min, temp;
	int i, j;
	for(i=0;i<n-1;i++)
	{
		min = i;
		for(j=i+1;j<n;j++)
		{
			if(*(p+min) > *(p+j))
				min = j;
		}
		if(min!=i)
		{
			temp = *(p+i);
			*(p+i) = *(p+min);
			*(p+min) = temp;
		}
	}
}

void asub(int *data, int *sum, int n)
{
	int i;
	for(i=0;i<n-1;i++)
	{
		*(sum+i) = abs(*(data+i) - *(data+i+1));
	}
	sort(sum,n-1);
}

int cond(int *sum, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(*(sum+i) != i+1)
			return 0;
	}
	return 1;
}
