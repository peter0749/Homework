#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	
	/*Declare var*/
	struct node{
		char name[10];
		int age;
		struct node *next;
	};
	
	struct node *head,*ptr,*newptr;
	int i;
	
	/*Generate node 1*/
	newptr=(struct node*)malloc(sizeof(struct node));
	strcpy(newptr->name,"David");
	newptr->age=20;
	newptr->next=NULL;
	head=newptr;ptr=newptr;
	
	/*Generate node 2*/
	newptr=(struct node*)malloc(sizeof(struct node));
	strcpy(newptr->name,"Peter");
	newptr->age=24;
	newptr->next=NULL;
	ptr->next=newptr;
	ptr=newptr;
	
	/*Generate node 3*/
	newptr=(struct node*)malloc(sizeof(struct node));
	strcpy(newptr->name,"Lucy");
	newptr->age=21;
	newptr->next=NULL;
	ptr->next=newptr;
	/*ptr=newptr;##End of node##*/
	
	/*Printout nodes*/
	ptr=head;
	i=1;
	while(ptr!=NULL){
		printf("\nNode %d\tName:%s",i++,ptr->name);
		printf("\n\tAge:%d",ptr->age);
		ptr=ptr->next;
	}
	
	printf("\n");
	system("pause");
	return 0;
} 
