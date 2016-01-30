#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#define LEN 100

int main(void)
{
	FILE *fptr;
	char fpath[LEN];
	int fno,fsize;
	printf("File to open: ");
	gets(fpath);
	fptr=fopen(fpath,"r");
	if(fptr==NULL)
	{
		printf("\nFailed to open file \"%s\".",fpath);
	exit(0);
	}
	fno=fileno(fptr);
	fsize=filelength(fno);
	printf("\nSuccessfully opened file: %s\t(%d bytes).",fpath,fsize);
	fclose(fptr);
	return 0;
	
}
