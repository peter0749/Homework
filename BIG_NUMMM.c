#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100

void EN(int n, int arr[10])
{
    int tn;
    int bk[10];
    int ok;
    int i;
    int down;
    //printf("==n %d\n",n);
    down = pow(10,n-1);
    n = pow(10,n);

    //printf("==down %d\n",down);

    while(n>down)
    {
        n--;
        //printf("==%d\n",n);
        for(i=0;i<10;i++)   bk[i] = arr[i];
        tn = n;
        ok = 1;
        do{
            i = tn%10;
            bk[i]--;
            if(bk[i]<0){ok = 0; break;}
            tn/=10;
        }while(tn>0);
        if(ok)
        {
            printf("%d\n",n);
        }
    }
}

int main(void)
{
    int book[10] = {0};     //index0 for 1 index 1 for 2
    int c[MAX] = {0};
    int input;
    int i, j;
    while(scanf("%d",&input)!=EOF)
    {
        book[1] = book[2] = 0;
        book[2] = input/2;
        book[1] = input%2;
        while(book[2]>=0)
        {
            EN(book[1]+book[2],book);

            book[2]--;
            book[1]+=2;
        }
    }

    return 0;
}


