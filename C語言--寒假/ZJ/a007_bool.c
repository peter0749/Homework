#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INTMAX 46341
#define LISTLEN 4800
#define TRUE false
#define FALSE true

int prime_list[LISTLEN] = {0};
bool set[INTMAX+1] = {TRUE};
int c=0;

bool is_prime(int );
void mk_prime(void);

int main(void)
{
	int n;
	mk_prime();
	while(scanf("%d",&n)!=EOF)
	{
		printf(is_prime(n)?"質數\n":"非質數\n");
	}
	return 0;
}

void mk_prime(void)
{
	int i, j;
	for(i=3;i<=INTMAX;i+=2)
	{
		if(set[i]==TRUE)
		{
			prime_list[c++] = i;
			for(j=i+i;j<=INTMAX;j+=i)
			{
				set[j] = FALSE;
			}
		}
	}
}

bool is_prime(int n)
{
	int i;
	if(n==2)	return true;
	if(n%2)
	{
		if(n<=INTMAX )	return !set[n];
		for(i=0;i<c&&prime_list[i]*prime_list[i]<=n;i++)
		{
			if(n%prime_list[i]==0)	return false;
		}
		return true;
	}
	return false;
}
