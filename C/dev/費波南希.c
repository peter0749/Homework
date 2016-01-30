#include <stdio.h>
#include <stdlib.h>
int main(){
	int i,n;
	printf("A[1]=A[2]=1\nA[n]=A[n-1]+A[n-2]\nA[n]=?\nPlease enter n:");
	scanf("%d",&n);
	unsigned long x[n];
	x[1]=1;
	x[2]=1;
	if(n==1){
		printf("F=1");
	}
	else if(n==2){
		printf("F=1,1");
	}
	else{
	printf("\nF=1,1");
		for(i=3;i<=n;i++){
			x[i]=x[i-1]+x[i-2];
			printf(",%u",x[i]);
			}
	}
	printf("\n");
	system("pause");
	return 0;
}
