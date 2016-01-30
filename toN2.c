#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    while(scanf("%d",&i)!=EOF)
    {
        printf("%d\n", i&2147483647);
    }
    return 0;
}
