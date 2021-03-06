#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int cases;
    while(scanf("%d", &cases) == 1) {
        int *ptr = (int *)malloc(sizeof(int) * cases);
        for(int i = 0; i < cases; i++)
            scanf("%d", ptr + i);

        qsort(ptr, cases, sizeof(int), cmp);

        for(int i = 0; i < cases; i++) {
                printf("%d ", *(ptr + i));
        }
        printf("\n");
        free(ptr);
    }
}

