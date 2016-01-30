#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int i,l;
	char ch[10000];
	while(scanf("%s",ch)!=EOF){
		l=strlen(ch);
		/*printf("%d",l);*/
		for(i=0;i<l;i++){
		ch[i]-=7;
		printf("%c",ch[i]);
	}
	printf("\n");
	}
	return 0;
}
