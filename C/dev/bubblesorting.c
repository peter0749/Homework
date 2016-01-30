#include <stdio.h>
int main(){
	int data[5];
	int n,i,j,t;
	printf("--Bubble sorting--\n");
	printf("Before sorting:\t ");
	for(i=0;i<5;i++){
		scanf("%d",&n);
		data[i]=n;
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
	printf("After sorting:\t");
	for(i=0;i<5;i++){
		printf(" %d",data[i]);
	}
	printf("\n");
	return 0;
} 
