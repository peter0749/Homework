#include <stdio.h>
#include <stdlib.h>

int Test(){
int a=10;
return a;	
	
}



int main(){
int num;
int X;
printf("Welcome\n");
num=Test();
printf("%d\n",num);
for(X=0;X<=10;X++){
	printf("X=%d\n",X);
	
}

return 0;
system("pause"); 
}
