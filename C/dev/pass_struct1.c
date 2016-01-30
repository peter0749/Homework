#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct grade
{
	char course[10];
	int score;
}peter={"ICS",85}, john={"Math",80};

void swap(struct grade, struct grade);

int main(void)
{
	printf("Call by value:\n\n");
	printf("\n\nIn main() before calling:\n");
	printf("peter.course=%s\tpeter.score=%d\n",peter.course,peter.score);
	printf("john.course=%s\tjohn.score=%d\n",john.course,john.score);
	
	swap(peter,john);
	
	printf("\n\nIn main() after calling:\n");
	printf("peter.course=%s\tpeter.score=%d\n",peter.course,peter.score);
	printf("john.course=%s\tjohn.score=%d\n",john.course,john.score);
	
	system("pause");
	return 0;
} 

void swap(struct grade x1, struct grade x2)
{
	struct grade temp;
	
	printf("\n\nIn swap() before swapping:\n");
	printf("peter.course=%s\tpeter.score=%d\n",x1.course,x1.score);
	printf("john.course=%s\tjohn.score=%d\n",x2.course,x2.score);
	
	temp=x1;
	x1=x2;
	x2=temp;
	
	printf("\n\nIn swap() after swapping:\n");
	printf("peter.course=%s\tpeter.score=%d\n",x1.course,x1.score);
	printf("john.course=%s \tjohn.score=%d\n",x2.course,x2.score);
	
}
