#include <stdio.h>
int main(){
	int data[5];
	int n,i,searchNum,num=-1;
	printf("循序搜尋法\n");
	printf("請連續輸入五個數值\n\n");
	printf("請輸入:");
	for(i=0;i<5;i++){
		scanf("%d",&n);
		data[i]=n;
	}
	printf("\n");
	printf("請輸入欲搜尋的值:");
	scanf("%d",&searchNum);
	for(i=0;i<5;i++){
		if(data[i]==searchNum){
			num=i;
		}
	}
	printf("===========================================\n");
	if(num==-1){
		printf("無此數:%d\n",searchNum);
	}
	else{
		printf("您輸入的%d是第%d個數字\n",searchNum,(num+1));
	}
	system("pause");
	return 0;
}
