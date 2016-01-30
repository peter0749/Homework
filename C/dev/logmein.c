#include <stdio.h>
#include <string.h>
int main(){
	char user_id[20],pwd[20];
	printf("Please enter your user_id:");
	scanf("%s",user_id);
	printf("\nPlease enter your password:");
	scanf("%s",pwd);
	if(strcmp(user_id,"peter0749") == 0 && strcmp(pwd,"lisa1024") == 0)
		printf("\nLoging in......\n");
	else
		printf("Wrong user_id or password. Can\'nt log in.\n");
	system("pause");
	return 0;
}
