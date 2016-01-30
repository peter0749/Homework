#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 52
#define N_FLAG 6

void prtstack(int n, int arr[N_FLAG][MAX]);

int main(void)
{
    int a[N_FLAG][MAX] = {0};
    char temp[MAX];
    char *ptr = NULL;
    int i, j, k;
    while(1)
    {
        memset(a,0x00,sizeof(int)*MAX*N_FLAG);
        for(i=0; i<N_FLAG; i++)
        {
            if(fgets(temp,MAX,stdin)==NULL)
                exit(0);
            ptr = strtok(temp,",\n");
            j = 0;
            while(ptr!=NULL)
            {
                a[i][j++] = atoi(ptr);
                ptr = strtok(NULL,",\n");
            }
        }
#if 0
        for(k=0; k<6; k++)
        {
            for(j=0; j<3; j++)
                printf("%d\n",a[k][j]);
        }
#endif // 1
        prtstack(0,a);
    }

    return 0;
}

void prtstack(int n, int arr[N_FLAG][MAX])
{
#if 0
    int k,j;
    for(k=0; k<6; k++)
    {
        for(j=0; j<3; j++)
            printf("%d\n",arr[k][j]);
    }
    if(n<5)
        {
            prtstack(n+1,arr);
        }
#endif // 1
#if 0

#endif
}
