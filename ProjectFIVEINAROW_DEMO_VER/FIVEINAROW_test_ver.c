#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BD 19
#define MAX 30

void game(int tar, int arr[][MAX]);
void cp_mtx(int des[][MAX], int src[][MAX]);
int is_five(int tar,int arr[][MAX]);
int automode(int tar,int cotar,int arr[][MAX]);
int cter(const int dir, const int tar, int *ptr, int arr[][MAX]);
int shi(const int dir);
void clean_arr(int arr[][MAX]);


int main(void)
{
    //freopen("testout.txt","w",stdout);
    int term;
    int tar;
    int board[MAX][MAX] = {{0}};
    int i, j;
    scanf("%d",&term);
    while(term--)
    {
        clean_arr(board);
        scanf("%d",&tar);
        for(i=1; i<=BD; i++)
        {
            for(j=1; j<=BD; j++)
                scanf("%d",&board[i][j]);
        }
        game(tar,board);
        if(term>0)
            printf("\n\n");
    }
    return 0;
}


void game(int tar, int arr[][MAX])     //difcult 0:easy 1:hard
{
    int state;
    int cotar = (tar==1?2:1 );
    int fakeptr = -1;

    state = is_five(2,arr);
    if(state==1)
    {
        printf("1 1");
        return;
    }

    state = is_five(1,arr);
    if(state==1)
    {
        printf("1 2");
        return;
    }


    if(automode(tar,tar,arr))
    {
        //printf("\n");
        return;
    }   //Search status "2"        (ATTACK)

    automode(cotar,tar,arr);    //Search status "3", "4"   (DEFENSE)
    //printf("\n");
    //Done
}

void cp_mtx(int des[][MAX], int src[][MAX])
{
    int i, j;
    for(i=0; i<MAX; i++)
    {
        for(j=0; j<MAX; j++)
            des[i][j] = src[i][j];
    }
}

int is_five(int tar,int arr[][MAX])
{
    int i, j;
    int len;
    int dir;
    for(i=1; i<=BD; i++)
    {
        for(j=1; j<=BD; j++)
            if(arr[i][j]==tar)
            {
                for(dir=0; dir<4; dir++)
                {
                    len = cter(dir,tar,&arr[i][j],arr);
                    if(len>5)
                        return -1;
                    if(len==5)
                        return 1;

                }
            }
    }
    return 0;
}
int automode(int tar,int cotar,int arr[][MAX])
{
    int i, j, dir, k , l;
    int shifter;       //Shifter
    int bk[MAX][MAX];
    //int map[MAX][MAX];
    int valid[500][2];
    int sul[500][2];
    int ok = 0;
   // int first = 1;

    k = 0;
    for(i=1;i<=BD;i++)
    {
        for(j=1;j<=BD;j++)
        {
            if(arr[i][j] == 0)
            {
                valid[k][0] = i;
                valid[k][1] = j;
                k++;
            }
        }
    }

    j = 0;
    if(k>0)
    {
        for(i=0; i<k; i++)
        {
            cp_mtx(bk,arr);
            bk[valid[i][0]][valid[i][1]] = tar;
            if(is_five(tar,bk)==1)
            {
                    sul[j][0] = valid[i][0];
                    sul[j][1] = valid[i][1];
                    j++;
            }

        }
    }

    if(tar==cotar)
    {
        if(j>0)
        {
            printf("2");
            for(i=0; i<j; i++)
                printf(" %d %d",sul[i][0], sul[i][1]);
            return 1;
        }
        return 0;
    }
    //tar!=cotar
    if(j==1)
    {
        printf("4 %d %d",sul[0][0],sul[0][1]);
    }
    else
        printf("3");

    return 0;       //Nothing
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
    //printf("count = %d\n",count);
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


void clean_arr(int arr[][MAX])
{
    int i, j;
    for(i=0; i<MAX; i++)  for(j=0; j<MAX; j++)  arr[i][j] = -1;
    for(i=1; i<=BD; i++)  for(j=1; j<=BD; j++)  arr[i][j] = 0;
}
