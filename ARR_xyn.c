#include <stdio.h>
#include <stdlib.h>
#define M_DIM 7

void cp(int dim, int a[][M_DIM], int b[][M_DIM]);
void mul(int dim, int p, int a[][M_DIM], int b[][M_DIM], int c[][M_DIM]);
void xyn(int dim, int p, int time, int input[][M_DIM]);

int main(void)
{
    int p,dim,time;
    int i, j;
    int arr[M_DIM][M_DIM] = {{0}};
    while(1)
    {
        scanf("%d %d %d",&dim,&time,&p);
        if(dim==0 && time==0 && p==0)
            break;
        for(i=0;i<dim;i++)
        {
            for(j=0;j<dim;j++)
                scanf("%d",&arr[i][j]);
        }
        xyn(dim,p,time,arr);
        for(i=0;i<dim;i++)
        {
            for(j=0;j<dim-1;j++)
                printf("%d ",arr[i][j]);
            printf("%d\n",arr[i][j]);
        }

    }
    return 0;
}

void cp(int dim, int a[][M_DIM], int b[][M_DIM])
{
    int i, j;
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
            a[i][j] = b[i][j];
    }
}

void mul(int dim, int p, int a[][M_DIM], int b[][M_DIM], int c[][M_DIM])
{
    int i, j, k;
    long long int t;
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
            c[i][j] = 0;
    }
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
        {
            for(k=0;k<dim;k++)
            {
                t = (long long int)a[i][k] * b[k][j];
                t %= p;
                c[i][j] += (int)t;
                c[i][j] %= p;
                //c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
}

void xyn(int dim, int p, int time, int input[][M_DIM])
{
    int temp1[M_DIM][M_DIM], temp2[M_DIM][M_DIM];
    int result[M_DIM][M_DIM];
    int i, j;
    for(i=0;i<dim;i++)
    {
        for(j=0;j<dim;j++)
            result[i][j] = 0;
    }
    for(i=0;i<dim;i++)
        result[i][i] = 1;           /*Identical Metrics*/
    cp(dim,temp1,input);
    while(time>0)
    {
        if(time&1)
        {
            mul(dim,p,temp1,result,temp2);
            cp(dim,result,temp2);
        }
        mul(dim,p,temp1,temp1,temp2);
        cp(dim,temp1,temp2);

        time>>=1;
    }
    cp(dim,input,result);
}
