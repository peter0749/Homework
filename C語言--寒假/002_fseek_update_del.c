#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LEN 100
#define IDLEN 6
#define NAMELEN 30
#define FLAGLEN 3
#define NUMLEN 10

typedef struct book_struct{
	char id[IDLEN];
	char name[NAMELEN];
	int price;
	int qty;
	char delflag[FLAGLEN];
}BOOK;

void showfiledata(char[] );

int main(void) {
	FILE *fptr;
	char fpath[LEN];
	char search_id[IDLEN], t_price[NUMLEN], t_qty[NUMLEN], search_bookid[IDLEN];
	BOOK my_book;
	int recno = 0;
	char ch[NUMLEN];
	printf("Please enter file path: ");
	gets(fpath);

	fptr = fopen(fpath,"r+");		//Opening file
	if(fptr==NULL) {				//Reporting error when opening file
		puts("An ERROR occured when loading file...\nThe program halted \(-1\)");
		return -1;
	}

	showfiledata(fpath);
	printf("Please select:\n1. Edit\t2. Delect\t3. Exit\n");
	gets(ch);
	if(strncmp(ch,"3",NUMLEN)==0) {
		printf("Bye!\n");
		return 0;
	}

	printf("Please enter bookid: ");
	gets(search_bookid);
	rewind(fptr);
	while(1) {
		if(fread(&my_book,sizeof(BOOK),1,fptr)==NULL) {	//If the bookid does not exist in the file, the program halt.
			printf("Found not the bookid \"%s\" in this file.\n",search_bookid); 
			return 0;
		}
		else {
			if(strncmp(my_book.id,search_bookid,IDLEN)==0 && strncmp(my_book.delflag,"d",FLAGLEN)) {
				if(strncmp(ch,"1",NUMLEN)==0) {
					printf("Editing...\n");
					printf("New name: ");
					gets(my_book.name);
					printf("New ID: ");
					gets(my_book.id);
					printf("New price: ");
					gets(t_price);
					my_book.price = atoi(t_price);
					printf("New remain: ");
					gets(t_qty);
					my_book.qty = atoi(t_qty);

				}
				else if(strncmp(ch,"2",NUMLEN)==0) {
					printf("Delecting\n");
					strcpy(my_book.delflag,"d");
				}

				printf("ARE YOU SURE TO EXECUTE THIS OPERATION? (y/n)\n");			//CHECKING BEFORE DOING ANYTHING
				gets(ch);
				if(strncmp(ch,"y",NUMLEN)==0 || strncmp(ch,"Y",NUMLEN)==0) {
					fseek(fptr,sizeof(BOOK)*recno,0);
					fwrite(&my_book,sizeof(BOOK),1,fptr);
					fclose(fptr);
					break;
				}
				else {
					puts("Abort...\n");
					return 0;
				}
			}
			else {
				recno++;
			}
		}
	}

	puts("Successfully Edited data");
	showfiledata(fpath);
	printf("\n");


	return 0;
}

void showfiledata(char vfpath[] ) {
	int rectot = 0;
	BOOK vbook;
	FILE *vfptr;
	vfptr = fopen(vfpath,"r");
	printf("\nFollowing is the contents of the file.\n");
	while(fread(&vbook,sizeof(BOOK),1,vfptr)!=NULL) {
		if(strcmp(vbook.delflag,"d")!=0) {
			printf("%s %s %d %d\n", vbook.id, vbook.name, vbook.price, vbook.qty);
			rectot++;
		}
	}
	printf("Total number of record: %d\n",rectot);
	fclose(vfptr);

}
