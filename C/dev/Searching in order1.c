#include <stdio.h>
int main(){
	int n,i,j,searchNum,num=-1;
	printf("�`�Ƿj�M�k\n");
	printf("�z�n��J�X�ռƦr?");
	scanf("%d",&j);
	int data[j];
	printf("�гs���J%d�ӼƦr:",j);
	for(i=0;i<j;i++){
		scanf("%d",&data[i]);
	}
	printf("\n\n�п�J����J����:");
	scanf("%d",&searchNum);
	for(i=0;i<j;i++){
		if(searchNum==data[i]){
			num=i+1;
		}
	}
	if(num==-1){
		printf("�L%d�o�Ӽƭ�",searchNum);
	}
	else{
		printf("�z��J��%d�O��%d�ӼƦr\n",searchNum,num);
	}
	system("pause");
	return 0;
}
