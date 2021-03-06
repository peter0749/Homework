#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int prime_list[1000001]={0},prime_map[1000001]={0},number_map[1000001]={0},input;

void mk_prime(void);
void devide(void);

int main(void){
	int i,n=0;
	mk_prime();
	/*printf("done!\n\n");
	int i;
	for(i=0;prime_list[i]!=0;i++){
		printf("p[%d]%d\n",i,prime_list[i]);
	}*/
	while(scanf("%d",&input)!=EOF){
		devide();
	/*	for(i=1;i<12;i++)	printf("num[%d]=%d",i,number_map[i]);*/
		for(i=1;i<1000001;i++){
			if(number_map[i]==1){
				if(n==0){
					printf("%d",i);
					n=1;
				}	
				else printf(" * %d",i);
			}
			else if(number_map[i]>1){
				if(n==0){
					printf("%d^%d",i,number_map[i]);
					n=1;
				}
				else printf(" * %d^%d",i,number_map[i]);
			}
		}
		n=0;
		printf("\n");
		memset(number_map,0x00,sizeof(number_map));
	} 
	return 0;
} 

void mk_prime(void){
	int i,j,index=0;
	prime_list[0]=2;
	for(i=3;i<=1000000;i+=2){
		if(prime_map[i]==0){
			for(j=i+i;j<=1000000;j+=i){
			prime_map[j]=1;
		}
		}
		prime_list[++index]=i;
	}
}

void devide(void){
	int i;
	for(i=0;prime_list[i]!=0&&prime_list[i]<=input;i++){
		if(input%prime_list[i]==0){
			/*printf("??\n");*/
			number_map[prime_list[i]]++;
			input/=prime_list[i];
			devide();
		}
	}
}
