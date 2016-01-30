#include <stdio.h>
#include <stdlib.h>
#define MAX 65536

int bitmap[MAX] = {0};
int list[6543] = {0};

int is_prime(int);
void mk_p(void);

int main(void)
{
	int input, term;
	mk_p();
	scanf("%d",&term);
	while(term--)
	{
		scanf("%d",&input);
		printf(is_prime(input) ? "Y\n":"N\n");
	}
	return 0;
}

void mk_p(void)
{
	int i, j;
	int count = 0;
	for(i=3;i<MAX;i++)
	{
		if(bitmap[i]==0)
		{
			for(j=i+i;j<MAX;j+=i)
			{
				bitmap[j] = 1;
			}
			list[count++] = i;
		}
	}
	/*printf("--count = %d",count);*/

}

int is_prime(int n)
{
	int i;
	if(n == 2)
		return 1;
	else if(n % 2 == 0)
		return 0;
	else if(n<MAX)
		return !bitmap[n];
	else
	{
		for(i=0;list[i]*list[i]<=n && list[i]!=0;i++)
		{
			if(n%list[i]==0)
				return 0;
		}
		return 1;
	}
}
