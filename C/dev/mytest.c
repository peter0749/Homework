#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 40000
#define MAXsqr 200
int bit_map[MAXsqr]={0},prime[MAXsqr]={0};
void make_prime(void);
int is_prime(int);
int main(){
	int input;
	make_prime();
	int i=0;
	/*printf("Done!\n");*/
	while(prime[i]!=0)
	{
		printf("%d\n",prime[i++]);
	}
	while(scanf("%d",&input)!=EOF){
		if(is_prime(input)==1)	printf("質數\n");
		else	printf("非質數\n");
	}
	return 0;
}
void make_prime(void){
	int i,j,index=0;
	for(i=3;i<=MAXsqr-1;i+=2){
		if(bit_map[i]==0){
			for(j=i+i;j<=MAXsqr-1;j=i+j){
				bit_map[j]=1;
			}
			prime[index++]=i;
		}
	}
	
}
int is_prime(int input){
	if(input==1)	return 0;
	else if(input==2)	return 1;
	else if(input%2==0)	return 0;
	else if(input<=MAXsqr-1){
		return !bit_map[input];
	}
	else{
		int i;
		for(i=0;prime[i]*prime[i]<=input && prime[i]!=0 ; i++){
			if(input % prime[i] == 0)	return 0;
		}
		return 1;
	}

}
