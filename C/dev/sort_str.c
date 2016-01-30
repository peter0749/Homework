#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	char name[5][10];
	char temp[10];
	int i,j;
	printf("==氣泡排序法(小到大)==\n");
	printf("==請輸入五位學生姓名==\n");
	printf("\n");
	printf("排序前-->\n");
	for(i=0;i<5;i++){
		printf("第 %d 位學生: ",i+1);
		gets(name[i]);
	}
	
	for(i=3;i>=0;i--){
		for(j=0;j<=i;j++){
			if(strcmp(name[j],name[j+1])>0){
				strcpy(temp,name[j]);
				strcpy(name[j],name[j+1]);
				strcpy(name[j+1],temp);
			}
		}
	}
	
	printf("\n排序後-->\n");
	for(i=0;i<5;i++){
		printf("%d.->%s\n",i+1,name[i]);
	}
	printf("\n");
	
	return 0;
} 
