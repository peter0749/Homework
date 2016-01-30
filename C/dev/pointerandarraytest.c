#include <stdio.h>

int main(void){
	#if 0
	char str[7]="Hello\n";
	str[6]=0;
	char *pc = str;
	int i = 0;
	while(pc[i])	printf("%c",pc[i++]);
	pc[4]='\n';
	pc[5]=0;
	i=0;
	while(pc[i])	printf("%c",pc[i++]);
	#endif
	#if 0
	int A[]={0,100,200};
	int *pi=A;
	printf("pi=%d\t*pi=%d\n",pi,*pi);
	printf("pi=%d\t*pi=%d\n",pi+2,*(pi+2));
	printf("pi=%d\t*pi=%d\n",++pi,*pi);
	if(pi!=A)	printf("pi!=A");
	if(pi>=A)	printf("pi>=A");
	pi=A;
	pi[0]=*(pi+0);
	pi[1]=*(pi+1);
	pi[1]=*(pi+2);
	#endif
	#if 0
	int a[]={1,2,3},i;
	int *p=a;
	for(i=0;i<=3;++i)	printf("Addr=%d\tValue=%d\n",p,*p++);
	i=3;p=&a[2];
	do{
		--i;
		printf("Addr=%d\tValue=%d\n",p,*p--);
	}while(i>=0);
	#endif
	#if 0
	int A1[]={0,1,2};
	int A2[] = {10, 11, 12, 76};
	int A3[] = {20, 99}; 
	int *pa[3] = {A1, A2, A3}; 
	int i,j;
	for(i=0;i<3;++i){
		for(j=0;j<4;++j){
			printf("%d, ", pa[i][j]);
		}
		printf("\n");
	}
	#endif
	#if 1
	int A[2][3]=
		{
		{1,3,5},
		{7,9,11}
		};
	int *pa = A;
	int i,j;
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			printf("%d, ",pa[i*3+j]);
		}
		printf("\n");
	}
	#endif
	
	return 0;
}
