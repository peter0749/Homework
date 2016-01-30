#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1002

int dis(int,int,int,int);
void del(int d,int n, int data[2][MAX]);
int go_find(int n,int px, int py, int tresure[2][MAX]);

int main(void)
{
    //freopen("nearest_test.in","r",stdin);
    //freopen("testout.txt","w+",stdout);
	int tresure[2][MAX] = {{0}};
	int cp[2][MAX] = {{0}};
	int px, py, poi;
	/*[0] for x, [1] for y;*/
	int term, n, i;
	int tn, sum;
	scanf("%d",&term);
	while(term--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d %d",&tresure[0][i], &tresure[1][i]);
		#if 0
		for(i=0;i<n;i++)	//printout for test
			printf("%d %d\n",tresure[0][i],tresure[1][i]);
		#endif
		for(i=0;i<n;i++)	/*Backup the data*/
		{
			cp[0][i] = tresure[0][i];
			cp[1][i] = tresure[1][i];
		}
		//scanf("%d %d",&px,&py);
		px = 0;
		py = 0;
		tn = n+1;
		sum = 0;
		while(tn--)
		{
			poi = go_find(tn,px,py,cp);
			sum += dis(px,py,cp[0][poi],cp[1][poi]);
			px = cp[0][poi];
			py = cp[1][poi];
			del(poi,tn,cp);
		}
		printf("%d\n",sum);

	}

	return 0;
}

int dis(int px, int py, int tx, int ty)
{
	return abs(px-tx) + abs(py-ty);
}

int go_find(int n,int px, int py, int cp[2][MAX])
{
	int i, min;
	min = 0;
	for(i=0;i<n;i++)
	{
		if(dis(px,py,cp[0][i],cp[1][i]) < dis(px,py,cp[0][min],cp[1][min]))
			min = i;
	}
	return min;
}

void del(int d,int n, int data[2][MAX])
{
	int i;
	for(i=d;i<n-1;i++)
	{
		data[0][i] = data[0][i+1];
		data[1][i] = data[1][i+1];
	}
}
