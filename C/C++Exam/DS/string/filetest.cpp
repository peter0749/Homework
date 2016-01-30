#include <stdio.h>
#include <istream>
#include <iostream>
#include <fstream>
#include <CString>
#include <fcntl.h>
#include <io.h>

/************************************************************************/
/* main()
/************************************************************************/


int main()
{
	using namespace std;
	int i=0;
	int idnum=0;
	File *fp;
	File *fo;
	string ifile="infile.txt";
	fp = fopen(ifile, "rb");
	string ofile="outfile.txt";

	ofstream fout(ofile.c_str(), ios::binary);
  //  ifstream fin( ifile.c_str(), ios::binary);
    char temp[100];
	while(!fin.eof()){
	//  fin.get((char *)&temp,sizeof(&temp));
	  fp.
	  cout << temp << endl;
	  fout << temp << endl;



  
   }


    fin.close();
	fout.close();

	return 1;
}
