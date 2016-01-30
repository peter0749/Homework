#include <stdio.h>
int main()
{
	int x,y,N,i,j,k;
	i=1;
	while(1)
	{
		scanf("%d",&x);
		if(x==0){
			break;
		}
		else{
			scanf("%d %d",&y,&N);
		}
		if(y==0){
			printf("%d",i);
			printf("\n");
			continue;
		}
		i=x%N;
		for(j=y;j>1;j--){
			i=(i*x)%N;
		}
		printf("%d",i);
		printf("\n");
		i=1;
	}
}
