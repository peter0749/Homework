#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int counter(int (*book)[10]);

int main(void)
{
	int i,k;
	int book[10];
	int ncase;
	scanf("%d",&ncase);
	while(ncase--)
	{
		memset(book,0x00,sizeof(int)*10);
		for(i=0;i<6;i++)
		{
			scanf("%d",&k);
			book[k]++;
		}
		printf("%d",counter(&book));
	}

	return 0;
}

int counter(int (*book)[10])
{
	int cpy[10];
	int i,k,j,temp, ans=0, ok = 1;
	for(i=0;i<1000000;i++)
	{
		for(j=0;j<10;j++)
			cpy[j] = (*book)[j];
		temp = i;
		ok = 1;
		do
		{
			k = temp%10;
			if(cpy[k]<1)	{ok=0;break;}
			cpy[k]--;
			temp /= 10;
		}while(temp>0);
		if(ok==1)
			ans++;
	}
	return ans;

}
