#include <stdio.h>

int main(void){
	struct bcc{
		char name[10];
		int hw;
		int mid;
		int final;
		float avg;
	};
	struct bcc david,*ptr;
	ptr=&david;
	printf("\n\t計算機概論成績試算\n\n");
	printf("\t1. 學生姓名:\t");
	gets(ptr->name);
	printf("\n\t2. 平時考:\t");
	scanf("%d",&(ptr->hw));
	printf("\n\t3. 期中:\t");
	scanf("%d",&(ptr->mid));
	printf("\n\t4. 期末:\t");
	scanf("%d",&(ptr->final));
	ptr->avg=ptr->hw*0.3+ptr->mid*0.3+ptr->final*0.4;
	printf("\n========================================\n");
	printf("\t5. AVG:\t%6.2f\n",ptr->avg);
	system("pause");
	return 0;
} 
