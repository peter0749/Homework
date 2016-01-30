#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

int count(char *a, char *b);

int main(void)
{
	char temp[MAX];
	char src[MAX];
	char tar[MAX];
	while((fgets(temp,MAX,stdin))!=NULL)
	{
		sscanf(temp,"%s %s",tar,src);
		printf("%d\n",count(tar,src));
	}
	return 0;
}

int count(char *a, char *b)
{
	int na = strlen(a);
	int nb = strlen(b);
	int i, j;
	int count = 0;
	int ok;
	for(i=0;i<=nb-na;i++)
	{
		ok = 1;
		for(j=0;j<na;j++)
		{
			if(*(a+j) != *(b+i+j))
				ok = 0;
		}
		if(ok == 1)
			count++;
	}
	return count;
}
