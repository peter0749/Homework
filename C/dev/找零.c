#include <stdio.h>
#include <stdlib.h>
int main(){
	int input,sum,left,r1000,r500,r200,r100,r50,r10,r5,r1;
	printf("==��s�t��==\n");
	printf("�п�J�I�ڪ��B:");
	scanf("%d", &input);
	printf("�п�J���O�`�B:");
	scanf("%d", &sum);
	printf("\n\n==��s�禡==\n");
	printf("1000��	500��	200��	100��	50��	10��	5��	1��\n");
	printf("-------------------------------------------------------------\n");
	left=input-sum;
	r1000=left/1000;
	r500=(left-r1000*1000)/500;
	r200=(left-r1000*1000-r500*500)/200;
	r100=(left-r1000*1000-r500*500-r200*200)/100;
	r50=(left-r1000*1000-r500*500-r200*200-r100*100)/50;
	r10=(left-r1000*1000-r500*500-r200*200-r100*100-r50*50)/10;
	r5=(left-r1000*1000-r500*500-r200*200-r100*100-r50*50-r10*10)/5;
	r1=(left-r1000*1000-r500*500-r200*200-r100*100-r50*50-r10*10-r5*5);
	printf("%d�i	%d�i	%d�i	%d�i	%d�i	%d�i	%d�i	%d�i\n",r1000,r500,r200,r100,r50,r10,r5,r1);
	system("pause");
}
