#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BD 19
#define MAX 25

int is_five(int tar,int arr[][MAX]);
int is_four(int tar,int arr[][MAX], int book[][MAX]);
int cter(const int dir, const int tar, int *ptr, int arr[][MAX]);
int shi(const int dir);

void stat(int tar, int arr[][MAX], int book[][MAX]);

void clean_arr(int arr[][MAX])
{
    int i, j;
    for(i=0;i<MAX;i++)  for(j=0;j<MAX;j++)  arr[i][j] = -1;
    for(i=1;i<=BD;i++)  for(j=1;j<=BD;j++)  arr[i][j] = 0;
}

int main(void)
{
    //freopen("FiveInARow.in","r",stdin);
    //freopen("testout.txt","w",stdout);
    int term;
    int tar;
    int board[MAX][MAX] = {{0}}, book[MAX][MAX] = {{0}};
    int i, j;
    scanf("%d",&term);
    while(term--)
    {
        memset(book,0x00,sizeof(int)*MAX*MAX);
        clean_arr(board);
        scanf("%d",&tar);
        for(i=1; i<=BD; i++)
        {
            for(j=1; j<=BD; j++)
                scanf("%d",&board[i][j]);
        }
        stat(tar,board,book);
        if(term>0)
            printf("\n");
    }
    return 0;
}

void stat(int tar, int arr[][MAX], int book[][MAX])
{
    int i, j;
    int cotar = (tar==1?2:1);
    if(is_five(tar,arr))
    {
        printf("1 %d\n",cotar);
    }
    else if(is_five(cotar,arr))
    {
        printf("1 %d\n",tar);
    }
    else if(is_four(tar,arr,book))
    {
        for(i=1; i<=BD; i++)  for(j=1; j<=BD; j++)
                if(book[i][j]==1)   printf("2 %d %d\n",i,j);
    }
    else
    {
        if(is_four(cotar,arr,book)==1)
        {
            for(i=1; i<=BD; i++)  for(j=1; j<=BD; j++)
                    if(book[i][j]==1)   printf("4 %d %d\n",i,j);
        }
        else
            printf("3\n");
    }
}

int is_five(int tar,int arr[][MAX])
{
    int i, j;
    int dir;
    for(i=1; i<=BD; i++)
    {
        for(j=1; j<=BD; j++)
            if(arr[i][j]==tar)
            {
                for(dir=0; dir<4; dir++)
                {
                    if(cter(dir,tar,&arr[i][j],arr)==5)
                        return 1;
                }
            }
    }
    return 0;
}
int is_four(int tar,int arr[][MAX], int book[][MAX])
{
    int i, j, dir;
    int shifter;       //Shifter
    int count = 0;
    for(i=1; i<=BD; i++)
    {
        for(j=1; j<=BD; j++)
            if(arr[i][j]==tar)
            {
                for(dir=0; dir<4; dir++)
                {
                    if(cter(dir,tar,&arr[i][j],arr)==4)
                    {
                        shifter = shi(dir);
                        if(*(&arr[i][j]-shifter)==0)
                        {
                            count++;
                            *(&book[i][j]-shifter) = 1;
                        }

                        if(*(&arr[i][j]+4*shifter)==0)
                        {
                            count++;
                            *(&book[i][j]+4*shifter) = 1;
                        }
                    }
                }
            }
    }
    return count;
}
int cter(const int dir, const int tar, int *ptr, int arr[][MAX])
{
    int count = 0;
    while(tar==*ptr)
    {
        count++;
        ptr+=shi(dir);
    }
    /*The initial number of count MUST BE ZERO!!!*/
    return count;
}

int shi(const int dir)
{
    int shift;
    if(dir==0)		//m = 0
    {
        shift = 1;
    }
    else if(dir==1)		//m = -1
    {
        shift = (MAX + 1);
    }
    else if(dir==2)		//m = undefine
    {
        shift = MAX;
    }
    else		//dir==4   m = 1
    {
        shift = (MAX - 1);
    }
    return shift;
}
