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
		printf("\n\t1. Push\n\t2. Pop\n\t3. Printout\n\t0. Quit\n\t=======================================\n\t請選擇[0-3]:");
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
			printf("\n\t請輸入[0-3]\n");
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
		printf("\n\n\t堆疊已經空了");
		i=1;/**/
	}
}

void push(void){
	sptr++;
	if(sptr==full){
		printf("\n\n\t堆疊已滿");
		sptr--;
	}
	else{
		printf("\n\n\t請輸入第%d筆整數:",i++);
		scanf("%d",sptr);
		
	}
}

void printout(void){
	int *lptr=sptr;
	printf("\n\n\t目前堆疊資料:");
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
