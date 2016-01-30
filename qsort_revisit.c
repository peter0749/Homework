#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100000

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void q_sort(int left, int right, int c[]);

int main(void)
{
    int input[MAX];
    int count;
    int i;
    char temp[MAX];
    char *ptr = NULL;

    while((gets(temp))!=NULL)
    {
        count = 0;
        ptr = strtok(temp," ");
        while(ptr!=NULL)
        {
            input[count++] = atoi(ptr);
            ptr = strtok(NULL," ");
        }
        q_sort(0,count-1,input);
        for(i=0; i<count; i++)
        {
            printf("i(%d) = %d\n",i,input[i]);
        }
    }

    return 0;
}

void q_sort(int left, int right, int c[])
{
    int i = left, j = right+1;
    int pivot;
    if(left>=right)
        return;
    pivot = c[left];
    do
    {
        do
        {
            i++;
        }
        while(c[i]<pivot);
        do
        {
            j--;
        }
        while(c[j]>pivot);
        if(i<j)
            swap(c+i,c+j);
    }while(i<j);
    swap(c+left,c+j);
    q_sort(left,j-1,c);
    q_sort(j+1,right,c);
}
