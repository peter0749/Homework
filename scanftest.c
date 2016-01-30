#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char c;
	while(1)
	{
		scanf(" %c",&c);
		printf("Command:");
		switch(c)
		{
			case '0':
				printf("%c\n",c);
				break;
			case '1':
				printf("%c\n",c);
				break;
			default:
				printf("default\n");
				break;
		}
	}

	return 0;
}
