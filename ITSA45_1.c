#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char temp[1000];
    int k[200];
    char str[1000][1000];
    char *num;
    int i;
    while((fgets(temp,200,stdin))!=NULL)
    {
        i = 0;
        num = strtok(temp," \n");
        while(num != NULL)
        {
            strcpy(str[i++],num);
            num = strtok(NULL," \n");
        }
        for(i=i-1;i>=1;i--)
            printf("%s ",str[i]);
        printf("%s\n",str[i]);
    }
    return 0;
}
