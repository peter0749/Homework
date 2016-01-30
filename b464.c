#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	double temp;
	int min,sec;
	int data;
	int rate,n;
	while(scanf("%d %d",&rate ,&n)!=EOF)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&data);
		temp = (double)n / rate;
		if(temp >= 60)
		{
			min = (int)temp / 60;
			temp = temp / 60;
			temp *= 10;
			temp += 5;
			sec = (int)temp / 10;
		}
		else
		{
			temp *= 10;
			temp += 5;
			temp /= 10;
			sec = (int)temp;
			min = 0;
		}
		if(sec > 9)
			printf("%d:%d\n",min,sec);
		else 
			printf("%d:0%d\n",min,sec);

	}

	return 0;
}
