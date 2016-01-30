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
	friend MyStrings operator>>(const char * t, const MyStrings & MyStr);
	MyStrings MyStrings::uppercase();
	int MyStrings::CountsofChar(const char t);
	bool MyStrings::operator==(const MyStrings & MyStr);
	char * MyStrings::ShowStr();
//	MyStrings MyStrings::uppercase(const MyStrings & MyStr);
//	MyStrings& MyStrings::operator=(const char * t);
//	MyStrings& MyStrings::operator>>(const char * t);
//	MyStrings& MyStrings::operator+(const char * t);
//	MyStrings& MyStrings::operator==(const char * t);
//	MyStrings& MyStrings::operator<(const char * t);
//	MyStrings& MyStrings::operator>(const char * t);
};
MyStrings::MyStrings()
{
	chars=0;
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
//	char * newstr;
//	Employee y;
//	int len=strlen(t)+strlen(str);
//	int mylen=strlen(t)+strlen(str);
//    newstr = new char[mylen+1];  	
//	y.str = new char[len+1];
//	_name=new char[len+1];
//	int length = strlen(t);
//	str=new char[length+1];
//	strcpy(str,t);
    int length = strlen(t);
	if(chars>0)
	{  //String has characters inside already
		strcat(str,t);	
		chars += length;
	}
	else
	{		
		str=new char[length+1];
		strcpy(str,t);
		chars = length;
	}

//	strcpy(y.str,str);
	
//	strcat(y.str,t);
	return *this;
};

//--------------------------------------------------

MyStrings operator>>(const char * t, const MyStrings & MyStr) 
{
	MyStrings MyS;
	int len=strlen(t);
	if(MyStr.chars==0)
	{
		MyS.str=new char[len+1];
	    strcpy(MyS.str,t);
		MyS.chars=len;
	} else
	{	
		int total_len=len+MyStr.chars;
		MyS.str=new char[len+MyStr.chars+1];
		strcpy(MyS.str,t);
		strcat(MyS.str,MyStr.str);		
		MyS.chars=total_len;	
	}
	return MyS;
};
//-------------------------------------------------
MyStrings MyStrings::uppercase()
{
	MyStrings MyS;
	int length=strlen(str);
	int i=0;
	char ch[50];
	char target[50];
	strcpy(ch,str);
//	ch=new char[length+1];

	for(i=0;i<=length;i++)
	{
		if(!isupper((int)ch[i]))
		  target[i] = toupper(ch[i]);
		else
		  target[i] = ch[i];

	}
	MyS.str=new char[length+1];
	strcpy(MyS.str, target);
	MyS.chars = length;

//	MyS.str = uppercase(MyStr.str);
	return MyS;
};
int MyStrings::CountsofChar(const char t)
{   int count=0;
    int length=strlen(str);
	int i=0;
	char ch[50];
//	char target[50];
	strcpy(ch,str);
//	ch=new char[length+1];

	for(i=0;i<=length;i++)
	  if(ch[i]==t)
		  count++;  
  return count;
};
bool MyStrings::operator==(const MyStrings & MyStr)
{
	if(strcmp(str, MyStr.str)==true) 
		return true;
	else
		return false;
};
char * MyStrings::ShowStr()
{
	return str;
};
/*
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
	int name_toggle=0;
    MyStrings mystr;
	MyStrings upperstr;
	MyStrings YellowStr,BlueStr,RedStr,WhiteStr,GreenStr;
//	MyStrings ;
	int isColor=0;
    int color[10]={0};
// color: 1:red, 2:green, 3:blue 4:orange, 5:yellow 6:purple 7:white
// color: 1~3: normal
	int k=0; 
	/* name string*/
	const char * myName="My name is ";
	const char * studentStr=" and I am a C++ student.";
    const char * space = " ";
	/* right color */
    const char * redColor="red";
	const char * greenColor="green";
	const char * blueColor="blue";
	/* wrong color */
	const char * yellowColor="yellow";
	const char * whiteColor="white";
	const char * tryCommand="Try again!";
	const char * rightCommand="That's right!";
	const char * colorPrompt="Enter the name of a primary color for mixing light: \r";
	
  //  fstream fin( ifile.c_str(), ios::binary);
    ifstream fin;
	ofstream fout;   //在VISUAL C++中使用fstream不會當機
