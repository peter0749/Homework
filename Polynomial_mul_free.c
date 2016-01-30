#include <stdio.h>
#include <stdlib.h>

typedef struct poly{	//link-list ���c
	int exp;
	double c;
	struct poly *next;
}NODE;

NODE *mk_poly (int n);	//����link-list
NODE *add_poly(NODE*, NODE*);	//�[�k
NODE *mul_poly(NODE*, NODE*);	//���k
void printpoly(NODE*);

int main(void)
{
	NODE *poly1, *poly2, *poly3;
	int np1,np2;
	printf("Number of poly1: ");
	scanf("%d",&np1);
	poly1 = mk_poly(np1);
	printf("poly1:\n");
	printpoly(poly1);
	printf("Number of poly2: ");
	scanf("%d",&np2);
	poly2 = mk_poly(np2);
	printf("poly2:\n");
	printpoly(poly2);
	poly3 = mul_poly(poly1,poly2);
	printf("poly1 * poly2:\n");
	printpoly(poly3);
	free(poly1);free(poly2);free(poly3);

	return 0;
}

NODE *mk_poly(int n)
{
	NODE *head, *ptr, *tail;
	head = ptr = tail = NULL;
	int i = 0;
	int exp = 0;
	double cf = 0.0;
	while(n>i)
	{
		i++;
		ptr = malloc(sizeof(NODE));
		printf("C*x^n: input C n\n");
		scanf("%lf %d",&cf,&exp);
		ptr->c = cf;
		ptr->exp = exp;
		ptr->next = NULL;
		if(head == NULL)
			head = ptr;
		else
			tail->next = ptr;
		tail = ptr;
	}
	return head;
}

void printpoly(NODE *ptr)
{
	if(ptr->c < 0)	//�ץ��榡�G�Ů�&���t��
		printf("-%.2lf*x^%d",ptr->c,ptr->exp);
	else
		printf("%.2lf*x^%d",ptr->c,ptr->exp);
	ptr = ptr->next;
	while(ptr!=NULL)
	{
		printf(" %+.2lf*x^%d",ptr->c,ptr->exp);
		ptr = ptr->next;
	}
	printf("\n");
}

NODE *add_poly(NODE *poly1, NODE *poly2)	//�[�k
{
	NODE *tail,*head,*ptr1,*ptr2,*ptr3;
	ptr1 = poly1;
	ptr2 = poly2;
	head=tail=NULL;
	while(ptr1!=NULL && ptr2!=NULL)		//Merge
	{
		ptr3 = malloc(sizeof(NODE));
		if(ptr1->exp > ptr2->exp)	//�Yptr1������ > ptr2������
		{
			ptr3->c = ptr1->c;
			ptr3->exp = ptr1->exp;
			ptr1 = ptr1->next;
		}
		else if(ptr1->exp < ptr2->exp)		//�Yptr1������ < ptr2������
		{
			ptr3->c = ptr2->c;
			ptr3->exp = ptr2->exp;
			ptr2 = ptr2->next;
		}
		else		//�۵���
		{
			ptr3->c = ptr1->c+ptr2->c;
			ptr3->exp = ptr1->exp;
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		ptr3->next=NULL;
		if(head==NULL)
			head = ptr3;
		else
			tail->next = ptr3;
		tail = ptr3;
	}
	if(ptr1==NULL)			//������������A���b�᭱
	{
		while(ptr2!=NULL)
		{
			ptr3=malloc(sizeof(NODE));
			ptr3->next = NULL;
			ptr3->c = ptr2->c;
			ptr3->exp = ptr2->exp;
			ptr2 = ptr2->next;
			tail->next = ptr3;
			tail = ptr3;
		}
	}
	else
	{
		while(ptr1!=NULL)
		{
			ptr3=malloc(sizeof(NODE));
			ptr3->next = NULL;
			ptr3->c = ptr1->c;
			ptr3->exp = ptr1->exp;
			ptr1 = ptr1->next;
			tail->next = ptr3;
			tail = ptr3;
		}
	}
	return head;		//�^��head �N�O�ۥ[�᪺�h����Link-list ���}�Y��}
}
NODE *mul_poly(NODE *poly1, NODE *poly2)		//�ۭ�
{
	NODE *ptr1, *ptr2, *head, *tail, *base, *temp;
	ptr1 = poly1;
	ptr2 = poly2;
	head = tail = base = temp = NULL;
	while(ptr1!=NULL)		//�����̰����A�@�����᪺�Q�[��
	{
		base = malloc(sizeof(NODE));
		base->exp = ptr1->exp + ptr2->exp;	//����ۥ[
		base->c = ptr1->c * ptr2->c;		//�Y�Ƭۭ�
		base->next = NULL;
		if(head==NULL)
			head = base;
		else
			tail->next = base;
		tail = base;
		ptr1 = ptr1->next;
	}
	base = head;	//��Q�[�ƪ���}�s�_��

	ptr2 = poly2->next;
	while(ptr2!=NULL)		//temp �����F�̰����H�~����L��
	{
		ptr1 = poly1;
		head = tail = NULL;	//Cleanup head, tail
		while(ptr1!=NULL)
		{
			temp = malloc(sizeof(NODE));
			temp->exp = ptr1->exp + ptr2->exp;
			temp->c = ptr1->c * ptr2->c;
			temp->next = NULL;
			if(head == NULL)
				head = temp;
			else
				tail->next = temp;
			tail = temp;
			ptr1 = ptr1->next;
		}
		base = add_poly(head,base);	//�Nbase �[�W �᭱temp�C�@���ۭ��᪺���G
		ptr2 = ptr2->next;
	}
	return base;	//�^�ǭ��n���h����
}
