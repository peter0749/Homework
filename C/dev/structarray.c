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
	printf("====\tCD�ۤ��n�J�@�~\t==\n\n");
	for(i=0;i<MAX;i++){
		printf("��%d�iCD�s��:",i+1);
		gets(cd[i].no);
		printf("\nCD���Y:");
		gets(cd[i].title);
		printf("\n���:");
		gets(price);
		cd[i].price=atoi(price);
		printf("\n");
	}
	printf("\n");
	printf("�п�J���d�ߪ�CD�s��:");
	gets(keyin);
	for(i=0;i<MAX;i++){
		if(strcmp(cd[i].no,keyin)==0){
			num=i;
			break;
		}
	}
	if(num==-1)	printf("\n\t...�d�L�����");
	else{
		printf("\nCD�s��:%s",cd[num].no);
		printf("\nCD���Y:%s",cd[num].title);
		printf("\nCD����:%d",cd[num].price);
	}
	printf("\n\n");
	system("pause");
	return 0;
} 