//    fstream fin;
//    ifstream fin( ifile.c_str(), ios::binary);
//	ofstream fout(ofile.c_str(), ios::binary);

    fin.open( ifile.c_str(), ios_base::in );
	fout.open(ofile.c_str(), ios::binary);
	char temp[100];
	int i=0;
//	bool EOF=fin.eof();
//	char * EOF=0x1;
 //   while(1){
	YellowStr << yellowColor;
    BlueStr << blueColor;
	RedStr << redColor;
	WhiteStr << whiteColor;
	GreenStr << greenColor;
	
	fin >> temp;
	  usrname.erase();
//      fin.getline((char *)&temp, sizeof(&temp));
     while(fin.good()) 
     {
		 isColor=0;
		
		int retYellow = strcmp(temp,yellowColor);
		if(retYellow==0) 
		{
			isColor=1;
            color[k++]=5;           
			cout<< tryCommand << endl; 
		}
		int retWhite = strcmp(temp,whiteColor);
		if(retWhite==0) 
		{
			isColor=1;
            color[k++]=7;             
			cout<< tryCommand << endl; 
		}
		int retBlue = strcmp(temp,blueColor);
		if(retBlue==0) 
		{
			isColor=1;
            color[k++]=3;           
			cout<< rightCommand << endl; 
		}
    
   // }while((color[k-1]<1) || (color[k-1]>3)); 
   //     cout<< temp;
/*        
		while(temp[k] != '\0')
		{
		   if((temp[k]>='a')&&(temp[k]<='z')||(temp[k]>='A')&&(temp[k]<='Z'))
		   {usrname+=temp[k];}
           k++;
		}
		
*/
//     if(fin.eof()==true)
  //     { break; }
 //    fin.getline((char *)&temp, sizeof(&temp));
		if((isColor==0)&&(name_toggle==0))
		{	usrname += temp;
		    usrname += space; 
			name_toggle ^= 1;
		}
		else if((isColor==0)&&(name_toggle==1))
		{
			char UpperA='A';
			usrname += temp;
			mystr = myName >> mystr;
		//	fout<<;
			fout <<"Please enter your name: "<< usrname.c_str() <<"\r\n";
	        		
			mystr << usrname.c_str();
			cout << mystr.ShowStr() << "."<< endl;
			fout << mystr.ShowStr() << ".\r\n";
			mystr << studentStr;
			
			upperstr = mystr.uppercase();
			cout <<"The string: "<< upperstr.ShowStr() << endl;
			fout <<"The string: "<< upperstr.ShowStr() <<"\r\n";

			int num = upperstr.CountsofChar(UpperA);
	
			cout << "contains " << upperstr.CountsofChar(UpperA) << "'A' characters in it." << endl;
			fout << "contains " << num << "'A' characters in it." << "\r\n";
	//		cout << "contains " << num << "'A' characters in it." << endl;
	//		cout << "contains " ;
	//		cout << num;
	//		cout << " 'A' characters in it." << endl;
			name_toggle++; //usrname finished, push usrname here!
			cout << usrname.c_str() << endl;
			cout << "Enter the name of a primary color for mixing light: ";
			fout << "Enter the name of a primary color for mixing light: ";

			usrname.erase();  }

		fin >> temp;
		

	}
	if(fin.eof())
		{ cout << "EOF \n";
		  
                     }
        else if(fin.fail())
        { cout << "Input terminated by data mismatch Fail \n";
		  
                     }
        else cout << "Input terminated for unknown reason.\n";
        

		
	fin.close();
	try{
			fout.close();
		}catch(const char *s)
		{
			cout << s << endl;
		}

	
	system("pause");
	return 0;
}

