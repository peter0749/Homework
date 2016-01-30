#include <stdio.h>
#include <stdlib.h>

int main(void){
	int i,n,*ptr=NULL,search_Num,num=-1;
	printf("請問要輸入幾個整數:");
	scanf("%d",&n);
	ptr=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		printf("請輸入第%2d個整數:",i+1);
		scanf("%d",ptr+i);
		printf("\n");
	}
	printf("\n請輸入要搜尋的數值:");
	scanf("%d",&search_Num);
	for(i=0;i<n;i++){
		if(*(ptr+i)==search_Num){
			num=i+1;
			break;
		}
	}
	if(num==-1)	printf("找不到%2d此數值!\n",search_Num);
	else	printf("%2d是第%2d個數字\n",search_Num,num);
	free(ptr);
	
	
	return 0;
}
