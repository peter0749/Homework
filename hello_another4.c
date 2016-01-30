#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	while(1)
	{
		putchar('h');putchar('e');putchar('l');putchar('l');putchar('o');putchar(',');putchar(' ');
		fputs(stdin,stdout);
	}
	return 0;
}

