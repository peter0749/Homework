#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10000

double f(int p, double x, double c[]);
double cmp(int p, double low, double hi, double c[]);

int main(void)
{
	//freopen("b_search.txt","w+",stdout);
	double tx;
	double ftx,fa,fb;
	double a, b, c[MAX];
	int term, p, i;
	scanf("%d",&term);
	while(term--)
	{
		scanf("%d",&p);
		for(i=p; i>=0; i--)
		{
			scanf("%lf",&c[i]);
		}
		scanf("%lf %lf",&a,&b);
		printf("%.5lf\n",cmp(p,a,b,c));

	}

	return 0;
}


double f(int p, double x, double c[])
{
	int i;
	double sum = 0;
	for(i=1; i<=p; i++)
	{
		sum += c[i]*pow(x,i);
	}
	sum += c[0];
	return sum;
}

double cmp(int p, double low, double hi, double c[])
{
    double mid;
    mid = (low+hi)/2;
    if(hi-low<0.0000001)
        return mid;
    else
    {
        if(f(p,low,c)*f(p,mid,c)<0)
            return cmp(p,low,mid,c);
        else
            return cmp(p,mid,hi,c);
    }
}
