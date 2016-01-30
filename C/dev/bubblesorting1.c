#include <stdio.h>
int main() {
	int n,i,j,t,times;
	/*printf("--Bubble sorting--\n");
	printf("How many numbers?");*/
	/*scanf("%d",&times);*/
	while(scanf("%d",&times)!=EOF)
	{
		int data[times];
		/*printf("Before sorting:\t ");*/
		for(i=0;i<times;i++){
			scanf("%d",&data[i]);
		}
		for(i=times-2;i>=0;i--){
			for(j=0;j<=i;j++){
				if(data[j]>data[j+1]){
				t=data[j];
				data[j]=data[j+1];
				data[j+1]=t;
				}
			}
		}
		/*printf("After sorting:\t");*/
		for(i=0;i<times;i++){
			printf("%d ",data[i]);
		}
		printf("\n");
	}
	return 0;
}
