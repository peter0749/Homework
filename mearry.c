#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintA (int (*A)[10]){
	int i;
	for(i=0; i<10; ++i)
		printf("%d, ", (*A)[i]);
	printf("\n");
}
void PrintAA (int (*A)[3][10]){
	int i;
	for(i=0; i<3; ++i)
		PrintA(&(*A)[i]);
}
int main( void ){
	int MM[3][10] = {0};
	int i, j, k = 0;
	for(i=0; i<3; i++)
		for(j=0; j<10; j++, k++)
			MM[i][j] = k;
	PrintAA(&MM);
}
