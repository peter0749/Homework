#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int times,i;
	int a,b,c;
	while(scanf("%d",&times)!=EOF)
	{
		for(i=0;i<times;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			if(a==1)
			{
				printf("%d",b+c);
			}
			else if(a==2)
			{
				printf("%d",b-c);
			}
			else if(a==3)
			{
				printf("%d",b*c);
			}
			else if(a==4)
			{
				printf("%d",b/c);
			}
			printf("\n");
		}
	}
	
	return 0;
}
