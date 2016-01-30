#include <stdio.h>
void swap(int *a, int *b){
	int t=*a;*a=*b;*b=t;
}
int main(void){
	printf("&x\t&y\tx\ty\t&px\t&py\tppi\t*ppi\n");
	int x=0,y=0;
	int *px=&x;
	int *py=&y;
	int **ppi=&px;
	**ppi=10;
	printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",&x,&y,x,y,&px,&py,ppi,*ppi);
	ppi=&py;
	printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",&x,&y,x,y,&px,&py,ppi,*ppi);
	**ppi=30;
	printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",&x,&y,x,y,&px,&py,ppi,*ppi);
	swap(&x,&y);
	printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",&x,&y,x,y,&px,&py,ppi,*ppi);
	return 0;
} 
