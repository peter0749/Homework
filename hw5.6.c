#include <stdio.h>
#include <stdlib.h>

int hm_days(int,int);

int is_leap(int);

int main(void)
{
    int k;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(k=0; k<n; k++)
        {
            int days_count=0;
            int i,j;
            int year, mon, dat;
            scanf("%d/%d/%d", &year, &mon, &dat);
            if(year < 1970 || mon > 12 || mon < 1 || dat > 31 || dat < 1)
            {
                printf("0\n");
                continue;
            }
            else if(mon == 2 && is_leap(year) == 1 && dat > 29)
            {
                printf("0\n");
                continue;
            }
            else if(mon == 2 && is_leap(year) == 0 && dat > 28)
            {
                printf("0\n");
                continue;
            }
            else
            {
                days_count+=dat;
                mon--;

                for(j=year; j>=1970; j--)
                {
                    for(i=mon; i>0; i--)
                    {
                        days_count+=hm_days(j,i);
                    }
                    mon=12;
                }

                printf("%d\n",days_count);
            }
        }
    }
    return 0;
}

int is_leap(int year)
{
    if(year % 400 == 0)
        return 1;
    else if(year % 100 != 0 && year % 4 == 0)
        return 1;
    else
        return 0;
}

int hm_days(int year,int mon)
{
    switch(mon)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 2:
        if(is_leap(year) == 1)
            return 29;
        else
            return 28;
    default:
        return 30;
    }
}
