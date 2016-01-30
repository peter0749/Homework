#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
int main(){
	int number,guess,x;
	int y=10;
	char yn; 
	for(;;){
		if(y==0)break;
		srand((unsigned)time(NULL));
		number=rand()%9+1;
		printf("Please guess a number. (1~9)\n");
		scanf("%d", &guess);
		if(guess==number)
		{
			printf("You\'r right! The game is over.\n");
			break;
		}
		else
		{
				printf("Wrong number! The right number is: %d\n%d times ramain.\nTry again? (Y/N)\n", number,y);
				yn=getche();
				if(yn=='y' || yn=='Y')
				{
					y--;
					printf("\n");
				}
				else if(yn=='n' || yn=='N')
				{
					printf("\nThe game is over.\n");
					break;
				}
				else
				{
					printf("\nPlease enter Y/N.\n");
				}
				
	     	
		}
	}
	system("PAUSE");
	return 0;
}
