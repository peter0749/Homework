// inserts.cpp -- copy() and insert iterators
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <fstream>
class MyString
{
public:
	std::string str;
	int chars;
//	static strings;
public:
	MyString::MyString();
	MyString& MyString::operator<<(std::string mystr);
	friend MyString operator>>(std::string mystr, const MyString & MyStr);
	friend std::ostream & operator<<(std::ostream & os, const MyString & MyStr);
//	friend void operator<<(std::ostream & os, const MyString & MyStr);
	MyString& MyString::uppercase();
	int MyString::NumOfChar(const char T);
};
MyString::MyString()
{
	chars=0;
};

MyString& MyString::operator<<(std::string mystr)
{ 
	str+=mystr;
	chars = strlen(str.c_str());
	return *this;
};
MyString operator>>(std::string mystr, const MyString & MyStr)
{
	MyString MyTemp;
	MyTemp.str = mystr + MyStr.str;
    MyTemp.chars = strlen(MyTemp.str.c_str());
	return MyTemp;
	
};
/*
void operator<<(std::ostream & os, const MyString & MyStr)
{
	os << MyStr.str << std::endl;
};
*/
std::ostream & operator<<(std::ostream & os, const MyString & MyStr)
{  
    os << MyStr.str << std::endl;
    return os;
             };
MyString& MyString::uppercase()
{
	int length = strlen(str.c_str());
	char ch[50];
	char target[50];
	strcpy(ch,str.c_str());
	for(int i=0; i<=length; i++)
	{
		if( !isupper((int)ch[i]))
			target[i] = toupper(ch[i]);
		else
			target[i] = ch[i];		
	}
//	std::string mystemp;
//	strcpy(mystemp, target);
	str=target;
	return *this;
};

int MyString::NumOfChar(const char T)
{
	int MAXSIZE=100;
	int counts=0;
	char * temparray;
	temparray = new char[chars+1];

	strcpy(temparray,str.c_str());
	for(int j=0; j<chars; j++)
		if (temparray[j] == T) counts ++;
    return counts;
};

int main()
{
    using namespace std;
	string ifile = "991101.s01";
	string ofile = "991101.w01";
	int is_color=0;
	ifstream fin;		
	ofstream fout;
	fin.open(ifile.c_str(), ios_base::in);
	fout.open(ofile.c_str(), ios_base::binary);

    string s1[4] = {"fine", "fish", "fashion", "fate"};
    string s2[2] = {"busy", "bats"};
    string s3[2] = {"silly", "singers"};
	string s4[10];
	string s5[3] = {"My", "name", "is"};
	string s6[6] = {" and", "I", "am", "a", "C++", "student."};
	string colors[7] = {"red", "green", "blue", "yellow", "white", "orange", "purple"};
	string right_colors[3] = {"red", "green", "blue"};
	string bad_colors[4] = {"yellow", "white", "orange", "purple"};
    vector<string> words(4);
	vector<string> pinwords(4);
	vector<string> usrname(4);
	string temp;
	cout << "Please enter your name : ";
	fin >> temp;
	int i=0;
	s4[0]=temp;
	s4[0]+=" ";
    MyString inputstr;
	while(fin.good())
	{
//		copy(temp+i, temp+i+1, pinwords.begin());
//		cout << temp << endl;
		fin >> temp;

		for(int j=0; j<=3;j++)
		{
			if(temp == bad_colors[j]) 
			{
				is_color=1;
				cout << temp << endl;
				cout << "Try again!" << endl;
				break;
			}
		}
		for(int k=0; k<=2;k++)
		{
			if(temp == right_colors[k]) 
			{
				is_color=1;
				cout << temp << endl;
				cout << "That's right!" << endl << "Bye " << endl;
				break;
			}
		}
		if(is_color==0)
		{
			s4[i]+=temp;
			inputstr<<s4[i++];
			cout << " ***** usrname **** " << endl; 
			cout << inputstr;
			string temp01 = "My name is ";
			inputstr = temp01 >> inputstr;
			cout << " ---- usrname 2 ---- " << endl;
			cout << inputstr;
			string temp02 = " and I am a C++ student.";
			inputstr << temp02;
			cout << " &&&&&& usrname total &&&&& " << endl;
			cout << inputstr<<endl;;
			cout<< inputstr.uppercase();
			int num_of_chars=inputstr.NumOfChar('A');
			cout << "contains " << num_of_chars << " 'A' characters in it." << endl;
			cout << "Enter the name of a primary color for mixing light:  ";
		}

		

	}
    copy(s1, s1 + 4, words.begin());
	copy(s4, s4 + i, pinwords.begin());
    ostream_iterator<string, char> out(cout, " ");
	copy (words.begin(), words.end(), out);
    cout << endl;
	cout << "========== pinwords =============" << endl;
//	ostream_iterator<string, char> out(cout, " ");
	copy (pinwords.begin(), pinwords.end(), out);
	cout << endl;

// construct anonymous back_insert_iterator object
    copy(s2, s2 + 2, back_insert_iterator<vector<string> >(words));
    copy (words.begin(), words.end(), out);
    cout << endl;

// construct anonymous insert_iterator object
    copy(s3, s3 + 2, insert_iterator<vector<string> >(words, words.begin()));
    copy (words.begin(), words.end(), out);
    cout << endl;
	copy(s5, s5 + 3, insert_iterator<vector<string> >(pinwords, pinwords.begin()));
	copy (pinwords.begin(), pinwords.end(), out);
	cout << endl;
system("pause");
    return 0; 
}
