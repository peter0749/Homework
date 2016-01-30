#include<iostream>
#include<iomanip>
#include<string>
#include <cctype>
#include<conio.h>
using namespace std;
#define MAXSIZE 100

#ifndef STACKTP_H_
#define STACKTP_H_

template <class T>
class StackTemplate
{
	private:
		T item[MAXSIZE];
		string name;
		int top;
//		static int Num_of_stack;
	public:
		StackTemplate();
//		StackTemplate(T * myitem, string Sname, int stop);
//		void Show_num_of_Stack() const
//		{ cout << "**** Num of Stack ****" << Num_of_stack << endl; }
		bool StackFull();
		bool StackEmpty();
		bool push(const T & myitem);
		bool pop(T & myitem);
};

template <class T>
StackTemplate<T>::StackTemplate()
{
//	Num_of_stack++;
	top = 0;
}
/*
template <class T>
StackTemplate<T>::StackTemplate(T * Sitem, string Sname , int Stop)
{
	Num_of_stack++;
}
*/

template <class T>
bool StackTemplate<T>::StackFull()
{
	if(top==MAXSIZE) return true;
	else return false;
}

template <class T>
bool StackTemplate<T>::StackEmpty()
{
	if(top==0) return true;
	else  return false;
}
template <class T>
bool StackTemplate<T>::push(const T & myitem)
{
	if (top<MAXSIZE)
	{
		item[top++] = myitem;
		return true;
	}
	else
		return false;
}
template <class T>
bool StackTemplate<T>::pop(T & myitem)
{
	if (top > 0)
	{
		myitem = item[--top];
		return true;
	}
	else
		return false;
}
#endif

int main(void)
{
//	StackTemplate<int> intstack;
	StackTemplate<std::string> st;
//	string tempstr="first";
	char ch;
	std::string po;
	cout << "Please enter A to add a purchase order,\n"
         << "P to process a PO, or Q to quit.\n";
	while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;
		if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch(ch)
        {
            case 'A':
            case 'a': cout << "Enter a PO number to add: ";
                      cin >> po;
                      if (st.StackFull())
                          cout << "stack already full\n";
                      else
                          st.push(po);
                      break;
            case 'P':
            case 'p': if (st.StackEmpty())
                          cout << "stack already empty\n";
                      else {
                          st.pop(po);
                          cout << "PO #" << po << " popped\n";
                          break;
                      }
        }
        cout << "Please enter A to add a purchase order,\n"
             << "P to process a PO, or Q to quit.\n";
    }
 
	
	cout << "Bye\n";	
	
	return 1;
}