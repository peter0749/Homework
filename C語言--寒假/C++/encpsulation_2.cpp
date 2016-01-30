#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class student
{
	private:
		int weight, height;
		int max(int foo, int bar)
		{
			return foo>bar?foo:bar;
		}

	public:
		void SET_HEIGHT(int h)
		{
			height = ( (h>=50 && h<=250) ? h:50);
		}
		void SET_WEIGHT(int w)
		{
			weight = ( (w>=4 && w<=150) ? w:4);
		}
		int GET_HEIGHT(void)
		{
			return height;
		}
		int GET_WEIGHT(void)
		{
			return weight;
		}
		int GET_MAX(int pik, int boo)
		{
			return max(pik,boo);
		}
};//END OF CLASS STATEMENT

int main(void)
{
	student peter;
	peter.SET_HEIGHT(20000);
	peter.SET_WEIGHT(30000);
	cout << peter.GET_WEIGHT() << "\t" << peter.GET_HEIGHT() << "\t" << peter.GET_MAX(100,200) << "\n";
	return 0;
}
