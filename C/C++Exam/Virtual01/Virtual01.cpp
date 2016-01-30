#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
using namespace std;

class Members
{
private:
	string name;
	string ID_no;
public:
	Members();
	Members(string, string);
	virtual void print_data() const;
//    virtual void ViewAcct() const;
};

Members::Members()
{
	name=""; ID_no="";
}
Members::Members(string name, string ID_no)
{
	this->name = name;
	this->ID_no = ID_no;
}

void Members::print_data() const
{
	cout << "**** Basic Member data ****" << endl;
	cout << "ID no : " << this->ID_no << endl;
	cout << "Name : " << this->name << endl;
}


class Staff_Member: public Members
{
private:
	int salary;
//	Staff_Member(string, string, int):Members(string, string);
public:
	Staff_Member();
	Staff_Member(string, string, int);
	virtual void print_data() const;
};

Staff_Member::Staff_Member()
{
	Members::Members();
	salary = 0;
  }

Staff_Member::Staff_Member(string name, string ID_no, int salary):Members(name, ID_no)
{
	Members::Members(name, ID_no);
	this->salary = salary;
}

void Staff_Member::print_data() const
{
	Members::print_data();
	cout << "**** Staff data ****" << endl;

	cout << this->salary << endl;
}

int main(void)
{
	Staff_Member john("John", "A1111", 45000);
	john.print_data();

	return 1;
}