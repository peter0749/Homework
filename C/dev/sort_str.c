#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	char name[5][10];
	char temp[10];
	int i,j;
	printf("==��w�ƧǪk(�p��j)==\n");
	printf("==�п�J����ǥͩm�W==\n");
	printf("\n");
	printf("�Ƨǫe-->\n");
	for(i=0;i<5;i++){
		printf("�� %d ��ǥ�: ",i+1);
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
	
	printf("\n�Ƨǫ�-->\n");
	for(i=0;i<5;i++){
		printf("%d.->%s\n",i+1,name[i]);
	}
	printf("\n");
	
	return 0;
} 
