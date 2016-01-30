#include <stdio.h>
#include <math.h>
void odd_or_not(int);
int main(){
	int test;
	while(scanf("%d",&test)!=EOF){
		odd_or_not(test);
	}
}
void odd_or_not(int n){
	int i,buffer;
	if(n==1)	printf("獶借计\n");
	else if(n==2)	printf("借计\n");
	else if(n==3)	printf("借计\n");
	else{
	buffer=sqrt(n);
	/*printf("buffer=%d\n",buffer);*/
		for(i=2;i<=buffer;i++){
			if(n%i==0){
				printf("獶借计\n");
				break;
			}
			else if(i==buffer && n%i!=0){
				printf("借计\n");
			}
		}
	}
}


