#include <stdio.h>
#include <stdlib.h>
#define MAX 60

void sort(int n, int data[]);
void prt(int n, int data[]);

int main(void)
{
	//freopen("ar12_test.in","r",stdin);
	//freopen("testout.out","w",stdout);
	int data[MAX];
	int ncase;
	int i, n;
	scanf("%d",&ncase);
	while(ncase--)
	{
		i = 0;
		do{
			scanf("%d",&data[i++]);
		}while(data[i-1]!=-999);
		n = i-1;
		sort(n,data);
		prt(n,data);
		if(ncase>0)
			printf("\n");
	}

	return 0;
}

void sort(int n, int data[])
{
	int temp;
	int i ,j, max;
	for(i=0;i<n-1;i++)
	{
		max = i;
		for(j=i+1;j<n;j++)
		{
			if(data[j]>data[max])
				max = j;
		}
		if(max!=i)
		{
			temp = data[i];
			data[i] = data[max];
			data[max] = temp;
		}
	}
}

void prt(int n, int data[])
{
	int i ,j;
	int count = 1;
	for(i=0;i<n;i++)	/*data[n] == -999*/
	{
		if(data[i]==data[i+1])
			count++;
		else
		{
			printf("%d %d\n",data[i],count);
			count = 1;
		}
	}
}
