#include <stdio.h>
#include <iostream>
#include <fstream>
#include <CString>
#include <fcntl.h>
#include <io.h>
/************************************************************************/
/* Class Employee
/************************************************************************/
class Employee 
{
public:
	char * _name;
	//string position;
	int _salary;

//e1<< _name                                                                                                                                                                                                                                                                                                                                    
/*
	Employee::Employee()
	{
		_name='\0';
	};
	*/
Employee& Employee::operator<<(const char * t) 
{
//	Employee y;
	int len=strlen(t);
	_name=new char[len+1];
	strcpy(_name,t);
	return *this;
};

Employee& Employee::operator <<(int g)
{
//	Employee y;
	_salary = g;
	return *this;

};

const char * Employee::name()
{
	return _name;
};
int Employee::salary()
{
	return _salary;
};

/*
bool Employee::empty()
{
	char * NULLSTR='\0';
	
	if(!strcmp(_name,NULLSTR)) return true;
	else return false;	
};
*/
};

/************************************************************************/
/* Class Manager:Employee
/************************************************************************/


class Manager:Employee
{
public:
	int  _allowance;
/*
	Manager::Manager()
	{
		
	};
	*/
Manager& Manager::operator<<(const char * t) 
{
	int len=strlen(t);
	_name=new char[len+1];
	strcpy(_name,t);
	return *this;
};
Manager& Manager::operator <<(int g)
{
	if(_salary<0)
		_salary = g;
	else
		_allowance = g;
	return *this;

};


int Manager::allowance()
{
	return _allowance;

};

int Manager::salary()
{
	return _salary;
};

const char * Manager::name()
{
	return _name;
};
/*
bool Manager::empty()
{
	
	if(_name) return false;
	else return true;	
};
*/

};
/*
int f(char *s)
{
	int i;
	for(i=1;*s;i++,s++);
	return i;
}
*/
/* 
int char_erase(char * &tmp)
{
	int len=strlen(tmp);
	for(int i=0;i<len;i++) tmp[i]='\0'; 
	return 1;
}
*/
/************************************************************************/
/* main()
/************************************************************************/


int main()
{
	using namespace std;
	int i=0;
	int idnum=0;
	
	string ifile="920201.s01";
	string ofile="920101.w01";
	string usrname;
	string money;
	string money1;
	Employee e1;
    Manager m1;
	ofstream fout(ofile.c_str(), ios::binary);
    ifstream fin( ifile.c_str(), ios::binary);
    char temp[100];
	while(!fin.eof()){
	  fin.getline((char *)&temp,sizeof(&temp));
	  int k=0;
	  int allow=0;
	  usrname.erase();
	  money.erase();
	  money1.erase();
	  int begin=0;
	  if(isalpha(temp[k])) idnum++;
	  while(temp[k] != '\0')
	  {
		  if((temp[k]>='a')&&(temp[k]<='z')||(temp[k]>='A')&&(temp[k]<='Z'))
		  {  

			 usrname+=temp[k];
			
		  }
		  if((temp[k]>='0')&&(temp[k]<='9'))
		  {
			  if(allow==0)
				  money+=temp[k];
			  else
				  money1+=temp[k];
		  }
		  
		  if((temp[k]==' ')&&(!money.empty())) 
				  allow=1;
		    

		  k++;
	  }
	  int len=usrname.length();
	  char ppp[20];
	  char * errmsg;
	  strncpy(ppp,usrname.c_str(),len);
      ppp[len] = '\0';	  

	  if(money1.empty())
	  {//Employee
		  e1<<ppp;
		  int salary =(int) strtod(money.c_str(),&errmsg);
		  e1<<salary;
	  }else
	  {//Manager
		  m1<<ppp;
		  int salary =(int) strtod(money.c_str(),&errmsg);
		  m1<<salary;
		  int allowance =(int) strtod(money1.c_str(),&errmsg);
		  m1<<allowance;
	  }
  
   }

	cout << e1._name << " salary = " << e1._salary << endl;
	cout << m1.name() << " SALARY = " << m1.salary() << endl; 
    cout << m1.name() << " Allowance = " << m1.allowance() << endl;
	fout << "Salary of " << e1._name << " = " << e1._salary << "\r\n";
    fout << "Salary of " << m1.name() << " = " << m1.salary() << "\r\n";
	fout << "Allowance of " << m1.name() << " = " << m1.allowance() << "\r\n";

    fin.close();
	fout.close();

	return 1;
}
