#include <iostream>
#include <fstream>
#include <string>
#include <io.h>
#include <fcntl.h>
class MyString
{
  public:
         std::string  str;
         int chars;
         static int strings;
  public:
         MyString::MyString();
		 MyString::MyString(const char * conststr);
         MyString & MyString::operator<<(std::string conststr);
//         friend void operator<<(std::ostream & os, const MyString & MyStr);
         friend std::ostream & operator<<(std::ostream & os, const MyString & MyStr);
         friend MyString operator>>(std::string conststr, const MyString & MyStr);
         MyString & MyString::uppercase();
      };
int MyString::strings=0; //類別靜態變數在主程式和類別宣告外初始化

MyString::MyString()
{
  chars=0;
  strings++;
         };
MyString::MyString(const char * conststr)
{
	strings++;
	chars = strlen(conststr);
//	strcpy(str, conststr);
	str=conststr;
};

MyString & MyString::operator<<(std::string conststr)
{
  str += conststr;
  chars = strlen(str.c_str());
  return *this;
         };
/*
void operator<<(std::ostream & os, const MyString & MyStr)
{ 
  os << MyStr.str << std::endl;
       };
*/
std::ostream & operator<<(std::ostream & os, const MyString & MyStr)
{
  os << MyStr.str ;
  return os;
             };
MyString operator>>(std::string conststr, const MyString & MyStr)
{  MyString MyTemp;
   MyTemp.str = conststr;
   MyTemp.str += MyStr.str;
   MyTemp.chars=strlen(MyTemp.str.c_str());
   return MyTemp;
            };
MyString & MyString::uppercase()
{
	std::string tempstr;
	std::string target;
  // tempstr = new char[chars+1];
  // strcpy(tempstr,str.c_str());
   tempstr=str;
   int length = strlen(str.c_str());
 //  target=new char[length+1];
   target=str;
   for(int i=0; i<length; i++)
      if(isupper((int)tempstr[i]))
         target[i]=tempstr[i];
      else
         target[i] = toupper((int)tempstr[i]);
   str = target;
//      strcpy(str, target);
   return *this;        
         };

int main()
{
    using namespace std;
    string ifile = "920203.s01";
    string ofile = "920203.w01";
    int is_color=0;
    ifstream fin;
    ofstream fout;
    fin.open(ifile.c_str(), ios_base::in);
    fout.open(ofile.c_str(), ios_base::binary);
    string temp;
    int name_togole=0;
    MyString inputstr;
    string primary_color[3]={"red", "green", "blue"};
    string bad_color[4]={"white", "purple", "yellow", "orange"};
    cout << "Please input your name : " ;
    fin >> temp;
    inputstr<<temp;
    inputstr<<" ";
 //   cout << "Temp : " << temp << endl << "inputstr  : ";
 //   cout<<inputstr;
 //   cout << endl;
    while(fin.good())
    {
       
       for(int i=0; i<=3; i++)
        if(temp == bad_color[i]) 
         {
           is_color=1; 
           cout << temp << endl;
           cout << "Try Again!" << endl;
           break;
               }
       for(int j=0; j<=2; j++)
       if(temp == primary_color[j]) 
         {  is_color=1; 
           cout << temp << endl;
           cout << "That's right!" << endl;
           break;
               }  
       if(is_color==0){
          if(name_togole==1)
          {
          inputstr << temp;
   //      cout<< "**** usrnamr ****" << endl;
       //  inputstr<<temp;
       //  cout<<inputstr;
         string tempstr = "My name is ";
         inputstr = tempstr >> inputstr;
         cout << inputstr << "." << endl;       
         tempstr = " and I am a C++ student.";
		 MyString MyTemp(" Hello ");
         inputstr << tempstr;
         cout << "The string : "<< inputstr << endl;
         cout << "The string : "<< inputstr.uppercase() << endl;
		 cout << "MyTemp Object : " << MyTemp << endl;
         }
          if(name_togole==0)
          { 
            name_togole = name_togole ^ 1;
        //    break;
                            } 
          
                       
       }
       fin >> temp;
       
}
                     
    fout.close();
    fin.close();
    system("pause");
    return 0;
}
