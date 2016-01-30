#include<stdio.h>
#include<math.h>
int main()
{
	double a;
	double d;
	int b, c, i;
	int in[101], fl[101];
	while(scanf("%lf", &a) == 1)
	{
		c = 0;
		b = (int) floor(a);
		d = (double) a - b;
		for(i = 0 ; ; i++)
		{
			in[i] = b % 2;
			b = b / 2;
			if(b == 0)
				break;
			c++;
		}
		for(i = c ; i >= 0 ; i--)
		{
			printf("%d", in[i]);
		}
		printf(".");
		c = 0;
		for(i = 0 ; ; i++)
		{
			fl[i] = (int) floor(d * 2);
			d = d * 2 - fl[i];
			if(d == 0 || i > 30)
				break;
			c++;
		}
		for(i = 0 ; i <= c ; i++)
		{
			printf("%d", fl[i]);
		}
		printf("\n");
	}
	return 0;
}
