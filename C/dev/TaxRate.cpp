#include <stdio.h>
#include <stdlib.h>
int main(){
	int tax,diff,income,x;
	double rate;
	for(;;){
	printf("請輸入綜合所得稅淨額: \n\n");
	scanf("%d", &income);
	printf("綜合所得稅淨額: %d\n",income);
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
		printf("不合格式!請重新輸入:\n");
	}
}
	tax=rate*income;
	printf("稅額: %2.0f ％\n", rate*100);
	printf("稅金: %d", tax);
	printf("累進差額: %d", diff);
	printf("應繳: %d\n", tax-diff);
	system("PAUSE");
	return 0;
	
}
