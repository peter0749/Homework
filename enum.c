#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int counter(int (*book)[10]);

int main(void)
{
	int num;
	int i;
	int book[10] = {0};
	int ncase;
	scanf("%d",&ncase);
	while(ncase--)
	{
		memset(book,0x00,sizeof(int)*10);
		for(i=0;i<6;i++)
		{
			scanf("%d",&num);
			book[num]++;
		}
		printf("%d",counter(&book));
	}

	return 0;
}

int counter(int (*book)[10])
{
	int fail;
	int i,j,k,temp;
	int ans=0;
	int cpy[10];
	for(i=0;i<1000000;i++)
	{
		temp = i;
		for(j=0;j<10;j++)
			cpy[j] = (*book)[j];
		fail = 0;
		do
		{
			k = temp%10;
			if(cpy[k]<1) {fail = 1;break;}
			cpy[k]--;
			temp /= 10;
		}while(temp>0);
		if(fail == 0)
			ans++;
	}
	return ans;
}
