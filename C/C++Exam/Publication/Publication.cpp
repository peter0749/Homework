/*
1. 使用>>運算子需注意，>>會把空白當作分隔字元，會把換行字元留在BUFFER當中
   因此使用>>處理輸入需自己處理空白和換行字元
2. 處理字串時，可以將字串宣告為兩種方式: 字元陣列和字串
   宣告字元陣列請任意給定長度。
   宣告字串不用
3. 字串處理函數：getline, get, >>
   getline: 會以整行處理字串，不會把換行字元視為輸入來儲存,會把換行丟棄
   get: 會把換行字元留在QUEUE當中，會把換行字元留在BUFFER當中，下次輸入會先看到它
4. 字串附加：分為字串和字元陣列兩種
   字元陣列: char aa[20]: strcpy, strcat
   字串: 使用 + 運算或 = 運算
   
*/

#include <iostream>
#include <fstream>
#include <io.h>
#include <string>
#include <fcntl.h>
using namespace std;

class Publication
{
private:
	string title;
	int price;
public:
	Publication();
	virtual void getdata();
	virtual void putdata();
};

Publication::Publication()
{
//	title=NULL;
	price=0;
}

void Publication::getdata()
{
/* string version */
/*	string tempstr;
	string temp2;
	int cost=0;
	cout << "Please enter title: ";
	getline(cin, tempstr);
	cin.get();
    title = tempstr;
	cout << "tempstr :" << tempstr << " title: " << title << endl;;
	cout << "\nPlease enter price: ";
	getline(cin, temp2);
	cin.get();
	char* errmsg;
	cost=(int)strtod(temp2.c_str(),&errmsg);
	price = cost;
	cout << "cost: " << cost << " price: " << price << endl;
	cout << endl; */
/* string version */
/* char array version */
    char tempstr[100]; //ver char array
	char temp2[100]; //ver char array
	int cost=0;
	cout << "Please enter title: ";
	cin.getline(tempstr,100); //ver char array
	int length=(int)strlen(tempstr);
	title = new char(length+1);
	title=tempstr[0];
	for(int i=1;i<length;i++)
		title += tempstr[i];
//	cout << "tempstr :" << tempstr << " title: " << title << endl;    
	cout << "\nPlease enter price: ";
	cin.getline(temp2,100);	
	cost=atof(temp2);
	price = cost;
//	cout << "cost: " << cost << " price: " << price << endl;
	cout << endl;
// string使用>>運算子會把空白字元當作字串的分隔字元。    

}

void Publication::putdata()
{
	cout << "Title: " << this->title << " price: " << this->price << endl;
}

class Book: public Publication
{
private:
	int pages;
public:
	Book();
	virtual void getdata();
	virtual void putdata();

};

Book::Book()
{
}

void Book::getdata()
{
	/* string version */
/*	string temp3;
	Publication::getdata();
	cout << "Enter Pages: ";
    getline(cin, temp3);
	cin.get();
	char* errmsg;
	pages = (int)strtod(temp3.c_str(), &errmsg);  */
/* string version */

/* char array version */
	char temp2[100];
	Publication::getdata();
	cout << "Enter Pages: ";
	cin.getline(temp2,100);
	pages=atoi(temp2);
/* char array version */

}
void Book::putdata()
{
	Publication::putdata();
	cout << "Pages: " << pages << endl;;
}

int main(void)
{
	Publication mypub;
	Book commic;
	mypub.getdata();
	commic.getdata();
	
	

//	Book commic;
	

	mypub.putdata();
	commic.putdata();

	system("pause");
	return 0;
}