#include <stdio.h>
#include <math.h>
int main(){
	int test,i,k,j;
	int a[43640]={0};
	a[0]=2;
	a[1]=3;
	a[2]=5;
	a[3]=7;
	for(i=3;i<43640 && a[i]*a[i]<=2147483647 ;i++){
		j=2;
		for(k=0;k<=i;k++){
			if((a[i]+j)%a[k]==0){
				j+=2;
				k=0;
				continue;
			}
			else{
				a[i+1]=a[i]+j;
			}
		}
	}
	printf("Done!\n");
	/*for(i=0;i<43640;i++)	printf(" %d",a[i]);*/
	while(scanf("%d",&test)!=EOF){
		for(i=0;i<43640;i++){
			if(test%a[i]==0){ 
				printf("�D���\n");
				break;
			}
			else if(i==43640 && test%a[i]!=0){
				printf("���\n");
				break;
			}
		}
	}
}



