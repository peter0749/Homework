#include <stdio.h>
#include <math.h>
int IsPrime(int);

int main(void){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(IsPrime(n)==0)	printf("非質數\n");
		else	printf("質數\n");
	}
	return 0;
}

int IsPrime(int n){
	int i;
	if(n==2)	return 1;
	else if(n==3)	return 1;
	else if(n==5)	return 1;
	else if(n==7)	return 1;
	else if(n==11)	return 1;
	else{
		for(i=2;i<=sqrt(n);i++){
			if(IsPrime(i)==1){
				if(n%i==0)	return 0;
			}
		}
		return 1;
		
	}	
	
}
