#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int k;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(k=0; k<n; k++)
        {
            int input;
            int i; /*INDEX*/
            scanf("%d",&input);
            for(i=1; i<input; i++)
                printf("%d\n",i);
            for(i; i>0; i--)
                printf("%d\n",i);
            if(k!=n-1)
                printf("\n");
        }
    }
    return 0;
}
