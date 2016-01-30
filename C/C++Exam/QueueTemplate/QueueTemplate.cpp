#include <stdio.h>
#include <CString>
#include <string>
#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <conio.h>

using namespace std;

#define MAXSIZE 100
template <class T>
class QueueTemplate
{
	private:
		T QueueArray[MAXSIZE];
		int front;
		int rear;
	public:
		QueueTemplate();
		bool isempty(){return front==rear==0}
		bool isfull(){return rear==MAXSIZE}
		bool Add_Queue(const T & myqueue);
		bool Delete_Queue(T & myqueue);
};

template <class T>
QueueTemplate<T>::QueueTemplate()
{
	front=0;
	rear=0;
}

template <class T>
bool QueueTemplate<T>::Add_Queue(const T & myqueue)
{
	if(rear==MAXSIZE) return false;
	else
	{
		T[rear++] = myqueue;
		return true;
	}
}

template <class T>
bool QueueTemplate<T>::Delete_Queue(T & myqueue)
{
	if(front==rear==0) return false;
	else
	{
		myqueue = T[front--];
		return true;
	}
}

int main(void)
{
	return 0;
}