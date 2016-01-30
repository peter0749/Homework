#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main(void)
{
	char fstr[MAX];
	while(fgets(stdout,MAX,stdin)!=NULL)
	{
		putchar('h');putchar('e');putchar('l');putchar('l');putchar('o');putchar(',');putchar(' ');
	}
	return 0;
}

