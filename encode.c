#include <stdio.h>
#include <stdlib.h>
#define LEN 200

char *seek_iden(char *, char []);

int main(void)
{
    char temp[LEN];
    char *head=NULL, *tail=NULL;
    while(scanf("%s",temp)!=EOF)
    {
        head = temp;
        while(head!=NULL && *head!='\0' && *head!='\n')
        {
            tail = seek_iden(head,temp);
            printf("%d%c",tail-head,*head);
            head = tail;
        }
        printf("\n");
    }

    return 0;
}

char *seek_iden(char *head, char input[])
{
    char *ptr = head + 1;
    while(ptr!=NULL && *head == *ptr)
    {
        ptr++;
    }
    if(ptr==NULL)
        return NULL;
    return ptr;
}
