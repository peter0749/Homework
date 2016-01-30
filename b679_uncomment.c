#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int big_sqrt(long long int);

int main(void)
{
	long long int temp;
	double dl;
	long long int x;
	while(scanf("%lld",&x)!=EOF)
	{
		if(x < 576460752303423488)
		{
			temp = (big_sqrt(8*x+1) -1)/2;
			printf("%lld\n",temp);
		}

		else
		{
			dl = (double)x;
			dl *= 8;
			dl++;
			dl = sqrt(dl);
			dl--;
			dl /= 2;
			printf("%d\n",(int)dl);	
		}
	}
	return 0;
}

long long int big_sqrt(long long int input)
{
	long long int i;
	for(i=1;i*i<=input;i++);
	return i;
}
