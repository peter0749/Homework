#include <stdio.h>

int main(void)

{

	int hmday[13]={0,31,28,31,30,31,30,31,31,30,31,30};

	int year,mon,dat;

	while(scanf("%d/%d/%d",&year, &mon, &dat)>2)

	{

		hmday[2] = (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) ? 29:28;

		printf((year < 1970 || mon > 12 || mon < 1 || dat > hmday[mon] || dat < 1) ? "Wrong\n":"Yes!!\n");

	}

	return 0;

}
