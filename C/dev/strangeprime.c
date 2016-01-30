#include <stdio.h>
#include <math.h>
int main(){
	int test,i,k,j;
	int a[43641]={0};
	a[0]=2;
	a[1]=3;
	a[2]=5;
	a[3]=7;
	for(i=3;i<43641;i++){
		j=1;
		for(k=0;k<=i;k++){
			if((a[i]+j)%a[k]==0){
				j++;
				k=0;
				continue;
			}
			else{
				a[i+1]=a[i]+j;
			}
		}
	}
	printf("Done!\n");
	for(i=0;i<43641;i++)	printf(" %d",a[i]);
	while(scanf("%d",&test)!=EOF){
		for(i=0;i<43641;i++){
			if(test%a[i]==0){ 
				printf("非質數\n");
				break;
			}
			else if(i==43640 && test%a[i]!=0){
				printf("質數\n");
				break;
			}
		}
	}
}
