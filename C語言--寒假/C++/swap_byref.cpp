#include <iostream>
#include <iomanip>
#include <string>
#define NENDL "\n"

using namespace std;

void swapbyref(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
	cout << "a: " << a << "\naddr of a: " << &a << NENDL;
	cout << "b: " << b << "\naddr of b: " << &b << NENDL;
}

void swapbyaddr(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
	cout << "*a: " << *a << "\na: " << a << "\n&a: " << &a << NENDL;
	cout << "*b: " << *b << "\nb: " << b << "\n&b: " << &b << NENDL;
}

int main(void)
{
	int i = 3;
	int j = 5;
	swapbyaddr(&i,&j);
	swapbyref(i,j);
	return 0;
}
