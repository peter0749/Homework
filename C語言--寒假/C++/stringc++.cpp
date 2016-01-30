#include <iostream>
#include <iomanip>
#include <string>
#define ENDLL "\n"

using namespace std;

int main(void)
{
	string str = "Hello World!";
	int s, e;
	cout << str << ENDLL;
	cout << str.length() << ENDLL;
	cout << "Position to del: ";
	cin >> s;
	cout << "How many? ";
	cin >> e;
	str.erase(s,e);
	cout << str << ENDLL;
	string input;
	cout << "String to insert: ";
	cin >> input;
	str.insert(0,input,0,input.length());
	cout << str << ENDLL;

	return 0;
}
