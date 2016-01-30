#include <stdio.h>
#include <stdlib.h>

long long int day_count(int,int,int,int);
int is_leap(int);

int hm[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(void)
{
	long long int a,b;
	int year, tyear, mon, tmon, day, tday;
	while(scanf("%d%d%d%d%d%d",&year,&mon,&day,&tyear,&tmon,&tday)!=EOF)
	{
		a = day_count(tyear,tyear,tmon,tday);
		b = day_count(tyear,year,mon,day);
		printf("%lld\n",b-a);
	}

	return 0;
}

long long int day_count(int tyear, int year, int mon, int day)
{
	long long int count = 0;
	int i,j;	/*INDEX*/
	/*printf("--%d %d\n",year,hm[2]);*/
	count += (long long int)day;
	mon--;
	for(i=year;i>=tyear;i--)
	{
		hm[2] = is_leap(i);
		for(j=mon;j>=1;j--)
		{
			count += (long long int)hm[j];
		}
		mon = 12;
	}
	return count;
}

int is_leap(int year)
{
	return (year%400 == 0 || (year%100 != 0) && (year%4 == 0)) ? 29:28;
}
