#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1001

int main(void)
{
	int term, max;
	char temp[MAX];
	int count[26] = {0};
	int i;
	fgets(temp,MAX,stdin);
	term = atoi(temp);
	while(term--)
	{
		memset(count,0x00,sizeof(int)*26);
		fgets(temp,MAX,stdin);
		for(i=0;i<strlen(temp);i++)
		{
			if(temp[i]>='a' && temp[i]<='z' || temp[i]>='A' && temp[i]<='Z')
			{
				count[toupper(temp[i])-'A']++;
			}
		}
		max = 0;
		for(i=0;i<26;i++)
		{
			if(max < count[i])
				max = count[i];
		}
		for(i=0;i<26;i++)
		{
			if(count[i]==max)
				printf("%c",'A'+i);
		}
		printf("\n");
	}
	return 0;
}
