#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int first_run = 1;
	int i;
	int sum;
	char str[100];
	while(scanf("%s",str)!=EOF)
	{
		if(first_run == 1)
			first_run = 0;
		else
			printf("\n");
		sum = 0;
		for(i=0;str[i]!='\0';i++)
		{
			sum += (str[i]-'0');
		}
		printf("%d",sum);
		str[0] = '\0';
		memset(str,0x00,100);
	}

	return 0;
}
