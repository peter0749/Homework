#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(void)
{
	string id, pwd;
	cout << "Account Name: ";
	cin >> id;
	cout << "Password: ";
	cin >> pwd;
	if(id=="peter0749" && pwd=="abc")
		cout << "Currect!\n";
	else
		cout << "False!\n";

	return 0;
}
