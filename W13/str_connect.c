#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 101
#define MAX 3010

void conn(char *a, char *b);

int main(void)
{
	int term;
	int times;
	char temp[LEN];
	char ans[LEN];
	int i;
	gets(temp);
	term  =  atoi(temp);
	while(term--)
	{
		gets(temp);
		times = atoi(temp)-1;
		gets(ans);
		while(times--)
		{
			gets(temp);
			conn(ans,temp);
		}
		printf("%d\n",strlen(ans));
		puts(ans);
		
	}
	return 0;
}

void conn(char *a, char *b)
{
	char *ptr=NULL;
	char *taila=NULL;
	int la = strlen(a);
	int lb = strlen(b);
	taila = a+(la+1);
	int i;
	if(la > lb)
		ptr = a+(la-lb);
	else
		ptr = a;
	while(ptr!=taila)
	{
		if(strncmp(ptr,b,strlen(ptr))==0)
		{
			strcpy(ptr,b);
			return;
		}
		ptr++;
	}
	strcat(a,b);
	return;
}
