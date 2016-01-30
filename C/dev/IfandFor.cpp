#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
int main()
{
	int x=0;
	char ch;
	printf("A: Add\nD: Delete\nE: Edit\nQ: Quit\n");
	for(x=0;x<=2;){
	ch=getchar();
	ch=toupper(ch);
	if(ch=='A'){
		printf("==CreateMode==\n");
		system("pause");
	}
	else if(ch=='D'){
		printf("==DeleteMode==\n");
		system("pause");
	}
	else if(ch=='E'){
		printf("==EditMode==\n");
		system("pause");
	}
	else if(ch=='Q'){
		x=3;
		printf("Quit!\n");
	}
	else{
		printf("Please enter A/D/E/Q .\n");
	}
	}
	system("pause");
	return 0;
}
