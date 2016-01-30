#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
int main(){
	int keyin;
	char minus[3],odds[3];
	printf("請輸入整數:");
	scanf("%d",&keyin);
	if(keyin<0){
		minus[3]="負";
	}
	else if(keyin>0){
		minus[3]="正";
	} 
	else
		minus[3]="";
	if(keyin%2==0){
		odds[3]="偶";
	}
	else{
		odds[3]="奇";
	}
	printf("您輸入的是%s%s數",minus,odds);
	system("pause");
	return 0;
}
