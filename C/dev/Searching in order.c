#include <stdio.h>
int main(){
	int data[5];
	int n,i,searchNum,num=-1;
	printf("�`�Ƿj�M�k\n");
	printf("�гs���J���Ӽƭ�\n\n");
	printf("�п�J:");
	for(i=0;i<5;i++){
		scanf("%d",&n);
		data[i]=n;
	}
	printf("\n");
	printf("�п�J���j�M����:");
	scanf("%d",&searchNum);
	for(i=0;i<5;i++){
		if(data[i]==searchNum){
			num=i;
		}
	}
	printf("===========================================\n");
	if(num==-1){
		printf("�L����:%d\n",searchNum);
	}
	else{
		printf("�z��J��%d�O��%d�ӼƦr\n",searchNum,(num+1));
	}
	system("pause");
	return 0;
}
