#include <stdio.h>
#include <stdlib.h>

int input_sudoku(void);

int main(void){
	while(1){
		if(input_sudoku()==0)	break;
		else if(input_sudoku()==1)	printf("yes\n");
		else if(input_sudoku()==2)	printf("no\n");
	}
	return 0;
} 

int input_sudoku(void){
	int i;
	char sudoku[9][10];
	for(i=0;i<9;i++){
		if(scanf("%s",&sudoku[i]==EOF))	return 0;
		/*Return 0 if input==EOF, then break in main function.*/
	}
	/*for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			printf("%d ",sudoku[i][j]);
		}
		printf("\n");
	}*/
	
	/*Compare x,y.*/
	int j,k,l;
	for(i=0;i<9;i++){
		for(j=0;j<8;j++){
			for(k=j+1;k<9;k++){
				if(sudoku[i][j]==sudoku[i][k])	return 2;
				if(sudoku[j][i]==sudoku[k][i])	return 2;
			}
		}
	}
	
	/*Compare 3x3.*/
	for(i=0;i<=6;i+=3){
		for(j=0;j<=6;j+=3){
			char temp[10];
			for(k=i;k<=i+2;k++){
				for(l=j;l<=j+2;j++){
					temp[i++]=sudoku[k][l];
				}
			}
			for(k=0;k<8;k++){
				for(l=k+1;l<9;l++){
					if(temp[k]==temp[l])	return 2;
				}
			}
		}
	}
	return 1;
}


