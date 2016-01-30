#include <stdio.h>
#include <stdlib.h>
#define N 120
#define M 12

typedef struct COD
{
    int x;
    int y;
    int err;
} REC;



REC cord[10005];
int map[N][N] = {0};
int check[M][M] = {0};

void clean_arr(void)
{
    int i;
    for(i=0;i<10005;i++)
    {
        cord[i].err = 0;
        cord[i].x = 0;
        cord[i].y = 0;
    }
}

int main(void)
{
    int n,m;
    int i ,j;
    int x, y;
    int k, counter;
    int min;
    int flag;

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            map[i][j] = -1;
    }

    while(scanf("%d",&m)!=EOF)
    {
        clean_arr();
        flag = 0;
        //min = 999;
        counter = 0;
        for(i=0; i<m; i++)
        {
            for(j=0; j<m; j++)
                scanf("%d",&check[i][j]);
        }

        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                scanf("%d",&map[i][j]);
        }
        for(y=0; y<n; y++)
        {
            for(x=0; x<n; x++)
            {
                for(k=0; k<(m/2); k++)
                {
                    for(i=k; i<m-k; i++)
                    {
                        if(i==k||i==m-k-1)
                        {
                            for(j=k; j<m-k; j++)
                            {
                                if(map[y+i][x+j]!=check[i][j])
                                {
                                    cord[counter].err += (k+1);
                                }
                            }
                        }
                        else
                        {
                            j = k;
                            if(map[y+i][x+j]!=check[i][j])
                            {
                                cord[counter].err += (k+1);
                            }
                            j = m-k-1;
                            if(map[y+i][x+j]!=check[i][j])
                            {
                                cord[counter].err += (k+1);
                            }
                        }

                    }
                }
                cord[counter].x = x+1;
                cord[counter].y = y+1;

                if(cord[flag].err > cord[counter].err)	flag = counter;
                counter++;
            }
        }
        printf("%d %d\n",cord[flag].y,cord[flag].x);

    }
    return 0;
}
