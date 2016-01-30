// VirtualFunction.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
//#include "stdafx.h"
using namespace std;


//Base Abstract Class: cannot be instancelized
class Customers
{
public:
	string name;
	string phone;
	int salary;
	static int num_of_customers;
	virtual void add_benefic(int) = 0; //pure virtual function
	Customers();
//	void show_data();
	static void show_customer_num()
	{
		cout << "The num of customer objects " << num_of_customers << endl;
	}
	
	
};

Customers::Customers()
{
	num_of_customers++;
}

class CustomersMarket:public Customers
{
public:
	string company;
	CustomersMarket();
	void show_data(); //¦h§Î POLYMORPHIC
	void add_benefic(int);
};
CustomersMarket::CustomersMarket()
{
}
void CustomersMarket::add_benefic(int x)
{
	if(x<5000)
		salary+=5000;
	else 
		salary+=x;
}
void CustomersMarket::show_data()
{
	cout << "class CustomersMarket: Name is : " << name << endl;
	cout << "class CustomersMarket: phone is : " << phone << endl;
    cout << "class CustomersMarket: salary is : " << salary << endl;
	cout << "class CustomersMarket: company is : " << company << endl;
}

class CustomersBank: public Customers
{
public:
	string location;
	CustomersBank();
	void show_data();
	void add_benefic(int);

};
CustomersBank::CustomersBank()
{
}
void CustomersBank::add_benefic(int x)
{
	if(x<2500)
		salary+=2500;
	else
		salary+=x;
}

void CustomersBank::show_data()
{
	cout << "class CustomersBank: Name is : " << name << endl;
	cout << "class CustomersBank: phone is : " << phone << endl;
    cout << "class CustomersBank: salary is : " << salary << endl;
	cout << "class CustomersBank: location is : " << location << endl;


}	
//Customers::show_customer_num()
//{
//	cout << "The num of customer objects " << num_of_customers;
//}

int Customers::num_of_customers=0;


int main(int argc, char* argv[])
{
	printf("Hello World!\n");
	Customers *ptr;
	CustomersMarket CustomerA;
	CustomersBank CustomerB;
	CustomerA.name = " Sony Ltd. ";
	CustomerA.company = "SONY ";
	CustomerA.phone = "03-123456" ;
	CustomerA.salary = 50000;
	CustomerA.show_data();
	cout << "After Adding Salary " << endl;
	CustomerA.add_benefic(4000);
	CustomerA.show_data();

	CustomerB.name = " Taiwan ";
	CustomerB.phone = "02-1233333";
	CustomerB.salary = 60000;
	CustomerB.location = "Taipei";
	CustomerB.show_data();
	CustomerB.add_benefic(10000);
	CustomerB.show_data();
	Customers::show_customer_num();
	cout << "**********************" << endl;
	ptr = &CustomerA;
	ptr->add_benefic(1000);
	CustomerA.show_data();
	
	system("pause");


	return 0;
}