#include "ArraySort.h"

template <class T>
ArrayClass<T>::ArrayClass()
{  
	element_num++;
	index=0;
	if(sizeof(T)==sizeof(int)) object_type=1;
	else if(sizeof(T)==sizeof(double)) object_type=2;

 }

template <class T>
ArrayClass<T> & ArrayClass<T>::operator<<(const T arg)
{
//	ArrayClass newArray;
	element[index++] = arg;
	return *this;
}

template <class T>
void ArrayClass<T>::printArray()
{
	if(object_type==1) //int
	{
		int Max=element[0];
		int temp=0;

		cout << "intValue: " << endl;
	}
	else if(object_type==2) //double
	{
		double Max=element[0];
		double temp=0;
		cout << "nulldoubleValue: " << endl;
	}

	
	int i=0;
/*	for(i=1;i<index;i++)
	{	  
		if(element[i]>=Max)
		{
			Max=element[i];
		} else
		{
			element[i-1]=element[i];
			element[i]=Max;
		}
	}
*/
	for(i=0;i<index;i++)
		cout << "element[ " << i << " ] = " << element[i] << endl;
}

template <class T>
int ArrayClass<T>::serachForInt(const T arg)
{
	int i=0;
	for(i=0;i<index;i++)
		if(element[i]==arg) 
		{		
			cout << "Found " << arg << " at element " << i << " in int";
			return i;
		}	
	cout << "Values" << arg << " not found in intValues" << endl;
	return -1;
}

template <class T>
int ArrayClass<T>::element_num=0;
template <class T>
int ArrayClass<T>::object_type=0;

int main(void)
{
	int iArray[20];
	double dArray[20];
	int i,str_leng=0;
	bool is_double=false;
	int j,k;
	j=k=0;
	char* errmsg;
	string ifile="1010201.s01";
	string ofile="1010201.w01";
	string temp;
	ifstream fin;
	ofstream fout;
    ArrayClass<int> inArray;
	ArrayClass<double> doArray;
	
	fin.open(ifile.c_str(), ios_base::in);
	fout.open(ofile.c_str(), ios_base::binary);
	while(fin.good())
	{
		fin>>temp;
		cout << temp << endl;
		str_leng=strlen(temp.c_str());
		for(i=0;i<str_leng;i++)
		{
			if(temp[i]=='.')
			{
				is_double=true;
				break;
			}
		}
		if(is_double==false)
		//	iArray[j++] = (int)strtod(temp.c_str(), &errmsg);
		   inArray = inArray << (int)strtod(temp.c_str(), &errmsg);
		else
			doArray = doArray << strtod(temp.c_str(), &errmsg);
		//	dArray[k++] = strtod(temp.c_str(), &errmsg);
			

	}
	inArray.printArray();
	doArray.printArray();
	int target=5;
	int result=inArray.serachForInt(target);
	target=8763;
	result=inArray.serachForInt(target);
	fin.close();
	fin.close();
	system("pause");
	return 0;
}