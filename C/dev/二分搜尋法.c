#include <stdio.h>
int main(){
	int data[5];
	int n,i,j,t;
	int searchNum,num=-1,low=0,high=4,midNum=0;
	printf("�G���j�M�k\n");
	printf("�гs���J���Ӽƭ�\n\n�Ƨǫe:");
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
	printf("�Ƨǫ�:");
	for(i=0;i<5;i++){
		printf(" %d",data[i]);
	}
	printf("\n�п�J�n�j�M���Ʀr:");
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
		printf("�L����%d\n",searchNum);
	}
	else{
		printf("�z��J��%d�O��%d�Ӽ�\n",searchNum,(num+1));
	}
	system("pause");
	return 0;
} 
