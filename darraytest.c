#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int i;
	int n;	/*SIZE to assign*/
	
	scanf("%d",&n);	/*Size for dynamic allocation*/
	
	int *ptr = NULL;
	ptr = (int*)malloc(sizeof(int)*n);
	if(ptr == NULL)
	{
		printf("Failed...\n");	
		exit(-1);	/*If malloc fails, return -1.*/
	}
	
	memset(ptr,-1,sizeof(int)*n);	/*Initialize ptr*/
	
	for(i=0;i<n;i++)
		printf("%2d",*(ptr+i));		/*-1 -1 -1 -1......*/

	return 0;
}
