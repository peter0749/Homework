#include <stdio.h>
#include <iostream>
#include <fstream>
#include <CString>
#include <fcntl.h>
#include <io.h>
#define MAXSIZE 20
typedef struct customer
{
	char * fullname;
	int payment;
}Customers ;

class Stack
{
public:
	Customers CustomerArray[MAXSIZE];
	int PtrStack;
public:
	Stack::Stack();
	bool Stack::isempty();
	bool Stack::isfull();
	void Stack::push(const char * name, int pay);
	void Stack::pop();
	Customers Stack::Top();
	int Stack::top();
};
Stack::Stack()
{ 
	PtrStack=0; 
	CustomerArray[PtrStack].payment=0;
	CustomerArray[PtrStack].fullname='\0';

};     //clear the Stack Pointer
bool Stack::isempty()
{
	if(this->top()==0)	return true;
	else return false;
};
bool Stack::isfull()
{
	if(this->top()==MAXSIZE)  return true;
	else return false;
};
void Stack::push(const char * name, int pay)
{
	int len=strlen(name);
	CustomerArray[PtrStack].fullname=new char[len+1];
//	strncpy(CustomerArray[PtrStack].fullname, name, sizeof(name)+2);
	strcpy(CustomerArray[PtrStack].fullname, name);
	CustomerArray[PtrStack].payment = pay;
	PtrStack++;
};
void Stack::pop()
{
	PtrStack--;
};

Customers Stack::Top()
{
	Customers pC;
		int len=strlen(CustomerArray[PtrStack-1].fullname);
	pC.fullname=new char[len+1];
	
	strcpy(pC.fullname, CustomerArray[PtrStack-1].fullname);
	pC.payment = CustomerArray[PtrStack-1].payment;
	return pC;
	
	
};
int Stack::top()
{ return PtrStack;
};

int main()
{
	using namespace std;
	string ifile="920202.s01";
	string ofile1="920202.w01";
	string ofile2="920202.w02";
	int amount=0;
	char * command = "Enter A to add a customer,P to sum up payments,and Q to quit:";
	char * commandA = "Enter customer name: ";
	char * commandB = "Enter customer payment: ";
	char * commandC = " processed. Payments now total $";
	char * commandD = " stack already empty";
	char * commandE = " Done!";
    ifstream fin( ifile.c_str(), ios::binary);
	ofstream fout1(ofile1.c_str(), ios::binary);
	Stack stack;
	char ch;
	string fullname;
	string payment;
	int startPush=0;
	int startPop=0;
	int name_on=0;
	int payment_on=0;
	const char * PushCmd="A";
	const char * PopCmd="P";
	const char * QuitCmd="Q";
	const char * Quit1Cmd="q";
	while(fin.get(ch)){
	  int k=0;

	//  start=0;
      if( (ch==(*PushCmd))&&(fin.peek()=='\r') ) 
	  { 
		  startPush=1; 
		  continue;
	  }
	  if( (ch==(*PopCmd))&&(fin.peek()=='\r') ) 
	  { 
		  // startPop=1; 
		  if(stack.isempty()==false)
		  {
			  amount += stack.Top().payment;
          
		  cout << command << PopCmd << endl;
		  cout << stack.Top().fullname << commandC << amount <<endl;
		  fout1 << command << PopCmd << "\r\n";
		  fout1 << stack.Top().fullname << commandC << amount << "\r\n";
		  cout << "Enter customer name: "<<stack.Top().fullname << endl;
		  cout << "Enter customer payment: "<<stack.Top().payment <<endl;
		  stack.pop();
		  } else
		  { cout << commandD << endl;
		  }

		 // startPop=0;
		  continue;
	  }

	  if( ((ch==(*QuitCmd))||(ch==(*Quit1Cmd)))&&(fin.peek()=='\r') ) 
	  { 
		  cout << command << commandE << endl;
		  fout1 << command << commandE << "\r\n";
		  fin.close();
		  fout1.close();
		  return 1;

		  startPush=1; 
		  continue;
	  }
 //     if( isalpha(ch) && (fin.peek()=='\r') )
	  if( isalpha(ch)  )
	  { 
		  fullname += ch;
		  if(fin.peek()=='\r')
		     name_on=1;
	  }
	  if( isdigit(ch) )
	  {
		  payment+=ch; 
		  if(fin.peek()=='\r')
			  payment_on=1;
	  }
	  if((startPush==1)&&(name_on==1)&&(payment_on==1))
	  {   char * errmsg;
		  int pay =(int) strtod(payment.c_str(),&errmsg);
		  stack.push(fullname.c_str(),pay);
		  cout << command << PushCmd << endl;
		  cout << "Enter customer name: "<<stack.Top().fullname << endl;
		  cout << "Enter customer payment: "<<stack.Top().payment <<endl;
          		  
		  fout1 << command << PushCmd << "\r\n"; 
		  fout1 << commandA << stack.Top().fullname << "\r\n";
		  fout1 << commandB << stack.Top().payment << "\r\n";   			 
		  startPush=name_on=payment_on=0;
	
		  fullname.erase();
		  payment.erase();
	  }



	} //EOF of fin



    system("pause");
	fin.close();
	fout1.close();
    return 1;

}