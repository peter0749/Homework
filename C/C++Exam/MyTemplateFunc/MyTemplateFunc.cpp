#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
using namespace std;
template<class T1, class T2>
void Printary(T1 * ary, T2 size);

template<class T1, class T2>
void sortary(T1 * ary, T2 size);

int main(void)
{
	cout << "*** Bubble Sort ***" << endl;
	int idata[]={40,23,45,2,44};
	cout << "Before : ";
	Printary(idata, 5);
	sortary(idata, 5);
	cout << "After  : ";
	Printary(idata, 5);
	cout << endl;
	
	double fdata[]={2.3, 3.4, 1.2, 0.3, 9.2};
    cout << "Before : ";
	Printary(fdata, 5);
	sortary(fdata, 5);
	cout << "After  : ";
	Printary(fdata, 5);
	cout << endl;
	return 1;
}

template<class T1, class T2>
void Printary(T1 * ary, T2 size)
{
	T2 i;
	for(i=0; i<size; i++)
		cout << ary[i] << "  ";
	cout << endl;
}

template<class T1, class T2>
void sortary(T1 * ary, T2 size)
{
	T2 i,j;
	T1 t;
	for(i=size-2; i>=0; i--)
		for(j=0;j<=i;j++)
			if(ary[j]>ary[j+1])
			{
				t = ary[j];
				ary[j] = ary[j+1];
				ary[j+1] = t;
			}
}