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
	printf("\n\t�p������צ��Z�պ�\n\n");
	printf("\t1. �ǥͩm�W:\t");
	gets(ptr->name);
	printf("\n\t2. ���ɦ�:\t");
	scanf("%d",&(ptr->hw));
	printf("\n\t3. ����:\t");
	scanf("%d",&(ptr->mid));
	printf("\n\t4. ����:\t");
	scanf("%d",&(ptr->final));
	ptr->avg=ptr->hw*0.3+ptr->mid*0.3+ptr->final*0.4;
	printf("\n========================================\n");
	printf("\t5. AVG:\t%6.2f\n",ptr->avg);
	system("pause");
	return 0;
} 
