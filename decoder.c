#include <stdio.h>
#include <stdlib.h>

char *getword(char *ptr, char temp[]);
char *getnum(char *ptr, char temp[]);

int main(void)
{
    char *head = NULL;
    char *tail = NULL;
    char temp[2000];
    char t[1200];
    int leng;
    int i;
    while((gets(temp))!=NULL)
    {
        head = temp;
        while(head!=NULL && *head!='\0' && *head!='\n')
        {
            tail = getnum(head,temp);
            for(i=0; i<tail-head; i++)
                t[i] = *(head+i);
            t[i] = '\0';
            leng = atoi(t);
            head = tail;
            tail = getword(head,temp);
            for(i=0; i<tail-head; i++)
                t[i] = *(head+i);
            t[i] = '\0';
            for(i=0; i<leng; i++)
                printf("%s",t);
            head = tail;
        }
        printf("\n");
    }
    return 0;
}

char *getword(char *ptr, char temp[])
{
    char *tail = ptr+1;
    while(*tail<='z' && *tail>='a' || *tail<='Z' && *tail>='A')
    {
        tail++;
    }

    return tail;
}

char *getnum(char *ptr, char temp[])
{
    char *tail = ptr+1;
    while(*tail<='9' && *tail>='0')
    {
        tail++;
    }

    return tail;
}
