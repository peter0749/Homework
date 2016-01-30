#include <stdio.h> 
#include <stdlib.h>

int main(void)
{
	int i;
	char str[20];
	while(1)
	{
		gets(str);
		if(str[0]=='#')	break;
		for(i=0;i<19 && str[i]!=' ';i++)
		{
			printf("%c",str[i]);
		}
	}
	return 0;
} 


