#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
int main(void)
	{
		int guess, number ;
		char yn ;
		MAIN:
		srand((unsigned)time(NULL)) ;
		guess=rand()%9+1 ;
		printf("Please guess a number. (1~9) \n") ;
		scanf("%d", &number) ;
		if(number==guess)
			{
				printf("You\'re right! The number is: %d \n", guess) ;
				printf("Again? (Y/N) \n") ;
				goto AGAIN ;
			}
		else
			{
				printf("Wrong number! The right is: %d \n", guess) ;
				printf("Try again? (Y/N) \n") ;
				goto AGAIN ;
			}
		AGAIN:
			yn=toupper(getche()) ;
				if(yn=='Y')
					{
						printf("\n") ;
						goto MAIN ;
					}
				else
					{
						printf("\nThe game is over. \n") ;
					}
		system("PAUSE") ;
		return 0 ;
	}
