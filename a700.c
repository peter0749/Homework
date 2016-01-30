#include <stdio.h>

int main(void)
{
    int INDEX;
    int i,j;
    long long int val;
    while(scanf("%d %d",&i,&j)!=EOF)
    {
	val=1;
	for(INDEX=0;INDEX<8*(i-1)+(j-1);INDEX++)
	{
	    val*=2;
	}
	printf("%lld\n",val);
    }
    return 0;
}
