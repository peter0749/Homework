#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int i;
	int *ptr;
	ptr = (int*)malloc(sizeof(int)*1000000000);    /*也是10^9, 動態配置記憶體*/
	if(ptr == NULL)
	{
		exit(-1);    /*記憶體配置失敗*/
	}
	memset(ptr,0x00,sizeof(int)*1000000000);    /*賦與初值0*/
		/*(略)*/
	for(i=0;i<1000000000;i++)
	{
		*(ptr+i) = 1;
	}
	printf("Safe... :-D\n");
		free(ptr);
	return 0;
}
