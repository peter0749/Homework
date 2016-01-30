#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MSG1 "請輸入英文字串:\t"
#define MSG2 "反轉後:\t"
#define BUFFER_SIZE 80 
char *reverse(char[]);
int main(void){
	char str1[BUFFER_SIZE];
	char *ptr1=NULL;
	printf("\n%s",MSG1);
	gets(str1);
	ptr1=reverse(str1);
	printf("\n%s",MSG2);
	puts(ptr1);
	
	return 0;
}

char *reverse(char str2[]){
	char *ptr2, *new_ptr;
	int i,j;
	int strcount=strlen(str2);
	new_ptr=(char*)malloc(sizeof(char)*(strcount+1));
	ptr2=str2;
	for(i=strcount-1,j=0;i>=0;i--,j++){
		*(new_ptr+j)=*(ptr2+i);
	}
	*(new_ptr+j)='\0';
	return new_ptr;
	
}

