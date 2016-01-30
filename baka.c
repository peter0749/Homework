#include <stdio.h>

void main(void)
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n", 50 + (((n*42925)+(2-3*n)*1275+50*(2*n-2))/2));
	}
	return;
}
