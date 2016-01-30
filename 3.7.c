#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int w;
	int l;
	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	l = (a > c ? a-c:c-a);
	w = (b > d ? b-d:d-b);
	printf("%d\n%d\n",l*w,2*(l+w));

	return 0;
}
