#include <stdio.h>
#include <stdlib.h>

int rev(int n);

int main(void)
{
	int input, reverse, term;
	int count;
	scanf("%d",&term);
	while(term--)
	{
		count = 0;
		scanf("%d",&input);
		reverse = rev(input);
		while(input!=reverse)
		{
			input += reverse;
			reverse = rev(input);
			count++;
		}
		printf("%d %d",count,input);
		if(term>0)
			printf("\n");
	}
	return 0;
}

int rev(int n)
{
	int sum = 0;
	do
	{
		sum*=10;
		sum += (n%10);
		n/=10;
	}while(n!=0);
	return sum;
}
