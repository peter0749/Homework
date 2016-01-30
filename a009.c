#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char str;
	while(EOF != (str = getchar()))
	{
		if(str == '\n')
			putchar('\n');
		else
			printf("%c",str-7);
	}
	return 0;
}
