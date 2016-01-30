#include <stdio.h>
#include <stdlib.h>
#define MAX 1002

//void b_sort(int,int,int,int[],int[]);
int merge(int,int,int[],int[],int[]);
void print_arr(int,int[]);

int main(void)
{
    //freopen("testout.txt","w",stdout);
    int count;
    int na, nb, i;
    int a[MAX], b[MAX], c[MAX*2+3];
    int term;
    scanf("%d",&term);
    while(term--)
    {
        scanf("%d%d",&na,&nb);
        for(i=0; i<na; i++)
            scanf("%d",&a[i]);
        for(i=0; i<nb; i++)
            scanf("%d",&b[i]);
        count = merge(na,nb,a,b,c);
        printf("%d\n",count);
        print_arr(na+nb,c);
    }

    return 0;
}

int merge(int na, int nb, int a[], int b[], int c[])
{
    int count = 0;
    int ic = 0;
    int ia=0, ib=0;
    while(ia<na && ib<nb)
    {
        if(a[ia]<=b[ib])
            c[ic++] = a[ia++];
        else
            c[ic++] = b[ib++];
        //printf("---c[%d] = %d\n",ic-1,c[ic-1]);
        count++;
    }

    while(ia<na)
    {
        c[ic++] = a[ia++];
    }
    while(ib<nb)
    {
        c[ic++] = b[ib++];
    }

    /*
    if(ia!=na)
        b_sort(na,ia,ic,a,c);
    else
        b_sort(nb,ib,ic,b,c);
    */
    return count;
}

void print_arr(int n, int arr[])
{
    int i;
    if(n<=6)
    {
        for(i=0; i<n-1; i++)
            printf("%d ",arr[i]);
        printf("%d\n",arr[i]);
    }
    else
    {
        for(i=0;i<3;i++)
            printf("%d ",arr[i]);
        for(i=n-3;i<n-1;i++)
            printf("%d ",arr[i]);
        printf("%d\n",arr[i]);
    }

}
/*
void b_sort(int na, int ia, int ic, int a[], int c[])
{
    int temp;
    int i, j;
    for(i=na-1; i>=ia; i--)
    {
        for(j=ia; j<=i-1; j++)
        {
            if(a[j+1]>a[j])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        c[ic++] = a[i];

    }
}
*/
