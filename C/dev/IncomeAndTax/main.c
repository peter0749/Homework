#include <stdio.h>
#include <stdlib.h>
int main(){
	int tax,income;
	double rate;
	for(;;){
		printf("Please enter your income (10k):");
		scanf("%d",&income);
		if(income>=0 && income<=30){
			rate=0;
			break;
		}
		else if(income>30 && income<=60){
			rate=0.05;
			break;
		}
		else if(income>60 && income<=80){
			rate=0.1;
			break;
		}
		else if(income>80 && income<=100){
			rate=0.2;
			break;
		}
		else if(income>100){
			rate=0.3;
			break;
		}
		else
			printf("Invalid!\n");
	}
	tax=rate*income;
	printf("\nincome=%d",income);
	printf("\nrate=%3.0f¢H",rate*100);
	printf("\ntax=%d\n",tax);
	system("pause");
	return 0;
}
