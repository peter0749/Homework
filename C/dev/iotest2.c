#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(char* a);

int main(void){
	char input[20];
	gets(input);
	func(input);
	return 0;
}

void func(char* a){
	printf("%s",&a);
}
