#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

typedef struct polynodes{
	float lower;
	int upper;
	struct polynodes *next_poly;
	
}NODE;

void print_poly(NODE*);
NODE* createpoly(int);
NODE* addpoly(NODE*,NODE*);

int main(void)
{
	int keyin;
	NODE *poly1,*poly2,*poly3;
	printf("==多項式相加==\n");
	printf("poly1(x)幾項: ");
	scanf("%d",&keyin);
	poly1=createpoly(keyin);
	printf("poly2(x)幾項: ");
	scanf("%d",&keyin);
	poly2=createpoly(keyin);
	poly3=addpoly(poly1,poly2);
	printf("poly1(x)= ");
	print_poly(poly1);
	printf("\npoly2(x)= ");
	print_poly(poly2);
	printf("\npoly1(x)+poly2(x)= ");
	print_poly(poly3);
	
	return 0;
}

void print_poly(NODE* ptr)
{
	char opr;
	if(ptr!=NULL && ptr->lower >= 0)
	{
		printf("%4.1fx^%d ",ptr->lower,ptr->upper);
		ptr=ptr->next_poly;
	}
	while(ptr!=NULL)
	{
		if(ptr->lower >= 0)
		{
			opr='+';
		}
		else
		{
			opr='-';
		}
		printf("%c %4.1fx^%d ",opr,ptr->lower,ptr->upper);
		ptr=ptr->next_poly;
	}
}

NODE* createpoly(int n)
{
	int i=1;
	int upper=0;
	float lower=0;
	NODE *head,*ptr,*newptr;
	head=ptr=newptr=NULL;
	do{
		printf("\n請輸入第%d項(係數 指數):",i++);
		scanf("%f %d",&lower,&upper);
		newptr=(NODE*)malloc(sizeof(NODE));
		newptr->lower=lower;
		newptr->upper=upper;
		
		newptr->next_poly=NULL;
		if(head==NULL)
		{
			head=newptr;
		}
		else
		{
			ptr->next_poly=newptr;
		}
		ptr=newptr;
	}while(i<=n);
	
	
	return head;
}

NODE* addpoly(NODE *poly1, NODE *poly2)
{
	NODE *head,*ptr,*ptr1,*ptr2,*ptr3;
	head=ptr=ptr1=ptr2=ptr3=NULL;
	ptr1=poly1;
	ptr2=poly2;
	while(ptr1!=NULL && ptr2!=NULL)
	{
		ptr3=(NODE*)malloc(sizeof(NODE));
		if(ptr1->upper > ptr2->upper)
		{
			ptr3->upper=ptr1->upper;
			ptr3->lower=ptr1->lower;
			ptr1=ptr1->next_poly;
		}
		
		else if(ptr1->upper < ptr2->upper)
		{
			ptr3->upper=ptr2->upper;
			ptr3->lower=ptr2->lower;
			ptr2=ptr2->next_poly;
		}
		
		else
		{
			ptr3->lower=ptr1->lower+ptr2->lower;
			ptr3->upper=ptr1->upper;
			ptr1=ptr1->next_poly;
			ptr2=ptr2->next_poly;
		}
		
		ptr3->next_poly=NULL;
		if(head==NULL)
		{
			head=ptr3;
		}
		else
		{
			ptr->next_poly=ptr3;
		}
		ptr=ptr3;	
	}
	
	if(ptr1==NULL)
	{
		while(ptr2!=NULL)
		{
			ptr3=(NODE*)malloc(sizeof(NODE));
			ptr3->upper=ptr2->upper;
			ptr3->lower=ptr2->lower;
			ptr2=ptr2->next_poly;
			ptr->next_poly=ptr3;
			ptr=ptr3;
		}
		
	}
	
	else
	{
		while(ptr1!=NULL)
		{
			ptr3=(NODE*)malloc(sizeof(NODE));
			ptr3->upper=ptr1->upper;
			ptr3->lower=ptr1->lower;
			ptr1=ptr1->next_poly;
			ptr->next_poly=ptr3;
			ptr=ptr3; 
		}
	}
	ptr->next_poly=NULL;
	
	return head;
}
