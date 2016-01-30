#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int first = 1;
	int nums[201];
	int count, temp;
	int n;
	int i ,j ,min; /*INDEX*/
	freopen("testoutput.txt","w+",stdout);
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
				count++;
			}
		}
		
		if(n < 3)
			printf("%d %d ",nums[0],nums[1]);
		else
		{
			for(i=0;i<3;i++)
			printf("%d ",nums[i]);
		}

		printf("%d",count);
	}
	return 0;
}
