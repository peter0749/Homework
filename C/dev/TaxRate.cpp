#include <stdio.h>
#include <stdlib.h>
int main(){
	int tax,diff,income,x;
	double rate;
	for(;;){
	printf("�п�J��X�ұo�|�b�B: \n\n");
	scanf("%d", &income);
	printf("��X�ұo�|�b�B: %d\n",income);
	if(income>=0 && income<=370000)
	{
		diff=0;
		rate=0.6;
		break;
	}
	else if(income>370000 && income<=990000)
	{
		diff=25900;
		rate=0.13;
		break;
	}
	else if(income>990000 && income<=1980000)
	{
		diff=105100;
		rate=0.21;
		break;
	}
	else if(income>1980000 && income<=3720000)
	{
		diff=283300;
		rate=0.3;
		break;
	}
	else if(income>3720000)
	{
		diff=655300;
		rate=0.4;
		break;
	}
	else{
		printf("���X�榡!�Э��s��J:\n");
	}
}
	tax=rate*income;
	printf("�|�B: %2.0f �H\n", rate*100);
	printf("�|��: %d", tax);
	printf("�ֶi�t�B: %d", diff);
	printf("��ú: %d\n", tax-diff);
	system("PAUSE");
	return 0;
	
}
