#include <stdio.h>
#include <stdlib.h>

int main(void){
	struct date{
		int year;
		int month;
		int day;
	};
	
	struct ename{
		char last[10];
		char first[10];
	};
	
	struct person{
		char id[11];
		char cname[10];
		struct date birth;
		char blood[2];
		char married;
		struct ename name;
	};
	
	struct person p1={"H124277261","¥ú¦t",{1996,10,03},"O",'N',{"Jeng","Kuang Yu"}
	};
	
	printf("1.\tp1.id\t%s\n",p1.id);
	printf("2.\tp1.cname\t%s\n",p1.cname);
	printf("3.\tYear\t%d\n",p1.birth.year);
	printf("4.\tMonth\t%d\n",p1.birth.month);
	printf("5.\tType\t%s\n",p1.blood);
	printf("6.\tmarried\t%c\n",p1.married);
	printf("7.\tname\t%s %s\n",p1.name.first,p1.name.last);
	system("pause");
	return 0;
}
