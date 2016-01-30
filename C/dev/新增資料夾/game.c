#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>

int choose_char(void);
void charactor_info(int,int);
int dps(int);
int def(int);
int criti(int);
int hp(int);
int function_choose(void);

int main(void){
	while(1){
		int ch,enemy,chhp,enehp,ene_choose,ch_choose;
		int ch_hit=0,ene_hit=0;
		ch=choose_char();
		/*printf("%d",ch);*/
		if(ch!=0){
			srand(time(NULL));
			enemy=(rand()%6+1);
			charactor_info(enemy,1);
			chhp=hp(ch);
			enehp=hp(enemy);
			while(chhp>0 && enehp>0){
				ch_choose=function_choose();
				/*printf("\nin_main:%d",ch_choose);*/
				switch(ch_choose){
					case 1:
						srand(time(NULL));
						if((rand()%10+1) <= criti(ch)){
							ch_hit=dps(ch)*1.2;
							printf("Ĳ�o�z���A��ĤH�W�[0.2���ˮ`:%d\n",ch_hit);
						}
						else{
							ch_hit=dps(ch);
							printf("��ĤH�ˮ`:%d\n",ch_hit);
						} 
						chhp-=ene_hit;
						printf("���ĤH�ˮ`%d\n�z��HP:%d\n",ene_hit,chhp);
						ene_hit=0;
						break;
					case 2:
						if(ene_hit<def(ch)){
							printf("�������m\n�z��HP:%d\n",chhp);
							break;
						}
						else{
							chhp-=(ene_hit-def(ch));
							printf("�z����ĤH%d�ˮ`\n�z��HP:%d\n",def(ch)-ene_hit,chhp);
						} 
						ene_hit=0;
						break;
					default:
						break;
				}
				srand(time(NULL));
				ene_choose=(rand()%2+1);
				switch(ene_choose){
					case 1:
						srand(time(NULL));
						if((rand()%10+1) <= criti(enemy))	ene_hit=dps(enemy)*1.2;
						else ene_hit=dps(enemy);
						enehp-=ch_hit;
						printf("�ĤHHP:%d",enehp); 
						ch_hit=0;
						break;
					case 2:
						if(ch_hit<def(enemy)){
							if(ch_choose==1)	printf("MISS!\n");
							printf("�ĤHHP:%d",enehp);
							break;
						}
						else{
							enehp-=(ch_hit-def(enemy));
							printf("�ĤH�S�������צ����,�ĤHHP:%d",enehp);
						}
						ch_hit=0;
						break;
					default:
						break;
				}
				
			}
			if(chhp>0)	printf("\n�pĹ�F!\n");
			else	printf("\n\n�p��F...\n");
		}
	}
	return 0;
} 

int choose_char(void){
	int ch;
	char yes[4];
	char *name[]={"��޳","�l��","���M","�a��","���t","����"};
	printf("\n\n�п�ܨ���:\n1.��޳\t2.�l��\t3.���M\t4.�a��\t5.���t\t6.����\n");
	ch=getch()-'0';
	charactor_info(ch,0);
	if(1<=ch && ch<=6){
		printf("�z�T�w�n���%s��?(yes/no)\n",name[ch-1]);
		scanf("%s",&yes);
		if(strcmp(yes,"yes")==0){
			return ch;
		}
		else{
			return 0;
		}
	}
	else	return 0;
	
}

void charactor_info(int ch,int n){
	char *word;
	printf("\n");
	if(n==0){
		word="�z";
	}
	else{
		word="�Ĥ�"; 
	}
	switch(ch){
		case 1:
			printf("%s��ܮ�޳�A���W�u����޳�v\nHP:%d\n����:%d\n���m:%d\n�z���v(x1.2):�H%d0\n",word,hp(ch),dps(ch),def(ch),criti(ch));
			break;
		case 2:
			printf("%s��ܤl�ˡA���W�u���l�ˡv\nHP:%d\n����:%d\n���m:%d\n�z���v(x1.2):�H%d0\n",word,hp(ch),dps(ch),def(ch),criti(ch));
			break;
		case 3:
			printf("%s��ܫ��M�A���W�u�d���M�v\nHP:%d\n����:%d\n���m:%d\n�z���v(x1.2):�H%d0\n",word,hp(ch),dps(ch),def(ch),criti(ch));
			break;
		case 4:
			printf("%s��ܰa���A���W�u�P�a���v\nHP:%d\n����:%d\n���m:%d\n�z���v(x1.2):�H%d0\n",word,hp(ch),dps(ch),def(ch),criti(ch));
			break;
		case 5:
			printf("%s��ܥ��t�A���W�u�G���t�v\nHP:%d\n����:%d\n���m:%d\n�z���v(x1.2):�H%d0\n",word,hp(ch),dps(ch),def(ch),criti(ch));
			break;
		case 6:
			printf("%s��ܪ��ߡA���W�u��سߡv\nHP:%d\n����:%d\n���m:%d\n�z���v(x1.2):�H%d0\n",word,hp(ch),dps(ch),def(ch),criti(ch));
			break;
		default:
			printf("�Э��s��J!\n");
			break;
	}
}


int dps(int dps){
	switch(dps){
		case 1:
			return 55;
			break;
		case 2:
			return 60;
			break;
		case 3:
			return 50;
			break;
		case 4:
			return 65;
			break;
		case 5:
			return 52;
			break;
		case 6:
			return 70;
			break;
		default:
			break;
	}
}

int def(int def){
	switch(def){
		case 1:
			return 45;
			break;
		case 2:
			return 40;
			break;
		case 3:
			return 50;
			break;
		case 4:
			return 35;
			break;
		case 5:
			return 48;
			break;
		case 6:
			return 30;
			break;
		default:
			break;
	}
}

int criti(int cri){
	switch(cri){
		case 1:
			return 4;
			break;
		case 2:
			return 3;
			break;
		case 3:
			return 6;
			break;
		case 4:
			return 2;
			break;
		case 5:
			return 5;
			break;
		case 6:
			return 1;
			break;
		default:
			break;
	}
}

int hp(int hp){
	switch(hp){
		case 1:
			return 500;
			break;
		case 2:
			return 400;
			break;
		case 3:
			return 400;
			break;
		case 4:
			return 500;
			break;
		case 5:
			return 400;
			break;
		case 6:
			return 500;
			break;
		default:
			break;
	} 
}


int function_choose(void){
	int ch_choose;
	printf("\n");
	while(1){
		printf("\n�п��:\n1.����\t2.���m\n\n");
		ch_choose=getch()-'0';
		/*printf("\nin_function_choose:%d",ch_choose);*/
		if(ch_choose==1 || ch_choose==2)	break;
	}
	return ch_choose;
}
