#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

void pop(void);
void push(void);
void printout(void);

int *sptr=NULL,*empty=NULL,*full=NULL;
int i=1;
int stack[MAXSIZE];

int main(void){
	int choose;
	
	sptr=stack;
	empty=stack;
	full=stack+MAXSIZE-1;
	
	do{
		printf("\n\t1. Push\n\t2. Pop\n\t3. Printout\n\t0. Quit\n\t=======================================\n\t�п��[0-3]:");
		scanf("%d",&choose);
		
		switch(choose){
		case 0:
			exit(0);
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			printout();
			break;
		default:
			printf("\n\t�п�J[0-3]\n");
		}
	}while(1);
	return 0;
} 

void pop(void){
	if(sptr!=empty){
		printf("\n\n\tPop from stack:%3d",*sptr);
		sptr--;
		i--;
	}
	else{
		printf("\n\n\t���|�w�g�ŤF");
		i=1;/**/
	}
}

void push(void){
	sptr++;
	if(sptr==full){
		printf("\n\n\t���|�w��");
		sptr--;
	}
	else{
		printf("\n\n\t�п�J��%d�����:",i++);
		scanf("%d",sptr);
		
	}
}

void printout(void){
	int *lptr=sptr;
	printf("\n\n\t�ثe���|���:");
	do{
		if(lptr!=empty){
			printf("%3d",*lptr);
			lptr--;
		}
		else{
			break;
		}
	}while(1);
	printf("\n\tTop <-- Stack --> Bottom\n");
}
