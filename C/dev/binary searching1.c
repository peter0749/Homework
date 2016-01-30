#include <stdio.h>
int main(){
	int i,j,n,t,searchNum,num=-1,low=0,high=8,midNum=0,data[9];
	printf("3x3矩陣排序+二分排序,請輸入:\n");
	for(i=0;i<3;i++){
		for(j=3*i;j<3*(i+1);j++){
			scanf("%d",&data[j]);
		}
	}
	//Bubble sorting;
	for(i=7;i>=0;i--){
		for(j=0;j<=i;j++){
			if(data[j]>data[j+1]){
				t=data[j];
				data[j]=data[j+1];
				data[j+1]=t;
			}
		}
	}
	//After sorting;
	printf("After sorting:\n");
	for(i=0;i<3;i++){
		for(j=3*i;j<3*(i+1);j++){
			printf("%d ",data[j]);
		}
	printf("\n");
	}
	printf("請輸入欲搜尋的值:");
	scanf("%d",&searchNum);
	//Binary searching;
	do{
		midNum=(low+high)/2;
		if(searchNum==data[midNum]){
			num=midNum;
			break;
		}
		if(searchNum>data[midNum]){
			low=midNum+1;
		}
		else{
			high=midNum+1;
		}
	}while(low<=high);
	if(num==-1){
		printf("找不到%d這個數!\n",searchNum);
	}
	else{
		i=(num/3)+1;
		j=(num%3)+1;
		printf("您輸入的%d位於第%d行第%d列\n",searchNum,j,i);
	}
	system("pause");
	return 0;
}
