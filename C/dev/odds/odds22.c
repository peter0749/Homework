#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
int main(){
	int keyin;
	char minus[3],odds[3];
	printf("�п�J���:");
	scanf("%d",&keyin);
	if(keyin<0){
		minus[3]="�t";
	}
	else if(keyin>0){
		minus[3]="��";
	} 
	else
		minus[3]="";
	if(keyin%2==0){
		odds[3]="��";
	}
	else{
		odds[3]="�_";
	}
	printf("�z��J���O%s%s��",minus,odds);
	system("pause");
	return 0;
}
