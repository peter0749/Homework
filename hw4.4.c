#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int leng;
	int x1,y1, x2,y2;
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

	leng = (x1 > x2 ? x1-x2 : x2-x1) + (y1 > y2 ? y1-y2 : y2-y1);
	leng*=2;

	printf("%d\n",leng);

	return 0;
}
