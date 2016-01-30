#include <stdio.h> 
#include <stdlib.h>
int main()
{
	int age ;
	printf("==Ticket purchasing==\n");
	printf("Please enter your age here: ");
	scanf("%d", &age);
	printf("The ticket you purchase is: %s", 
			age>=60 ? "Priority":(0<=age && age<=12 ? "Child" : "Adult"));
			return 0;
}
