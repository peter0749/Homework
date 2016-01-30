#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <ctype.h>
#include <string.h>
#define LEN 100

int main(void)
{
	FILE *fptr;
	char fpath[LEN],keyin[LEN];
	int fno,fsize,i;
	char ch;
	printf("\n1.Create a New file\t2. Edit a Old file\n");
	if(getche()=='1')
	{
		printf("\nFile to Create: ");
		gets(fpath);
		fptr=fopen(fpath,"w+");
	}
	else
	{
		printf("\nFile to Edit:");
		gets(fpath);
		fptr=fopen(fpath,"a+");
	}
	if(fptr==NULL)
	{
		printf("\nFailed to open file \"%s\", the file may not exitst...",fpath);
		exit(0);
	}
	fno=fileno(fptr);
	fsize=filelength(fno);
	printf("\nSuccessfully opened file \"%s\" (%d bytes).",fpath,fsize);
	while(1)
	{
		printf("\nAdding data? (Y/N)");
		if((toupper(getche()))=='Y')
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
			fclose(fptr);
			break;
		}
	}
	fptr=fopen(fpath,"r");
	fno=fileno(fptr);
	fsize=filelength(fno);
	printf("\nFinished updating data. (%d bytes)",fsize);
	printf("\nFollowing is the context:\n");
	while((ch=fgetc(fptr))!=EOF)
	{
		putchar(ch);
	}
	fclose(fptr);
	printf("\n");
	system("pause");
	
	return 0;
}
