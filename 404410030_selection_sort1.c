#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int nums[1002];
	int temp;
	int n;
	int i ,j ,min; /*INDEX*/
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",nums+i);
		}

		for(i=0;i<n-1;i++)
		{
			min = i;
			for(j=i+1;j<n;j++)
			{
				if(nums[j]<nums[min])
					min = j;
			}
			if(min != i)
			{
				temp = nums[min];
				nums[min] = nums[i];
				nums[i] = temp;
			}
		}

		for(i=0;i<n;i++)
			printf("%d ",nums[i]);

		printf("\n");
	}
	return 0;
}
