#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class student
{
	public:
		int height, weight;
		int getmax(int a, int b)
		{
			return a>b?a:b;
		}
};

int main(void)
{
	student peter;
	peter.weight = 45;
	peter.height = 162;

	cout << peter.weight << "\t" << peter.height << "\t" << peter.getmax(10,20) << endl;
	return 0;
}
