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
							printf("觸發爆擊，對敵人增加0.2倍傷害:%d\n",ch_hit);
						}
						else{
							ch_hit=dps(ch);
							printf("對敵人傷害:%d\n",ch_hit);
						} 
						chhp-=ene_hit;
						printf("受敵人傷害%d\n您的HP:%d\n",ene_hit,chhp);
						ene_hit=0;
						break;
					case 2:
						if(ene_hit<def(ch)){
							printf("完美防禦\n您的HP:%d\n",chhp);
							break;
						}
						else{
							chhp-=(ene_hit-def(ch));
							printf("您受到敵人%d傷害\n您的HP:%d\n",def(ch)-ene_hit,chhp);
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
						printf("敵人HP:%d",enehp); 
						ch_hit=0;
						break;
					case 2:
						if(ch_hit<def(enemy)){
							if(ch_choose==1)	printf("MISS!\n");
							printf("敵人HP:%d",enehp);
							break;
						}
						else{
							enehp-=(ch_hit-def(enemy));
							printf("敵人沒有完全擋住攻擊,敵人HP:%d",enehp);
						}
						ch_hit=0;
						break;
					default:
						break;
				}
				
			}
			if(chhp>0)	printf("\n妳贏了!\n");
			else	printf("\n\n妳輸了...\n");
		}
	}
	return 0;
} 

int choose_char(void){
	int ch;
	char yes[4];
	char *name[]={"泰瑋","子誼","宣霖","軒萱","光宇","阿喜"};
	printf("\n\n請選擇角色:\n1.泰瑋\t2.子誼\t3.宣霖\t4.軒萱\t5.光宇\t6.阿喜\n");
	ch=getch()-'0';
	charactor_info(ch,0);
	if(1<=ch && ch<=6){
		printf("您確定要選擇%s嗎?(yes/no)\n",name[ch-1]);
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
		word="您";
	}
	else{
		word="敵方"; 
	}
	switch(ch){
		case 1:
			printf("%s選擇泰瑋，全名「邱泰瑋」\nHP:%d\n攻擊:%d\n防禦:%d\n爆擊率(x1.2):％%d0\n",word,hp(ch),dps(ch),def(ch),criti(ch));
			break;
		case 2:
			printf("%s選擇子誼，全名「楊子誼」\nHP:%d\n攻擊:%d\n防禦:%d\n爆擊率(x1.2):％%d0\n",word,hp(ch),dps(ch),def(ch),criti(ch));
			break;
		case 3:
			printf("%s選擇宣霖，全名「吳宣霖」\nHP:%d\n攻擊:%d\n防禦:%d\n爆擊率(x1.2):％%d0\n",word,hp(ch),dps(ch),def(ch),criti(ch));
			break;
		case 4:
			printf("%s選擇軒萱，全名「周軒萱」\nHP:%d\n攻擊:%d\n防禦:%d\n爆擊率(x1.2):％%d0\n",word,hp(ch),dps(ch),def(ch),criti(ch));
			break;
		case 5:
			printf("%s選擇光宇，全名「鄭光宇」\nHP:%d\n攻擊:%d\n防禦:%d\n爆擊率(x1.2):％%d0\n",word,hp(ch),dps(ch),def(ch),criti(ch));
			break;
		case 6:
			printf("%s選擇阿喜，全名「邵建喜」\nHP:%d\n攻擊:%d\n防禦:%d\n爆擊率(x1.2):％%d0\n",word,hp(ch),dps(ch),def(ch),criti(ch));
			break;
		default:
			printf("請重新輸入!\n");
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
		printf("\n請選擇:\n1.攻擊\t2.防禦\n\n");
		ch_choose=getch()-'0';
		/*printf("\nin_function_choose:%d",ch_choose);*/
		if(ch_choose==1 || ch_choose==2)	break;
	}
	return ch_choose;
}
