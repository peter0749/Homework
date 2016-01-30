#include <stdio.h>

int getchar(void);

int main(void){
	int x=0;
	scanf("%d",&x);
	printf("%d\n",x);
	{
		int c;
		while((c=getchar())!='\n'&&c!=EOF);	//clear stdin
	}
	printf("press enter to exit");
	getchar();	//Waiting an Enter key
	return 0;
}

