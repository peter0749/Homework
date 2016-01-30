#include <stdio.h>
#include <string>
#include <CString>
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
#define MAXLENG 100
typedef struct node
{
	int dnode;
    node * llink;
	node * rlink;
} datanode;
datanode * Treenode[10];
//Treenode datanode;

//Treenode * intTree;


int main(void)
{
	string ifile="1010202.s01";
	string ofile="1010202.w01";
	char temp[MAXLENG];
	int data[MAXLENG];
	
	int length=0;
	int nodenum=0;
	int i=0;
	char *errmsg;
	ifstream fin;
	ofstream fout;
	fin.open(ifile.c_str(), ios_base::in);
	fout.open(ofile.c_str(), ios_base::binary);
	while(fin.good())
	{
		fin.getline(temp,MAXLENG);
		cout << "Num is : " << temp << endl;
		if(strlen(temp)>0)
		{nodenum=i; data[i++]=(int)strtod(temp, &errmsg);}
	}
	for(i=0;i<nodenum;i++)
		Treenode->dnode=data[i];
	fin.close();
	fout.close();
	system("pause");
	return 0;
}