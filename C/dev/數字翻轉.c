#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reverse_number(void);

int main(void){
	int state=1;
	while(state!=0){
		state=reverse_number();
	}
	return 0;
} 

int reverse_number(void){
	char input[20];
	/*printf("input=%s\n",input);*/
	if(scanf("%s",&input)==EOF)	return 0;
	int strlengthm1;
	strlengthm1=strlen(input)-1;
	if(input[0]=='0'){
		int i;
		int count_zero=1;
		while(count_zero<=strlengthm1 && input[count_zero]=='0'){
			/*printf("in_while\n");*/
			count_zero++;
		}
		if(count_zero==strlengthm1+1)	printf("0\n");
		else{
			for(i=strlengthm1;i>=count_zero;i--){
				printf("%c",input[i]);
			}
			printf("\n");
		}
	}
	else{
		int i;
		for(i=strlengthm1;i>=0;i--){
				printf("%c",input[i]);
			}
			printf("\n");
	}
	
	return 1;
}
