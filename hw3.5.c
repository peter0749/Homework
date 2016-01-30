#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int i;
	int count[4] = {0};
	int first_run = 1;
	int input;
	while(scanf(" %d",&input)!=EOF)
	{
		if(first_run == 1)
			first_run = 0;
		else
			printf("\n");
		if(input >= 50)
		{
			count[0] += input/50;
			input %= 50;
		}
		if(input >= 10)
		{
			count[1] += input/10;
			input %= 10;
		}
		if(input >= 5)
		{
			count[2] += input/5;
			input %= 5;
		}
		count[3] = input;
		for(i=0;i<4;i++)
		{
			if(i>0)
				printf(" ");
			printf("%d",count[i]);
		}
		memset(count,0x00,4);
	}

	return 0;
}
