#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 3

typedef struct grade
{
    int sum;
    int p[N];
} GRADE;

void swap(struct grade*, struct grade*);
void sort(int, int , struct grade[]);
void printout(int,int, struct grade[]);

int main(void)
{
    //freopen("testout.txt","w",stdout);
    GRADE student[1002];
    int st2reward;
    int times;
    int term;
    int i,j;
    scanf("%d",&times);
    while(times--)
    {
        scanf("%d %d",&term,&st2reward);

        for(j=0; j<term; j++)
        {
            student[j].sum = 0;
            for(i=0; i<N; i++)
            {
                scanf("%d",&student[j].p[i]);
                student[j].sum += student[j].p[i];
            }

        }
        sort(term, st2reward, student);
        printout(term,st2reward, student);
        if(times>0)
            printf("\n");
    }

    return 0;
}

void swap(struct grade *a, struct grade *b)
{
    GRADE temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int m, int n, struct grade data[])
{
    int i, j, max;
    for(i=0; i<n; i++)
    {
        max = i;
        for(j=i+1; j<m; j++)
        {
            if(data[j].sum>data[max].sum)
                max = j;
        }
        if(max!=i)
            swap(data+i,data+max);
    }
}

void printout(int m, int n, struct grade data[])
{
    double sum[N] = {0};
    int i ,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<N-1; j++)
        {
            printf("%d ",data[i].p[j]);
        }
        printf("%d %d\n",data[i].p[j],data[i].sum);
        //printf("data[%d].sum = %f\n",i,data[i].sum);
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<m;j++)
        {
            sum[i] += data[j].p[i];
        }
        sum[i] /= m;
    }
    for(i=0;i<N-1;i++)
        printf("%.2lf ",sum[i]);
    printf("%.2lf\n",sum[i]);
}
