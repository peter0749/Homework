#include <stdio.h>
#include <stdlib.h>
#define MAX 7
#define LEN MAX+1

void print_out_num(char*);

int main(void)
{
	int i;
	char input[LEN];
	while(scanf("%s",&input)!=EOF)
	{
			print_out_num(input+i);
		printf("\n");
	}
	
	return 0;
}

void print_out_num(char *input)
{
	char *ptr;
	ptr=input;
	int i;
	for(i=0;i<MAX-1;i++)
	{
		ptr=ptr+i;
		if(*(ptr)>*(ptr+1))
		{
			printf("%d",*(ptr)-*(ptr+1));
		}
		else if(*(ptr)<*(ptr+1))
		{
			printf("%d",*(ptr+1)-*(ptr));
		}
		else
		{
			printf("0");
		}
	}
}
