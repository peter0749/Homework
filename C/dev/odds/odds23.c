#include <stdio.h>
#include <stdlib.h>
int main(){
	int keyin,status;
	printf("�п�J�@�Ӿ��: ");
	scanf("%d", &keyin);
	printf("�z��J��%d�O",keyin);
	if(keyin>0)
		printf("��");
	else if(keyin<0)
		printf("�t");
	else
		printf("");
	if(keyin%2==0)
		printf("��");
	else
		printf("�_");
	printf("��\n");
	system("PAUSE");
	return 0;
	
}

