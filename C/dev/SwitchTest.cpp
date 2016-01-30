#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
main (){
	char ch;
	printf("A: Create\nD: Delete\nE: Edit\nQ: Quit\n");
	ch=toupper(getchar());
	switch(ch){
		case 'A':
			printf("==CreateMode==\n");
			break;
		case 'D':
			printf("==DeleteMode==\n");
			break;
		case 'E':
			printf("==EditMode==\n");
			break;
		case 'Q':
			printf("Quit!\n");
			break;
		default:
			printf("Please enter A/D/E/Q .\n");
			
	}
	system("PAUSE");
	return 0;
} 
