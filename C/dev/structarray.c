#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3

struct product{
	char no[5];
	char title[20];
	int price;
};

int main(void){
	int i,num=-1;
	struct product cd[MAX];
	char price[5];
	char keyin[5];
	printf("====\tCD唱片登入作業\t==\n\n");
	for(i=0;i<MAX;i++){
		printf("第%d張CD編號:",i+1);
		gets(cd[i].no);
		printf("\nCD抬頭:");
		gets(cd[i].title);
		printf("\n售價:");
		gets(price);
		cd[i].price=atoi(price);
		printf("\n");
	}
	printf("\n");
	printf("請輸入欲查詢的CD編號:");
	gets(keyin);
	for(i=0;i<MAX;i++){
		if(strcmp(cd[i].no,keyin)==0){
			num=i;
			break;
		}
	}
	if(num==-1)	printf("\n\t...查無此資料");
	else{
		printf("\nCD編號:%s",cd[num].no);
		printf("\nCD抬頭:%s",cd[num].title);
		printf("\nCD價格:%d",cd[num].price);
	}
	printf("\n\n");
	system("pause");
	return 0;
} 
