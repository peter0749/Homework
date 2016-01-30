#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 10000
#define NUM 1000

char a[NUM+1][MAX];
void cal(void);
void mul(int n);
void rev(char c[]);

int main(void)
{
	int n;
	memset(a,'\0',sizeof(char)*MAX*(NUM+1));
	cal();

	while(scanf("%d",&n)!=EOF)
	{
		printf("%d!\n%s\n",n,a[n]);
	}
	return 0;
}

void cal(void)
{
	int i;
	a[0][0] = '1';
	a[1][0] = '1';
	a[2][0] = '2';
	for(i=3;i<=NUM;i++)
	{
		mul(i);
	}
	for(i=3;i<=NUM;i++)
		rev(a[i]);
}

void mul(int n)
{
	char temp[5];
	int len = strlen(a[n-1]);
	int tlen;
	int i, j;
	int final;
	sprintf(temp,"%d",n);
	rev(temp);
	tlen = strlen(temp);
	for(i=0;i<len;i++)
	{
		for(j=0;j<tlen;j++)
		{
			a[n][i+j] += (a[n-1][i]-'0') * (temp[j] - '0');
			while(a[n][i+j] > 9)
			{
				a[n][i+j+1] += a[n][i+j]/10;
				a[n][i+j] %= 10;
			}
		}
	}
	for(i=len+tlen;a[n][i]==0;i--);
	for(i;i>=0;i--)
		a[n][i] += '0';
}

void rev(char c[])
{
	int i;
	int len = strlen(c);
	char temp;
	for(i=0;i<len/2;i++)
	{
		temp = c[i];
		c[i] = c[len-1-i];
		c[len-1-i] = temp;
	}
}
