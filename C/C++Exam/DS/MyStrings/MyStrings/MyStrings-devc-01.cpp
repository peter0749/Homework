#include <iostream>
#include <string>
#include <fstream>
#include <fcntl.h>

class MyStrings
{
   private:
          std::string str;
          int chars;
          static int strings;
   public:
          MyStrings::MyStrings();
          MyStrings::MyStrings(const char * tempstr);
          MyStrings & MyStrings::operator<<(const std::string tempstr);
          friend std::ostream & operator<<(std::ostream & os, const MyStrings & mystr);
          friend MyStrings operator>>(const std::string tempstr, const MyStrings & mystr);
          MyStrings & MyStrings::uppercase();
          int MyStrings::CountsOfChar(const char tempchar);
          
};
int MyStrings::strings=0;
MyStrings::MyStrings()
{
  chars = 0;
  strings ++;
};
MyStrings::MyStrings(const char * tempstr)
{
  chars = strlen(tempstr);
  strings++;
  str = tempstr;
};
MyStrings & MyStrings::operator<<(const std::string tempstr)
{
  str+=tempstr;
  chars=strlen(str.c_str());
  return *this;
};

std::ostream & operator<<(std::ostream & os, const MyStrings & mystr)
{
  os << mystr.str << std::endl;
  return os;
};

MyStrings operator>>(const std::string tempstr, const MyStrings & mystr)
{
  MyStrings MyTemp;
  MyTemp.str = tempstr;
  MyTemp.str += mystr.str;
  return MyTemp;
};
MyStrings & MyStrings::uppercase()
{
   std::string tempstr;
   std::string target;
   int length = strlen(str.c_str());
   tempstr = str;
   target = str;
   for(int i=0; i<length; i++)  
     if(!isupper((int)tempstr[i]))
        target[i] = toupper((int)tempstr[i]);
     else
        target[i] = tempstr[i];
   str = target;
   return *this;
                    
};                 
int MyStrings::CountsOfChar(const char tempchar)
{
    int counts=0;
    std::string tempstr;
    int length = strlen(str.c_str());
    tempstr = str;
    for(int i=0; i<length; i++)
      if(tempstr[i]==tempchar)  counts++;
    return counts;
    
};    
int main()
{
    using namespace std;
    string ifile="920203.s01";
    string ofile="920203.w01";
    string right_color[3]={"red", "green", "blue"};
    string wrong_color[4]={"white", "yellow", "orange", "purple"};
    int is_color=0;
    int name_toggle=0;
    ifstream fin;
    ofstream fout;
    fin.open(ifile.c_str(),ios_base::in);
    string temp;
    fin>>temp;
    MyStrings inputstr(temp.c_str());
    cout << "*** MyStrings Object ***" << endl;
    cout << inputstr;
    while(fin.good())
    {
      for(int i=0;i<=2;i++)
       if(temp==right_color[i])
        {cout << temp << endl << "That's right!, Bye " << endl;
         is_color=1;
         break;}
      for(int j=0;j<=3;j++)
       if(temp==wrong_color[j])
        {cout << temp << endl << "Try again!" << endl;
         is_color=1;
         break;}
      if(is_color==0)
      {
        if(name_toggle==1)
        {
          inputstr<<" " << temp;
          cout << " --- usrname ---" << endl;
          cout << inputstr;
          string temp01 = "My name is ";
          inputstr = temp01>>inputstr;
          cout << "*** My name is ***" << endl;
          cout << inputstr;
          string temp02 = " and I am a C++ student.";
          inputstr << temp02;
          cout << inputstr;
          cout << inputstr.uppercase();
          cout << "The Strings has " << inputstr.CountsOfChar('A') << " 'A' "<< endl;
        }
        if(name_toggle==0) name_toggle ^= 1;
        
      }
      cout << temp << endl;
      fin>>temp;
    }
    system("pause");  
    return 0;
}

