#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char ch[10000];
	while((gets(ch))!=NULL)
	{
		printf("hello, ");
		puts(ch);
	}
	return 0;
}

