#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 40

void clean_up(int d[],int n)
{
	int i;
	for(i=0;i<n;i++)
		d[i]=0;
}

void rev_n(int d[], int n)
{
	int i;
	int temp;
	for(i=0;i<n/2;i++)
	{
		temp = d[i];
		d[i] = d[n-1-i];
		d[n-1-i] = temp;
	}
}

int b_add(int na, int nb,int a[],int b[], int c[])
{
	int i;
	int more;
	int nc;
	nc = na>nb?na:nb;
	for(i=0;i<nc;i++)
	{
		c[i] = a[i] + b[i];
	}
	for(i=0;i<nc;i++)
	{
		more = 0;
		if(c[i]>=10)
		{
			c[i+1] += c[i]/10;
			c[i] %= 10;
			more = 1;
		}
	}
	nc += more;
	return nc;
}

int main(void)
{
	int term;
	int a[MAX],b[MAX],c[MAX];
	char temp[100];
	char ch;
	int i, j;
	int na, nb, nc;
	gets(temp);
	term = atoi(temp);
	while(term--)
	{
		clean_up(a,MAX);
		clean_up(b,MAX);
		clean_up(c,MAX);
		scanf("%s",temp);
		i = 0;
		j = 0;
		while(1)
		{
			ch = temp[i++];
			if(ch==' '||ch=='\n'||ch=='\0')
				break;
			a[j++] = (ch-'0');
		}
		na = j;
		rev_n(a,na);
		scanf("%s",temp);
		i = 0;
		j = 0;
		while(1)
		{
			ch = temp[i++];
			if(ch==' '||ch=='\n'||ch=='\0')
				break;
			b[j++] = (ch-'0');
		}
		nb = j;
		rev_n(b,nb);
#if 0
		for(i=0;i<na;i++)
			printf("%d : %d\n",i,a[i]);
		for(i=0;i<nb;i++)
			printf("%d : %d\n",i,b[i]);
		nc = b_add(na,nb,a,b,c);
		for(i=0;i<nc;i++)
			printf("%d : %d\n",i,c[i]);
#endif
		nc = b_add(na,nb,a,b,c);
		for(i=nc-1;i>=0;i--)
			printf("%d",c[i]);
		printf("\n");
	}
	return 0;
}
