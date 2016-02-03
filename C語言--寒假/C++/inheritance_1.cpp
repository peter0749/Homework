#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class student
{
	public:
		inline int getmax(int,int);
};

inline int student::getmax(int a, int b)
{
	return ( a>b ? a:b );
}

class studentson:public student
{
	public:
		void getf(int);
};

void studentson::getf(int n)
{
	int i;
	int f0 = 0, f1 = 1, f2;
	for(i=0;i<n;i++)
	{
		f2 = f0 + f1;
		cout << f2 << " ";
		f0 = f1;
		f1 = f2;
	}
	cout << "\n";
}

int main(void)
{
	studentson jackson;
	cout << jackson.getmax(10,20) << "\n";
	jackson.getf(20);
	return 0;
}
