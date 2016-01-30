#include <stdio.h>
int main(){
	int n,i,j,searchNum,num=-1;
	printf("循序搜尋法\n");
	printf("您要輸入幾組數字?");
	scanf("%d",&j);
	int data[j];
	printf("請連續輸入%d個數字:",j);
	for(i=0;i<j;i++){
		scanf("%d",&data[i]);
	}
	printf("\n\n請輸入欲輸入的值:");
	scanf("%d",&searchNum);
	for(i=0;i<j;i++){
		if(searchNum==data[i]){
			num=i+1;
		}
	}
	if(num==-1){
		printf("無%d這個數值",searchNum);
	}
	else{
		printf("您輸入的%d是第%d個數字\n",searchNum,num);
	}
	system("pause");
	return 0;
}
