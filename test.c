int is_leap(int year)
{
	return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0) ? 1:0;
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

if(year < 1970 || mon > 12 || mon < 1 || dat > hm_days(year,mon) || dat < 1)
{
	printf("0\n");
	continue;
}
