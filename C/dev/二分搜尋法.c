#include <stdio.h>
int main(){
	int data[5];
	int n,i,j,t;
	int searchNum,num=-1,low=0,high=4,midNum=0;
	printf("二分搜尋法\n");
	printf("請連續輸入五個數值\n\n排序前:");
	for(i=0;i<5;i++){
		scanf("%d",&data[i]);
	}
	for(i=3;i>=0;i--){
		for(j=0;j<=i;j++){
			if(data[j]>data[j+1]){
				t=data[j];
				data[j]=data[j+1];
				data[j+1]=t;
			}
		}
	}
	printf("排序後:");
	for(i=0;i<5;i++){
		printf(" %d",data[i]);
	}
	printf("\n請輸入要搜尋的數字:");
	scanf("%d",&searchNum);
	do{
		midNum=(low+high)/2;
		if(data[midNum]==searchNum){
			num=midNum;
			break;
		}
		if(data[midNum]>searchNum){
			high=midNum-1;
		}
		else{
			low=midNum+1;
		}
	}while(low<=high);
	if(num==-1){
		printf("無此數%d\n",searchNum);
	}
	else{
		printf("您輸入的%d是第%d個數\n",searchNum,(num+1));
	}
	system("pause");
	return 0;
} 
