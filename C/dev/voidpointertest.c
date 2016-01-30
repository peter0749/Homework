#include <stdio.h>

void Swap(void*,void*,int);

int main(void){
	int x=10,y=20;
	Swap(&x,&y,sizeof(int));
	printf("x=%d\ty=%d\n",x,y);
	float u=3.14,v=1.73;
	Swap(&u,&v,sizeof(float));
	printf("u=%f\tv=%f\n",u,v);
	return 0;
}

void Swap(void *a, void *b, int n){
	char *pa = (char*)a;
	char *pb = (char*)b;
	int i;
	for(i=0;i<n;i++){
		char t = pa[i];
		pa[i]=pb[i];
		pb[i]=t;
	}
}
