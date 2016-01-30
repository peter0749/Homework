#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
using namespace std;

class BankAccount
{
private:
	string CustomName;
	long Account;
	double balance;
public:
	BankAccount(string Customname="Null",long account=-1,double balance=0.0);
	void Generate_Account(string, string, int);
	void Deposit(double);
	virtual int Withdraw(string, string, int);
	void DisplayAccount(string, string);
};
class CheckAccount: public BankAccount
{
private:
	int UpperBound;
	double Interest_Rate;
	double TotalOverDraw;
	double TotalDebt;
public:
	CheckAccount(string Customname="Null",long account=-1,double balance=0.0, double TotalOverDraw, double TotalDebt);
	void Modify_UpperBound(string, string);
	void Modify_interestRate(string, string);
	int WithDraw(string, string, int);
};

int main(void)
{

	return 1;
}