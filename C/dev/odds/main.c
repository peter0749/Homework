#include <stdio.h>
#include <stdlib.h>
int main(){
	int keyin,status;
	printf("�п�J�@�Ӿ��: ");
	scanf("%d", &keyin);
	if(keyin>0 && keyin%2==0)
		status=1;
	else if(keyin<0 && keyin%2==0 )
		status=2;
	else if(keyin<0 && keyin%2!=0 )
		status=3;
	else if(keyin>0 && keyin%2!=0 )
		status=4;
	else if(keyin==0 )
		status=5;
	else
		status=0;
	switch(status){
		case 1:
			printf("\n�z��J��%d�O������\n",keyin);
			break;
		case 2:
			printf("\n�z��J��%d�O�t����\n",keyin);
			break;
		case 3:
			printf("\n�z��J��%d�O���_��\n",keyin);
			break;
		case 4:
			printf("\n�z��J��%d�O�t�_��\n",keyin);
			break;
		case 5:
			printf("\n�z��J���O%d,����\n",keyin);
			break;
		default: 
			printf("\n��p!�z����J�F����?\n");
			break;
	}
	system("PAUSE");
	return 0;
	
}

