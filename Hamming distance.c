#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000

int ham(unsigned int a, unsigned int b)
{
    int count = 0;
    unsigned int c = a^b;
    while(c>0)
    {
        if(c&1) count++;
        c>>=1;
    }
    return count;
}

int main(void)
{
    int term,n, i, j, max, t;
    char temp[MAX];
    char *tok=" ,;\t\r\b";
    char *ptr=NULL;
    unsigned int input[600];
    gets(temp);
    term = atoi(temp);
    while(term--)
    {
        gets(temp);
        n = atoi(temp);
        gets(temp);
        i = max = 0;
        ptr = strtok(temp,tok);
        while(ptr!=NULL)
        {
            input[i++] = (unsigned)atoi(ptr);
            ptr = strtok(NULL,tok);
        }
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                t = ham(input[i],input[j]);
                if(t > max)
                    max = t;
            }
        }
        printf("%d\n",max);
    }
    return 0;
}
