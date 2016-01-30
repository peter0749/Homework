#include <stdio.h>

int CheckN(int);

int main(void){
	int i;
	for(i=0;i<=100;i++)	printf("%d\t%d\n",i,CheckN(i));
	printf("\n");
	system("pause");
	return 0;
}

int CheckN(int n){
	if(n>0){
		if(n*2+1==n*2-1){
			if(10<=n<100)	return n*2+1;
			else	return 0;
		}
		else	return 0;
	}
	else return 0;
}
