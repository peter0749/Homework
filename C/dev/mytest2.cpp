#include <stdio.h>
#include <stdlib.h>
int prime_bit_map[46341]={0},prime_list[43640]={0};

int is_prime(int);
void make_prime(void);

int main(void){
	int input;
	make_prime();
	while(scanf("%d",&input)!=EOF){
		if(is_prime(input)==1)	printf("質數\n");
		else	printf("非質數\n");
	}
	return 0;
}

void make_prime(void){
	int i,j,index=0;
	
	for(i=3;i<=7;i+=2){
		prime_list[index++]=i;
		for(j=i+i;j<=46340;j=j+i){
			prime_bit_map[j]=1; /*1~100*/
		}
	}
	for(i=11;i<100;i+=2){
		if(prime_bit_map[i]==0){
			prime_list[index++]=i;
			for(j=i+i;j<=46340;j=j+i){
				prime_bit_map[j]==1; /*100~10000*/
			}
		}
	}
	for(i=101;i<10000;i+=2){ /*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
		if(prime_bit_map[i]==0){
			prime_list[index++]=i;
			for(j=i+i;j<=43640;j=j+i){
				prime_bit_map[j]==1;	/*10000~43641*/
			}
		}
	}
	for(i=10001;i<=43640;i+=2){
		if(prime_bit_map[i]==0)	prime_list[index++]=i;
	}
}

int is_prime(int input){
	if(input==1)	return 0;
	else if(input==2)	return 1;
	else if(input%2==0)	return 0;
	else if(input<=46340){
		return !prime_bit_map[input];
	}
	else{
		int i;
		for(i=0;prime_list[i]*prime_list[i]<=input && i<4791 ; i++){
			if(input % prime_list[i] == 0)	return 0;
		}
		return 1;
	}

}
