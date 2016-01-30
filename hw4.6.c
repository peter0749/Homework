#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int temp;
	int i;/*INDEX*/
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

	printf(t[0] + t[1] > t[2] ? "1\n":"0\n");

	return 0;
}
