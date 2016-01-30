#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class StudentA
{
public:
	string name;
	int score;
	show_student();
};
StudentA::show_student()
{
	cout << "Name is " << name << endl;
	cout << "Score is " << score << endl;
}
class StudentB: public StudentA
{
	
public:
	bool sex;
	show_sex();
};
StudentB::show_sex()
{
	if(sex)
		cout << "Male !! " << endl;
	else
		cout << "Female !!" << endl;
}

int main(void)
{
	StudentB John;
	John.name = "David";
	John.score = 93;
	John.sex = 1;
	John.show_student();
	John.show_sex();
	system("pause");
	return 1;
}