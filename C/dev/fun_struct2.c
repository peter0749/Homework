#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct product
{
	char id[MAX];
	char name[40];
	int price;
} book[]={
		"001","V�ǫ�",512,
		"002","Crysis",384,
		"003","Crystal",256
		};

void show(int,struct product*);
void search(int,struct product*,char[]);

int main(void)
{
	char keyin[MAX];
	show(sizeof(book),&book);
	printf("\n\n");
	printf("===>>> �п�J�d�߮Ѹ�:");
	gets(keyin);
	
	search(sizeof(book),&book,keyin);
	printf("\n\n");
	return 0;
}

void show(int arysize, struct product *tary)
{
	struct product *ptr;
	ptr=tary;
	int aryindex=arysize/sizeof(struct product);
	int i=0;
	for(i=0;i<aryindex;i++,ptr++)
	{
		printf("\n��%d���Ѹ�:%s\n",i+1,ptr->id);
		printf("\t�ѦW:%s\n",ptr->name);
		printf("\t���:%d\n",ptr->price);
	}
}

void search(int arysize,struct product *tary,char keyin[])
{
	struct product *ptr;
	ptr=tary;
	int i=0,num=-1;
	int aryindex=arysize/sizeof(struct product);
	
	for(i=0;i<aryindex;i++,ptr++)
	{
		if(strcmp(ptr->id,keyin)==0)
		{
			num=i;
			break;
		}
	}
	
	if(num==-1)
	{
		printf("�d�L����......");
	}
	else
	{
		printf("\t\t�ѦW:%s\n",ptr->name);
		printf("\t\t���:%d\n",ptr->price);
	}
}
