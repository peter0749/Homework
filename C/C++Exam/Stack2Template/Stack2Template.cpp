#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <cctype>
using namespace std;
#define MAXSIZE 100
template <class T>
class Stack2Template
{
	private:
		T items[MAXSIZE];
		int top;
	public:
		Stack2Template();
		bool is_empty();
		bool is_full();
		virtual bool push(const T & myitem);
		virtual bool pop(T & myitem);
};

template <class T>
Stack2Template<T>::Stack2Template()
{
	top=0;
}

template <class T>
bool Stack2Template<T>::is_empty()
{
	return top==0;
}

template <class T>
bool Stack2Template<T>::is_full()
{
	return top==MAXSIZE;
}

template <class T>
bool Stack2Template<T>::push(const T & myitem)
{
	if(top==MAXSIZE) return false;
	else
	{
		items[top++] = myitem;
		return true;
	}
}

template <class T>
bool Stack2Template<T>::pop(T & myitem)
{
	if(top==0) return false;
	else
	{
		myitem = items[--top];
		return true;
	}
}

typedef struct
{
	char* name;
	int weight;
} StackStruct;

class StructStack: public Stack2Template <StackStruct>
{
private:
	static int num_of_ss;
//	StackStruct stitems[MAXSIZE];
public:
	StructStack();
	virtual bool push(const StackStruct & myitem);
	virtual bool pop(StackStruct & myitem);
//	static int num_of_ss;
};
/*
StructStack::StructStack()
{
//	num_of_ss++;
}

bool StructStack <StackStruct>::push(const StackStruct & myitem)
{
	if(top==MAXSIZE) retuen false;
	else
	{
		

	}

}
*/

int StructStack::num_of_ss = 0;


int main(void)
{   int i;
	Stack2Template<string> stringstack;
	string mystr="ddd";
	stringstack.push(mystr);
	mystr.empty();
	mystr = "sss";
    stringstack.push(mystr);

	Stack2Template<int> intstack;
	for(i=0;i<=10; i++)  intstack.push(i);
	//	intstack.push((int)(rand()*10*i));
	int tmp_int;
	for(i=0; i<=3; i++)
	{
		intstack.pop(tmp_int);
		cout << "The int stack: " << tmp_int << endl; 
	}
	//	cout << "The int stack: " << intstack.pop() << endl;
	return 0;
}