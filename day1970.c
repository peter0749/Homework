#include <stdio.h>
#include <stdlib.h>

int hm_days(int,int);

int is_leap(int);

int main(void)
{
	int days_count;
	int i,j;
	int year, mon, dat;
	int k;
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(k=0; k<n; k++)
		{
			days_count=0;
			scanf("%d/%d/%d", &year, &mon, &dat);
			if(year < 1970 || mon > 12 || mon < 1 || dat > hm_days(year,mon) || dat < 1)
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
	return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}

int hm_days(int year,int mon)
{
	switch(mon)
	{
	case 1:	case 3:	case 5:	case 7:	case 8:	case 10:case 12:
		return 31;
	case 2:
		return is_leap(year) ? 29:28;
	default:
		return 30;
	}
}


