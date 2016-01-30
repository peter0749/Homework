#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class student
{
	public:
		int weight, height;

};

int main(void)
{
	student peter, david;
	peter.weight = 44;
	peter.height = 162;
	david.weight = 78;
	david.height = 161;

	cout << peter.weight << "\t" << peter.height << "\n";
	cout << david.weight << "\t" << david.height << "\n";
	return 0;
}
