#include <stdio.h>
#include <stdlib.h>

void q_sort(long long int*,int,int);

int main(void)
{
	int i=0;
	int input;
	while(scanf("%d",&input)!=EOF)
	{
		long long int *ptr;
		ptr=(long long int*)malloc(sizeof(long long int)*(input));
		for(i=0;i<input;i++)
		{
			scanf("%lld",ptr+i);
		}
		q_sort(ptr,0,input-1);
		for(i=0;i<input;i++)
		{
			printf("%lld ",*(ptr+i));
		}
		printf("\n");
		free(ptr);
	}
	
	return 0;
}

void q_sort(long long int *ptr,int left,int right)
{
	int i,j;
	long long int pivot,temp;
	if(left<right)
	{
		i=left;
		j=right+1;
		pivot=*(ptr+left);
		do{
			do{
				i++;
			}while(*(ptr+i)<pivot);
			do{
				j--;
			}while(*(ptr+j)>pivot);
			if(i<j)
			{
				temp=*(ptr+i);
				*(ptr+i)=*(ptr+j);
				*(ptr+j)=temp;
			}
		}while(i<j);
		
		temp=*(ptr+left);
		*(ptr+left)=*(ptr+j);
		*(ptr+j)=temp;
		q_sort(ptr,left,j-1);
		q_sort(ptr,j+1,right);
	}
	
}

