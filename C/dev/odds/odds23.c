#include <stdio.h>
#include <stdlib.h>
int main(){
	int keyin,status;
	printf("請輸入一個整數: ");
	scanf("%d", &keyin);
	printf("您輸入的%d是",keyin);
	if(keyin>0)
		printf("正");
	else if(keyin<0)
		printf("負");
	else
		printf("");
	if(keyin%2==0)
		printf("偶");
	else
		printf("奇");
	printf("數\n");
	system("PAUSE");
	return 0;
	
}

