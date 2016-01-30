#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int i,t;
	int ana[10]={0};
	srand(time(NULL));
	for(i=0;i<40;i++){
		t=rand()%10;
		ana[t]++;
	}
	for(i=0;i<10;i++){
		printf("%d\t",i-5);
	}
	printf("\n");
	for(i=0;i<10;i++){
		printf("%d\t",ana[i]);
	}
	printf("\n");
	system("pause");
	
	
	return 0;
} 
