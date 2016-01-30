/*
1. �ϥ�>>�B��l�ݪ`�N�A>>�|��ťշ�@���j�r���A�|�⴫��r���d�bBUFFER��
   �]���ϥ�>>�B�z��J�ݦۤv�B�z�ťթM����r��
2. �B�z�r��ɡA�i�H�N�r��ŧi����ؤ覡: �r���}�C�M�r��
   �ŧi�r���}�C�Х��N���w���סC
   �ŧi�r�ꤣ��
3. �r��B�z��ơGgetline, get, >>
   getline: �|�H���B�z�r��A���|�⴫��r��������J���x�s,�|�⴫����
   get: �|�⴫��r���d�bQUEUE���A�|�⴫��r���d�bBUFFER���A�U����J�|���ݨ쥦
4. �r����[�G�����r��M�r���}�C���
   �r���}�C: char aa[20]: strcpy, strcat
   �r��: �ϥ� + �B��� = �B��
   
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
// string�ϥ�>>�B��l�|��ťզr����@�r�ꪺ���j�r���C    

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