#include<stdio.h>

int main(void)
{
	int x=1, y=0, N=0, i=0, k=0, result=0;
	while(x!=0)
	{
		scanf("%d", &x);
		if(x==0)
			return 0;
		scanf("%d", &y);
		scanf("%d", &N);
		if(y==1)
		{
			result=x%N;
			printf("%d\n", result);
			return 0;
		}
		k = 1;
		x %= N;
		for(i=0; i<y; i++)
		{
			k *= x;
			k %= N;
		}
		result = k;
		printf("%d\n", result);
		x = 1;
	}
	return 0;
}
