#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int first = 1;
	int nums[1002];
	int count, temp;
	int n;
	int i ,j ,min; /*INDEX*/
	//freopen("testinput.txt","r",stdin);
	//freopen("testoutput.txt","w+",stdout);
	while(1)
	{
		count = 0;
		scanf("%d",&n);
		if(n == 0)
			exit(0);
		if(first == 1)
			first = 0;
		else
			printf("\n");
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
		{
			for(i=0;i<n;i++)
                printf("%d ",nums[i]);
		}
		else
		{
			for(i=0;i<3;i++)
			printf("%d ",nums[i]);
		}

		printf("%d",count);
		//printf("\n");
	}
	return 0;
}
