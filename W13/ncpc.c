#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

void count(int a[], int b[]);

int main(void)
{
	int i;
	int term;
	char temp[MAX];
	int ba[10]={0};
	int bb[10]={0};
	char *p=NULL;
	fgets(temp,MAX,stdin);
	term = atoi(temp);
	while(term--)
	{
		for(i=0;i<10;i++)
		{
			ba[i]=bb[i]=0;
		}
		fgets(temp,MAX,stdin);
		p = strtok(temp," ");
		while(p!=NULL)
		{
			ba[atoi(p)]++;
			p = strtok(NULL," ");
		}
		fgets(temp,MAX,stdin);
		p = strtok(temp," ");
		while(p!=NULL)
		{
			bb[atoi(p)]++;
			p = strtok(NULL," ");
		}
		count(ba,bb);
	}

	return 0;
}

void count(int a[], int b[])
{
	int num = 1000000;
	int counta=0, countb=0;
	int bka[10];
	int bkb[10];
	int t;
	int flaga,flagb;
	int i;
	while(num--)
	{
		t = num;
		flaga = 1;
		flagb = 1;
		for(i=0;i<10;i++)
		{
			bka[i] = a[i];
			bkb[i] = b[i];
		}
		do{
			bka[t%10]--;
			bkb[t%10]--;
			if(bkb[t%10]<0)
			{
				flagb = 0;
			}
			if(bka[t%10]<0)
			{
				flaga = 0;
			}
			
			t/=10;
		}while(t!=0);
		if(flaga==0 && flagb==1)
			countb++;
		if(flaga==1 && flagb==0)
			counta++;
	}
	printf("%d %d\n",counta,countb);
}
