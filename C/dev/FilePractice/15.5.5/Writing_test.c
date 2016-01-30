#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include <ctype.h>
#define LEN 100

int main(void)
{
	FILE *fptr;
	char fpath[LEN],keyin[LEN];
	int fno,fsize,i;
	char ch;
	printf("Writing test...\n");
	printf("File to open: ");
	gets(fpath);
	fptr=fopen(fpath,"a+");
	if(fptr==NULL)
	{
		printf("\nFailed to open file \"%s\", file may not exist. ",fpath);
		exit(0);
	}
	while(1)
	{		
		printf("\nAdding new data? (Y/N)");
		if(toupper(getche())=='Y')
		{
			printf("\nInput: ");
			gets(keyin);
			for(i=0;i<strlen(keyin);i++)
			{
				fputc(keyin[i],fptr);
			}
			fputc('\n',fptr);
		}
		else
		{
			break;
		}
	}
	printf("\n");
	fclose(fptr);
	printf("\n");
	system("pause");
	
	return 0;
}
