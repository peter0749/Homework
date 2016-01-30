#include <stdio.h>
#include <stdlib.h>
int main(){
	int keyin,status;
	printf("叫块俱计: ");
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
			printf("\n眤块%d琌タ案计\n",keyin);
			break;
		case 2:
			printf("\n眤块%d琌璽案计\n",keyin);
			break;
		case 3:
			printf("\n眤块%d琌タ计\n",keyin);
			break;
		case 4:
			printf("\n眤块%d琌璽计\n",keyin);
			break;
		case 5:
			printf("\n眤块琌%d,案计\n",keyin);
			break;
		default: 
			printf("\n╆簆!眤块ぐ或?\n");
			break;
	}
	system("PAUSE");
	return 0;
	
}

