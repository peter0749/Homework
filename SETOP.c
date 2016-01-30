#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000
unsigned long long int datain(char *str);
void IS_AND(char data [][MAX], char *a, char *b);
void IS_OR(char data [][MAX], char *a, char *b);
char *sop(char *ptr);

int main(void)
{
	char *ptr = NULL;
	int m , n , i;
	char temp[MAX];
	char data[51][MAX];
	scanf("%d %d\n",&m,&n);
	for(i=0;i<m;i++)
	{
		gets(data[i]);
	}
	while(n--)
	{
		gets(temp);
		ptr = sop(temp);
		//putchar(*(ptr));

		//puts(temp);
		//puts(ptr+2);
		if(*ptr=='*')
		{
		    *(ptr) = '\0';
			IS_AND(data,temp,ptr+1);
		}
		else
		{
		    *(ptr) = '\0';
			IS_OR(data,temp,ptr+1);
		}
	}

	return 0;
}

char *sop(char *ptr)
{
	while(ptr!=NULL && *ptr!='+' && *ptr!='*' && *ptr!='\0')ptr++;
	return ptr;
}

void IS_AND(char data [][MAX], char *a, char *b)
{
	unsigned long long int i;
	unsigned long long int set = 0;
	unsigned long long int ch;
	set |= datain(data[atoi(a)]);
	set &= datain(data[atoi(b)]);

	if(set==0)
	{
		printf("-1\n");
		return ;
	}

	for(i=0;i<26;i++)
	{
	    ch = set & (1uLL<<(i));
	    if(ch)
            printf("%c",i+'A' );
	}
	for(;i<52;i++)
	{
		ch = set & (1uLL<<(i));
	    if(ch)
            printf("%c",i-26+'a' );
	}
	printf("\n");
}

void IS_OR(char data [][MAX], char *a, char *b)
{
	unsigned long long int i;
	unsigned long long int set = 0;
	unsigned long long int ch;
	set |= datain(data[atoi(a)]);
	//printf("%llu",set);
	set |= datain(data[atoi(b)]);

	if(set==0)
	{
		printf("-1\n");
		return ;
	}

	for(i=0;i<26;i++)
	{
		ch = set & (1uLL<<(i));
	    if(ch)
            printf("%c",i+'A' );
	}
	for(;i<52;i++)
	{
		ch = set & (1uLL<<(i));
	    if(ch)
            printf("%c",i-26+'a' );
	}
	printf("\n");
}

unsigned long long int datain(char *str)
{
	int i;
	unsigned long long int set = 0;
	int len = strlen(str);
	for(i=0;i<len;i++)
	{
		if('A' <= *(str+i) && *(str+i) <= 'Z')
		{
			set |= (1uLL<<(*(str+i) - 'A'));
		}
		else if('a' <= *(str+i) && *(str+i) <= 'z')
		{
			set |= (1uLL<<(*(str+i) - 'a'+26));
		}
	}
	return set;
}
