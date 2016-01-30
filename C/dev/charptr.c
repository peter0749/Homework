#include <stdio.h>
#include <stdlib.h>
#define NUM 5
int main(void){
	int price[NUM]={400,320,350,150,280};
	char *name[NUM]={"松橋蛋糕","小王煎餅","牛肉肉干","精緻蛋捲","胖胖果汁"};
	int max,max_index=0,min,min_index=0;
	int i,j;
	printf("產品名稱\t單價\n============================\n");
	for(i=0;i<5;i++){
		printf("%s\t%d\n",*(name+i),price[i]);
	}
	#if 1
	for(i=0,j=0;i<5;i++,j++){
		if(price[i]>price[max_index]){
			max_index=i;
		}
		if(price[i]<price[min_index]){
			min_index=i;
		}
	}
	printf("最貴:\t%s\t單價%d\a\n",*(name+max_index),price[max_index]);
	printf("最便宜:\t%s\t單價%d\n",*(name+max_index),price[min_index]);
	#endif
	system("pause");
	return 0;
} 
