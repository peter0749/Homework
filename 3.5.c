#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int _50, _10, _5;
	_50=_10=_5=0;
	int input=0;
	scanf("%d",&input);
	while(input >= 50)
	{
		_50++;
		input-=50;
	}
	while(input >= 10)
	{
		_10++;
		input-=10;
	}
	while(input >= 5)
	{
		_5++;
		input-=5;
	}
	printf("%d\n%d\n%d\n%d\n",_50,_10,_5,input);

	return 0;
}
