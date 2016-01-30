#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int count=1;
    int i,j,k,l;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(l=0;l<n;l++)
        {
            scanf("%d",&i);
            scanf("%d",&j);
            printf("gcd\(%d,%d\)=",i,j);
            count=1;
            while(i % j != 0)
            {
                k = i % j;
                i = j;
                j = k;
                count++;

            }
            if(l == n-1)
                printf("%d, using %d division.",j,count);

            else
                printf("%d, using %d division.\n",j,count);
        }


    }

    return 0;
}
