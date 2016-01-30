#include <stdio.h>
int main()
{
	int year,month,day,day1,day2,sum=0,test;
	int cp_year;
	scanf("%d",&test);
	while(test!=0)
	{
		test--;
		scanf("%d/%d/%d",&year,&month,&day);
		cp_year = year;
		if(year<1970||month>12||day>31||(month==2&&((day==30)||(day==31)))||(month==4&&day==31)||(month==6&&day==31)||(month==9&&day==31)||(month==11&&day==31))
		{
			if(test>0)
			{
				printf("0\n");
			}
			else
			{
				printf("0");
			}
		}
		else
		{
			if(((year%400!=0)&&(year%4!=0||year%100==0))&&(month==2&&day==29))
			{
				if(test>0)
				{
					printf("0\n");
				}
				else
				{
					printf("0");
				}
			}
			else
			{



				while(year>1970)
				{
					year--;
					if((year%400==0)||(year%4==0&&year%100!=0))
					{
						day1=366;
					}
					else
					{
						day1=365;
					}

					sum+=day1;
				}



				while(month>1)
				{
					month--;
					if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
					{
						day2=31;
					}
					else if(month==4||month==6||month==9||month==11)
					{
						day2=30;
					}
					else
					{
						printf("Entering month == 2...\n");
						if(cp_year % 400 == 0 || cp_year % 100 !=0 && cp_year % 4 ==0)
						{
							day2=29;
							printf("Entering day2 == 29\n");
						}
						else
							day2=28;
					}
					sum+=day2;
				}
				sum+=day;
				if(test>0)
				{
					printf("%d\n",sum);
				}
				else
				{
					printf("%d",sum);
				}
				sum=0;
			}


		}
	}
	return 0;

}



