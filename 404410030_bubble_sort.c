#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int first = 1;
	int nums[201];
	int count, temp;
	int n;
	int i ,j; /*INDEX*/
	/*freopen("testoutput.txt","w+",stdout);*/
	while(1)
	{
		if(first == 1)
			first = 0;
		else
			printf("\n");

		count = 0;
		scanf("%d",&n);
		if(n == 0)
			exit(0);
		for(i=0;i<n;i++)
		{
			scanf("%d",nums+i);
		}
		for(i=n-2;i>=0;i--)
		{
			for(j=0;j<=i;j++)
			{
				if(nums[j]>nums[j+1])
				{
					temp = nums[j];
					nums[j] = nums[j+1];
					nums[j+1] = temp;
					count++;
				}
			}
		}
		printf("%d",count);
	}
	return 0;
}
