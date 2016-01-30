#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <CString>
using namespace std;



template <class T>
class ArrayClass 
{
	private:
		T element[10];	
		int index;
	public:
		ArrayClass();

		static int element_num;
		ArrayClass & operator<<(const T arg);
		virtual void printArray();
		static int object_type;
		int serachForInt(const T arg);
		
		
		
};
