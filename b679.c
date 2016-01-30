#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int big_sqrt(long long int);

/*int my_log(long long int);
long long int my_pow(long long int, int);*/

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

		/*
		else
		{
			logx = my_log(x);
			logx += 4;
			logx /= 2;
			temp = my_pow(2,logx);
			temp--;
			temp /= 2;
		}*/

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
/*
int my_log(long long int input)
{
	int i=0;
	while(input >= 2)
	{
		input /= 2;
		i++;
	}
	return i;
}

long long int my_pow(long long int a, int b)
{
	long long int base=1;
	int i;
	for(i=0;i<b;i++)
	{
		base *= a;
	}
	return base;
}
*/
