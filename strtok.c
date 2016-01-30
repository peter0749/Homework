#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

int main(void)
{
    char temp[MAX];
    char *tok=" ,;\t\b\r";
    char *ptr = NULL;
    int sum;
    while(gets(temp)!=NULL)
    {
        sum = 0;
        ptr = strtok(temp,tok);
        while(ptr!=NULL)
        {
            sum += atoi(ptr);
            ptr = strtok(NULL,tok);
        }
        printf("%d\n",sum);
    }
    return 0;
}
