#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int ch[26]={0};
	int term, max;
	char str[1000];
	int i;
	gets(str);
	term = atoi(str);
	while(term--)
	{
		gets(str);
		for(i=0;i<strlen(str);i++)
		{
			if(str[i] >= 'a'&& str[i]<= 'z' || str[i] >= 'A' && str[i] <= 'Z')	
			{
				ch[(toupper(str[i]))-'A']++;
			}
		}
		max = 0;
		for(i=0;i<26;i++)
		{
			if(max<ch[i])
				max = ch[i];
		}
		for(i=0;i<26;i++)
		{
			if(ch[i]==max)
				printf("%c",'A'+i);
		}
		if(term>0)
			printf("\n");
		memset(ch,0x00,sizeof(int)*26);
	}

	return 0;
}
