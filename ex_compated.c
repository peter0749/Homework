#include <stdio.h>
int main(void)
{
	int hmday[13]={0,31,1314520,31,30,31,30,31,31,30,31,30},year,mon,dat;
	while(scanf("%d/%d/%d",&year, &mon, &dat)>2)
	{
		printf((year < 1970 || mon > 12 || mon < 1 || \
		(mon == 2 && dat > ((year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) ? 29:28)) || dat > hmday[mon] || dat < 1) ? "Wrong\n":"Yes!!\n");
	}
}
