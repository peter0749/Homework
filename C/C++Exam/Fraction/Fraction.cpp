#include <fstream>
#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
using namespace std;

class Fraction
{
private:
	int fc;
	int fm;
public:
	Fraction(int c=0, int m=1);
	Fraction & Fraction:: operator+ (Fraction& lv);
	Fraction & Fraction:: operator- (Fraction& lv);
	Fraction & Fraction:: operator* (Fraction& lv);
	Fraction & Fraction:: operator/ (Fraction& lv);
	bool       Fraction:: operator> (Fraction& lv);
	bool       Fraction:: operator< (Fraction& lv);
	int Fraction:: operator== (Fraction& lv);
	float Fraction::evaulate();
	int Getfc();
	int Getfm();
	friend ostream & operator<<(std::ostream & os, const Fraction & lv);
	friend fstream & operator<<(std::fstream & fs, const Fraction & lv);
	

	void Fraction::PrintData();
};
Fraction::Fraction(int c, int m)
{
	if(m<=0)
		throw "だダぃ眔箂";
	this->fc=c;
	this->fm=m;
}

Fraction & Fraction::operator+ (Fraction& lv)
{
	int cc,cm;
	cc = this->fc; cm = this->fm;
	if(this->fm != lv.fm)
	{
		this->fm = cm * lv.fm;
		this->fc = cc * lv.fm + cm * lv.fc;
	} else
	{
		this->fc += lv.fc;
	}
	return *this;
}

Fraction & Fraction::operator- (Fraction& lv)
{
	int cc,cm;
	cc = this->fc; cm = this->fm;
	if(this->fm != lv.fm)
	{
		this->fm = cm * lv.fm;
		this->fc = cc * lv.fm - cm * lv.fc;
	} else
	{
		this->fc -= lv.fc;
	}
	return *this;
}

Fraction & Fraction::operator* (Fraction& lv)
{
//	int cc,cm;
	this->fm *= lv.fm;
	this->fc *= lv.fc;

	return *this;
}

Fraction & Fraction::operator/ (Fraction& lv)
{
//	int cc,cm;
	this->fm *= lv.fc;
	this->fc *= lv.fm;

	return *this;
}

bool Fraction:: operator> (Fraction& lv)
{
	if(this->fm == lv.fm)
		return ((this->fc - lv.fc) >0);
	else
		return ((this->fc * lv.fm - this->fm * lv.fc) >0);
}

bool Fraction:: operator< (Fraction& lv)
{
	if(this->fm == lv.fm)
		return ((this->fc - lv.fc) <0);
	else
		return ((this->fc * lv.fm - this->fm * lv.fc) <0);
}

int Fraction::operator == (Fraction& lv)
{
	if(this->fm != lv.fm)
		return ((this->fc * lv.fm) == (this->fm * lv.fc) );
	else
		return (this->fc == lv.fc);
}

float Fraction::evaulate()
{
	cout << "Eだ计 " << this->fc << " / " << this->fm << " = " ;
	cout << (float)this->fc/this->fm << endl;
	return this->fc/this->fm;
}

void Fraction::PrintData()
{
	cout << "だ计 " << this->fc << " / " << this->fm << " = " ;
	cout << (float)this->fc/this->fm << endl;
}
std::ostream & operator<<(std::ostream & os, Fraction & lv)
{
//	int cc=lv.Getfc();
//	int mm=lv.Getfm();
//	os << "Fraction( " << lv.fc << " ) ";
    os << " Fraction( " << lv.Getfc() << " / " << lv.Getfm() << " ) ";
	return os;

}

std::fstream & operator<<(std::fstream & fs, Fraction & lv)
{
//	int cc=lv.Getfc();
//	int mm=lv.Getfm();
//	os << "Fraction( " << lv.fc << " ) ";
    fs << " Fraction( " << lv.Getfc() << " / " << lv.Getfm() << " ) ";
	return fs;

}
int Fraction::Getfc()
{
	return this->fc;
}
int Fraction::Getfm()
{
	return this->fm;
}

int main()
{
//	int fm0, fc0, fm1, fc1;
	int i,j;
	string iFile="fraction.s01";
	string oFile="fraction.w01";
	ifstream fin;
	ofstream fout;
	fin.open(iFile.c_str(), ios_base::in);
	fout.open(oFile.c_str(), ios_base::binary);
    string temp;
	fin >> temp;
	int a0;
	if(a0=atoi(temp.c_str()))
	cout << "The num of fraction: " << a0 << endl;
	int fraction[2][2];
	i=0; j=0;
	fin>>temp;
	while(fin.good())
	{
		fraction[i][j++]=atoi(temp.c_str());
		if(j>1)
		{
			i++; j=0;
			if(i>1) break;
		}
		fin>>temp;
	}
/*
	int num_of_fractions=2;
	int fraction[2][2];
	cout << "叫ㄌ块ㄢ舱だ计计" << endl;

	i=0; j=0;
	while(i<num_of_fractions)
	{
		cout << "块材 " << i+1 << " 舱だ计 " << endl;
		cin >> fraction[i][j] >> fraction[i][j+1] ;

		i++;
	}

	i=0; j=0;
*/
	i=0;j=0;
//    while(i<num_of_fractions)
	while(i<a0)
	{
		cout << "だ计 " << fraction[i][j] << " / " << fraction[i][j+1] << " = " << (float)fraction[i][j]/fraction[i][j+1] <<endl;
		i++;
	}
    cout << "############" << endl;
	Fraction AA= Fraction(fraction[0][0],fraction[0][1]);
	AA.evaulate();
	Fraction BB= Fraction(fraction[1][0],fraction[1][1]);
	BB.evaulate();
	cout << AA << " and " << BB;
	fout << AA << " and " << BB;
	if(AA==BB) 
	{
		cout << "  " << endl;
		fout << "  " << "\r\n";
	}
	else
	{
		cout << " ぃ " << endl;
		fout << " ぃ " << "\r\n";
	}
	fout << AA << " > " << BB << "  ";
	fout << ((AA>BB)? " 痷 ":" 安 ") << "\r\n"; 
	fout << AA << " < " << BB << "  ";
	fout << ((AA<BB)? " 痷 ":" 安 ") << "\r\n"; 
	Fraction CC = AA;
	CC.evaulate();
	cout << "*** before addition ***" << endl;
	fout << AA << " + " << BB << " = ";
	AA.PrintData();
	AA = AA + BB;
	fout << AA << "\r\n";
	cout << "*** after addition ***" << endl;
    AA.PrintData();
	BB.PrintData();
	CC.PrintData();
	AA = CC;
    cout << "*** before substraction ***" << endl;
	fout << AA << " - " << BB << " = ";
	AA.PrintData();
	AA = AA - BB;
    cout << "*** after substraction ***" << endl;
    AA.PrintData();
	fout << AA << "\r\n";
	AA = CC;
    cout << "*** before multiplication ***" << endl;
	fout << AA << " * " << BB << " = ";
	AA.PrintData();
	AA = AA * BB;
    cout << "*** after multiplication ***" << endl;
    AA.PrintData();
	fout << AA << "\r\n";
    AA = CC;
    cout << "*** before division ***" << endl;
	fout << AA << " / " << BB << " = ";
	AA.PrintData();
	AA = AA / BB;
    cout << "*** after division ***" << endl;
	fout << AA << "\r\n";
    AA.PrintData();
	fin.close();
	fout.close();
	
	return 0;
}