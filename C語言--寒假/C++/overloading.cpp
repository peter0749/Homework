#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#define MAX 100

using namespace std;

double getmin(double, double);
double getmin( const double[], int );

int main(void)
{
	double data[MAX];
	int i = 0;

	while(scanf("%lf",&data[i])!=EOF)
	{
		i++;
	}
	cout << "Min in arr: " << getmin(data,i) << "\n";
	if(i>1)
		cout << "Min between arr0 arr1: " << getmin(data[0],data[1]) << "\n";

	return 0;
}

double getmin(double a, double b)
{
	return a<b?a:b;
}

double getmin( const double arr[], int n)
{
	int i;
	double min = arr[0];
	for(i=0;i<n;i++)
	{
		if(arr[i]<min) min = arr[i];
	}
	return min;
}
