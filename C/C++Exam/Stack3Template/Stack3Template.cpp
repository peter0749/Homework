#include <stdio.h>
#include <CString>
#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <io.h>
#include <iomanip>
#include <cctype>

#include <conio.h>
#include <string>
#include <stdlib.h>

typedef struct 
{
	char * fullname;
	int payment;
} Customer;

#define MAXSIZE 100

using namespace std;

template <class T>
class CustomerStack
{
	private:
//		T cStack[MAXSIZE];
		struct Node
		{
			T node_data;
			Node* link;
		};
		int top;
		const int stacksize;
	public:
		CustomerStack();
		CustomerStack(int s_size);
//		CustomerStack(const T &myStack);
		bool is_full();
		bool is_empty();
		bool push(const T &myStack);
		bool pop(T &myStack);

};

template <class T>
CustomerStack<T>::CustomerStack()
{
	top=0;
}

template <class T>
CustomerStack<T>::CustomerStack(int s_size):stacksize(s_size)
{
	top=0;
}

template <class T>
bool CustomerStack<T>::is_full()
{
//	return top==MAXSIZE;
	return top==stacksize;
}

template <class T>
bool CustomerStack<T>::is_empty()
{
	return top==0;
}
template <class T>
bool CustomerStack<T>::push(const T &myStack)
{
	if(is_full()) return false;
	Node.node_data.payment = mystack.payment;
	int length=strlen(mystack.fullname);
	Node.node_data.fullname=new char[length+1];
	strcpy(Node.node_data.fullname, mystack.fullname);


	return true;
}
/*
template <class T>
class StructStack: public CustomerStack<Customer>
{
	private:
		static int num_of_struct;
	public:
		StructStack();
		StructStack(int s_size);
		virtual bool push(const T &sStack);
		virtual bool pop(T &sStack);
		
};

template <class T>
StructStack<T>::StructStack()
{
	num_of_struct++;
}

template <class T>
StructStack<T>::StructStack(int s_size):CustomerStack<Customer>::stacksize(s_size)
{
	num_of_struct++;
}


template <class T>
int StructStack<T>::num_of_struct=0;
*/
int main(void)
{
	CustomerStack<Customer> BankCustomer(6);
	system("pause");
	return(1);
}