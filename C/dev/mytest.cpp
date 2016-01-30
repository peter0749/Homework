#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int bit_map[46341]={0},prime[5000]={0};
void make_prime(void);
int is_prime(int);
int main(){
	int input;
	make_prime();
	printf("DONE!\n");
	for(int i=0;i<50;i++)	printf(" p[%d]%d",i,prime[i]);
	/*printf("Done!\n");*/
	while(scanf("%d",&input)!=EOF){
		if(is_prime(input)==1)	printf("質數\n");
		else	printf("非質數\n");
	}
	return 0;
}
void make_prime(void){
	int i,j,index=0;
	for(i=3;i<=46340;i+=2){
		if(bit_map[i]==0){
			for(j=i+i;j<=46340;j=i+j){
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
	else if(input<=46340){
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
