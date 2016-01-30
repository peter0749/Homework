#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int temp;
	int i=0;
	int t[3]={0};
	for(i=0;i<3;i++)
	{
		scanf("%d",&t[i]);
	}
	for(i=0;i<2;i++)
	{
		if(t[i] > t[i+1])
		{
			temp=t[i];
			t[i]=t[i+1];
			t[i+1]=temp;
		}
	}
	temp = t[0]*t[0] + t[1]*t[1];
	if(temp > t[2]*t[2])
		printf("1\n");
	else if(temp < t[2]*t[2])
		printf("2\n");
	else 
		printf("3\n");

	return 0;
}
