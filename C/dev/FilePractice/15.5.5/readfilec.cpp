#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#define LEN 100

int main(void)
{
	FILE *fptr;
	char fpath[LEN];
	int fno,fsize;
	char ch;
	printf("File to open: ");
	gets(fpath);
	fptr=fopen(fpath,"r");
	if(fptr==NULL)
	{
		printf("\nFiled to open file \"%s\", the file may not exist.",fpath);
		exit(0);
	}
	fno=fileno(fptr);
	fsize=filelength(fno);
	printf("\nSuccessfully opened file \"%s\"\t(%d bytes).\nFollowing is the context:\n",fpath,fsize);
	while((ch=fgetc(fptr))!=EOF)
	{
		putchar(ch);
	}
	fclose(fptr);
	printf("\n\n");
	
	return 0;
}
