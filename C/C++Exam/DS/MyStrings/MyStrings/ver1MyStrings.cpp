#include <stdio.h>
#include <iostream>
#include <fstream>
#include <CString>
#include <fcntl.h>
#include <io.h>
class MyStrings
{
public:
	char * str;
	int chars;
    static int strings;
public:
	MyStrings::MyStrings();
	MyStrings& MyStrings::operator<<(const char * t);
//	friend operator>>(const char * t, const MyStrings & MyStr);
//	MyStrings& MyStrings::operator=(const char * t);
//	MyStrings& MyStrings::operator>>(const char * t);
//	MyStrings& MyStrings::operator+(const char * t);
//	MyStrings& MyStrings::operator==(const char * t);
//	MyStrings& MyStrings::operator<(const char * t);
//	MyStrings& MyStrings::operator>(const char * t);
};
MyStrings::MyStrings()
{
};
/*
e1 << Maria Pan t="Maria Pan" this.str=""   ==>e1.str="Maria Pan"
"Myname is " >> e1  ==>e1.str="My name is Mxx Pan"
e1 << "and I am a C++ student." t="and I am ..." this.str="My name is Mxx P
*/

//------------------------------------------------
MyStrings& MyStrings::operator<<(const char * t) 
{
//	MyStrings y;
	char * newstr;
//	Employee y;
//	int len=strlen(t)+strlen(str);
//	int mylen=strlen(t)+strlen(str);
//    newstr = new char[mylen+1];  	
//	y.str = new char[len+1];
//	_name=new char[len+1];
	if(strlen(str)>0)
	{  //String has characters inside already
		strcat(str,t);	
	}
	else
	{
		int length = strlen(t);
		str=new char[length+1];
		strcpy(str,t);
	}
//	strcpy(y.str,str);
	
//	strcat(y.str,t);
	return *this;
};

//--------------------------------------------------
/*
operator>>(const char * t, const MyStrings & MyStr) 
{
//	Employee y;
	int len=strlen(t);
	_name=new char[len+1];
	strcpy(_name,t);
	return *this;
};

//--------------------------------------------------
MyStrings& MyStrings::operator>>(const char * t) 
{
//	Employee y;
	int len=strlen(t);
	_name=new char[len+1];
	strcpy(_name,t);
	return *this;
};
//--------------------------------------------------
MyStrings& MyStrings::operator+(const char * t) 
{
//	Employee y;
	int len=strlen(t);
	_name=new char[len+1];
	strcpy(_name,t);
	return *this;
};
//----------------------------------------------------
MyStrings& MyStrings::operator==(const char * t) 
{
//	Employee y;
	int len=strlen(t);
	_name=new char[len+1];
	strcpy(_name,t);
	return *this;
};
//----------------------------------------------------
MyStrings& MyStrings::operator<(const char * t) 
{
//	Employee y;
	int len=strlen(t);
	_name=new char[len+1];
	strcpy(_name,t);
	return *this;
};
//----------------------------------------------------
MyStrings& MyStrings::operator>(const char * t) 
{
//	Employee y;
	int len=strlen(t);
	_name=new char[len+1];
	strcpy(_name,t);
	return *this;
};
*/
int main()
{
	using namespace std;
	string ifile="920203.s01";
	string ofile="920203.w01";
    string usrname;
	int k=0;
	/* name string*/
	const char * myName="My name is \r";
	const char * studentStr="and I am a C++ student.\r";

	/* right color */
    const char * redColor="red\r";
	const char * greenColor="green\r";
	const char * blueColor="blue\r";
	/* wrong color */
	const char * yellowColor="yellow\r";
	const char * whiteColor="white\r";
	const char * tryCommand="Try again!\r";
	const char * rightCommand="That's right!\r";
	const char * colorPrompt="Enter the name of a primary color for mixing light: \r";
	ofstream fout(ofile.c_str(), ios::binary);
    ifstream fin( ifile.c_str(), ios::binary);
	char temp[100];
	//bool EOF=fin.eof();
	//char * EOF=0x1;
	while(1){
//	while(!fin.eof()){
 //    while(strcmp(temp, "0x1")==false){
//	while(fin.getline((char *)&temp, sizeof(&temp))){
		fin.getline((char *)&temp, sizeof(&temp));
	
    	cout<< temp << endl;
    //	system("pause");
		int k=0;
		usrname.erase();
		int retYellow = strcmp(temp,yellowColor);
		if(retYellow==0) 
		{
			cout<< tryCommand << endl; 
			system("pause"); 
			continue;
		}
		int retWhite = strcmp(temp,whiteColor);
		if(retWhite==0) 
		{
			cout<< tryCommand << endl; 
			system("pause"); 
			continue;
		}
   //     cout<< temp;
/*        
		while(temp[k] != '\0')
		{
		   if((temp[k]>='a')&&(temp[k]<='z')||(temp[k]>='A')&&(temp[k]<='Z'))
		   {usrname+=temp[k];}
           k++;
		}

*/
//		EOF=fin.eof();
		if(fin.eof()) 
		{ cout<< "Finish \n";
		break; }

	}
	fin.close();
	fout.close();
	return 1;
}
