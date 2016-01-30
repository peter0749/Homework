#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct product
{
	char id[MAX];
	char name[40];
	int price;
} book[]={
		"001","V怪客",512,
		"002","Crysis",384,
		"003","Crystal",256
		};

void show(int,struct product[]);
void search(int,struct product[],char[]);

int main(void)
{
	char keyin[MAX];
	show(sizeof(book),book);
	printf("\n\n");
	printf("===>>> 請輸入查詢書號:");
	gets(keyin);
	
	search(sizeof(book),book,keyin);
	printf("\n\n");
	return 0;
}

void show(int arysize, struct product tary[])
{
	int aryindex=arysize/sizeof(struct product);
	int i=0;
	for(i=0;i<aryindex;i++)
	{
		printf("\n第%d本書號:%s\n",i+1,tary[i].id);
		printf("\t書名:%s\n",tary[i].name);
		printf("\t單價:%d\n",tary[i].price);
	}
}

void search(int arysize,struct product tary[],char keyin[])
{
	int i=0,num=-1;
	int aryindex=arysize/sizeof(struct product);
	
	for(i=0;i<aryindex;i++)
	{
		if(strcmp(tary[i].id,keyin)==0)
		{
			num=i;
			break;
		}
	}
	
	if(num==-1)
	{
		printf("查無此書......");
	}
	else
	{
		printf("\t\t書名:%s\n",tary[num].name);
		printf("\t\t單價:%d\n",tary[num].price);
	}
}
