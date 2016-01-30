#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int first_run = 1;
	int pnum;
	while(scanf(" %d",&pnum)!=EOF)
	{
		if(first_run == 1)
			first_run = 0;
		else
			printf("\n");

		if(pnum % 3 == 0 && pnum % 5 != 0)
			printf("1");
		else if(pnum % 3 != 0 && pnum % 5 == 0)
			printf("1");
		else
			printf("0");
	}

	return 0;
}
