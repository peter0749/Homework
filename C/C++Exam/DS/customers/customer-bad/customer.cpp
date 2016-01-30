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
//	void Stack::pop();
	const Customers * Stack::pop();
	const Customers * Stack::Top();
	int Stack::top();
};
Stack::Stack()
{ PtrStack=0; };     //clear the Stack Pointer
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
const Customers * Stack::pop()
{
	Customers pC;
	int len=strlen(CustomerArray[PtrStack-1].fullname);
	pC.fullname=new char[len+1];
//	name = new char[len+1];
	strcpy(pC.fullname, CustomerArray[PtrStack-1].fullname);
//	strcpy(name, CustomerArray[PtrStack-1].fullname);
	pC.payment = CustomerArray[PtrStack-1].payment;
//	(*pay) = CustomerArray[PtrStack-1].payment;
	PtrStack--;
	return &pC;
	
};
//void Stack::pop()
//{
//	PtrStack--;
//};
const Customers * Stack::Top()
{
	Customers pC;
		int len=strlen(CustomerArray[PtrStack-1].fullname);
	pC.fullname=new char[len+1];

	
	//int len=strlen(name)
	//CustomerArray[PtrStack].fullname=new char[len+1];
//	strncpy(CustomerArray[PtrStack].fullname, name, sizeof(name)+2);
	strcpy(pC.fullname, CustomerArray[PtrStack-1].fullname);
	pC.payment = CustomerArray[PtrStack-1].payment;
	return &pC;
	
	
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
	char temp[100];
	string fullname;
	string payment;
	int startPush=0;
	int startPop=0;
	int name_on=0;
	int payment_on=0;
	const char * PushCmd="A\r";
	const char * PopCmd="P\r";
	const char * QuitCmd="Q\r";
	const char * Quit1Cmd="q\r";
	while(!fin.eof()){
	  fin.getline((char *)&temp,sizeof(&temp));
	  int k=0;

	//  start=0;
	  
  	  int retPush = strcmp(temp,PushCmd);
	  if(retPush==0) {startPush=1; continue;}
	  int retPop = strcmp(temp,PopCmd);
	  if(retPop==0) 
	  {
          
		 // startPop=1; 
		  if(stack.isempty()==false)
		  {
			  int pa;
			  //char * na;
			 // Customers* cC;
			  pa=stack.pop()->payment;
			  int len=strlen(stack.pop()->fullname);
			  char * na=new char[len+1];
			  strcpy(na, stack.pop()->fullname);

			  
			 
/*
			  int  pa;
		      char * na;
			  stack.pop(na, &pa);
			  cout<<na;
			  cout<<pa;
       
			//  amount += stack.Top()->payment;
			amount += stack.pop()->payment;  
		  cout << command << PopCmd << endl;
		  cout << stack.pop()->fullname << commandC << amount <<endl;
		  fout1 << command << PopCmd << "\r\n";
		  fout1 << stack.pop()->fullname << commandC << amount << "\r\n";
		 // cout << "Enter customer name: "<<stack.Top()->fullname << endl;
		 // cout << "Enter customer payment: "<<stack.Top()->payment <<endl;
		 // stack.pop();
*/
		  } else
		  { cout << commandD << endl;
		  }

		 // startPop=0;
		  continue;

	  }
      int retQuit = strcmp(temp,QuitCmd);
	  int ret1Quit = strcmp(temp,Quit1Cmd);
	  if((retQuit==0) || (ret1Quit==0))
	  {
		  cout << command << commandE << endl;
		  fout1 << command << commandE << "\r\n";
	    	fin.close();
        	fout1.close();
            return 1;

		  startPush=1; 
	  continue;
	  }


	  while(temp[k] != '\0')
	  { // temp[k] != '\0'
	//	  if((temp[k] == 'A') && (temp[k+1] == '\r'))
	//	  { start=1;	  cout << "Push " << endl;  }
		  if((temp[k]>='a')&&(temp[k]<='z')||(temp[k]>='A')&&(temp[k]<='Z'))
		  {fullname+=temp[k]; name_on=1;}
		  if((temp[k]>='0')&&(temp[k]<='9'))
		  {payment+=temp[k]; payment_on=1;}
		  k++;
	  } // temp[k] != '\0'
	  if((startPush==1)&&(name_on==1)&&(payment_on==1))
	  {   char * errmsg;
		  int pay =(int) strtod(payment.c_str(),&errmsg);
		  stack.push(fullname.c_str(),pay);
		  cout << command << PushCmd << endl;
		  cout << "Enter customer name: "<<stack.Top()->fullname << endl;
		  cout << "Enter customer payment: "<<stack.Top()->payment <<endl;
          		  
		  fout1 << command << PushCmd << "\r\n"; 
		  fout1 << commandA << stack.Top()->fullname << "\r\n";
		  fout1 << commandB << stack.Top()->payment << "\r\n";   			 
		  startPush=name_on=payment_on=0;
	
		  fullname.erase();
		  payment.erase();
	  }
/*
	  if(startPop==1)
	  {
		  cout << command << PopCmd << endl;
		  cout << stack.Top()->fullname << commandC << stack.Top()->payment <<endl;;
		 // cout << "Enter customer name: "<<stack.Top()->fullname << endl;
		 // cout << "Enter customer payment: "<<stack.Top()->payment <<endl;
		  stack.pop();
		  startPop=0;
	  }
*/
//	  if(isalpha())

	} //EOF of fin



    system("pause");
	fin.close();
	fout1.close();
    return 1;

}