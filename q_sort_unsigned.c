#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void q_sort(unsigned int*,int,int);

int main(void)
{
	int i=0;
	int input;
	unsigned int *ptr;
	ptr=(unsigned int*)malloc(sizeof(unsigned int)*1000000);
	memset(ptr,0x00,sizeof(unsigned int)*1000000);
	while(scanf("%d",&input)!=EOF)
	{
		for(i=0;i<input;i++)
		{
			scanf("%u",ptr+i);
		}
		q_sort(ptr,0,input-1);
		for(i=0;i<input;i++)
		{
			printf("%u ",*(ptr+i));
		}

		printf("\n");
	}



	return 0;

}



void q_sort(unsigned int *ptr,int left,int right)

{

	int i,j;
	unsigned int temp, pivot;

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

