#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#define MEDL "\n"

using namespace std;

inline int getmin(int , int );
inline double getmin(double, double);
inline char getmin(char, char);

int main(void)
{
	cout << "Compare between a and z: " << getmin('a','z') << MEDL;
	cout << "Compare between 3.14 and 1.75 : " << getmin(3.14,1.75) << MEDL;
	cout << "Compare between 3 and 5 : " << getmin(5,3) << MEDL;

	return 0;
}

inline int getmin(int a, int b)
{
	return a<b?a:b;
}

inline double getmin(double a, double b)
{
	return a<b?a:b;
}

inline char getmin(char a, char b)
{
	return a<b?a:b;
}
