#include <stdio.h>
#include <stdlib.h>
int main(){
	int i,x,sum=0;
	printf("1+2+3+4+...+n=\nPlease enter n:\n");
	scanf("%d",&x);
	for(i=1;i<=x;i++){
		sum+=i;
	}
	printf("1+2+3+4+...+%d=%d\n",x,sum);
	system("pause");
	return 0;
}
