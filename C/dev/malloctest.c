#include <stdio.h>
#include <stdlib.h>

int main(void){
	int i,n,*ptr=NULL,search_Num,num=-1;
	printf("�аݭn��J�X�Ӿ��:");
	scanf("%d",&n);
	ptr=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		printf("�п�J��%2d�Ӿ��:",i+1);
		scanf("%d",ptr+i);
		printf("\n");
	}
	printf("\n�п�J�n�j�M���ƭ�:");
	scanf("%d",&search_Num);
	for(i=0;i<n;i++){
		if(*(ptr+i)==search_Num){
			num=i+1;
			break;
		}
	}
	if(num==-1)	printf("�䤣��%2d���ƭ�!\n",search_Num);
	else	printf("%2d�O��%2d�ӼƦr\n",search_Num,num);
	free(ptr);
	
	
	return 0;
}
