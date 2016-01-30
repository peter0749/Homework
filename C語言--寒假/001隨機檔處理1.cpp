#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LEN 100
#define IDLEN 6
#define NAMELEN 30
#define FLAGLEN 3

typedef struct
{
	char bookid[IDLEN];
	char bookname[NAMELEN];
	int price;
	int qty;
	char flag[FLAGLEN];
}BOOK;

int filelength(char [] );

int main(void)
{
	FILE *fptr;
	BOOK mybook;
	char fpath[LEN], rec_count=0;
	char yn[FLAGLEN];
	int op, flen, fno;
	while(1)
	{
		puts("請選擇 ->\n1.開新檔\n2.開舊檔");
		gets(yn);
		op = atoi(yn);
		if(op==1)
		{
			printf("請輸入檔案位置: ");
			gets(fpath);
			fptr = fopen(fpath,"w+");
		}
		else if(op==2)
		{
			printf("請輸入檔案位置: ");
			gets(fpath);
			fptr = fopen(fpath,"a+");			//Attach
		}
		else
			continue;
		break;
	}
	if(fptr==NULL)
	{
		puts("Failed to open file.");
		return -1;
	}
	while(1)
	{
		printf("\n請問是否要新增資料(Y/N): ");
		gets(yn);
		if(tolower(*(yn))=='y')
		{
			puts("\n請輸入要新增的資料->");
			printf("書號:\t");
			gets(mybook.bookid);
			printf("書名:\t");
			gets(mybook.bookname);
			printf("單價:\t");
			gets(yn);
			mybook.price = atoi(yn);
			printf("庫存:\t");
			gets(yn);
			mybook.qty = atoi(yn);
			
			fwrite(&mybook,sizeof(BOOK),1,fptr);
		}
		else if('n'==tolower(yn[0]))
			break;
	}
	
	fclose(fptr);
	fptr = fopen(fpath,"r");
	if(fptr==NULL)	return -2;
	puts("資料更新完成...");
	fclose(fptr);

	flen = filelength(fpath);
	rec_count = flen/sizeof(BOOK);

	fptr = fopen(fpath,"r");
	printf("目前檔案大小 %d bytes, 共 %d 筆資料, 內容如下:\n", flen, rec_count);
	while(fread(&mybook,sizeof(BOOK),1,fptr)!=NULL)
	{
		printf("%s\t%s\t%d\t%d\n",mybook.bookid,mybook.bookname,mybook.price,mybook.qty);
	}
	fclose(fptr);
	printf("\n");
	return 0;
	
	return 0;
} 

int filelength(char path[])
{
	FILE *vfptr;
	int len;
	vfptr = fopen(path,"r");
	fseek(vfptr, 0L, SEEK_END);
	len = ftell(vfptr);
	fclose(vfptr);
	return len;
}
