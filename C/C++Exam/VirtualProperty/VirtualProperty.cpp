#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>

using namespace std;


class Basic_property
{
private:
	string type;
	string location;
	int year;
	int price;
	string owner;
	static int property_num;
public:
	Basic_property();
	Basic_property(string type, string location, int year, int price, string owner);
	static void show_property_num()
	{
		cout << property_num;
	}
	virtual void show_property() const;
};

Basic_property::Basic_property()
{  
	property_num++;
}
//成員串列: 可存取基礎類別的private成員
//必須在類別 implementation 時才使用成員串列
//在宣告階段使用成員串列會產生編譯錯誤
Basic_property::Basic_property(string mytype, string mylocation, int myyear, int myprice, string myowner)
{
	property_num++;
	this->type=mytype;
	this->location=mylocation;
	this->year=myyear;
	this->price=myprice;
	this->owner=myowner;
}

void Basic_property::show_property() const
{  
	cout << "***** Basic property of buildings *****" << endl;
	cout << this->owner << endl;
	cout << this->type << endl;
	cout << this->location << endl;
	cout << this->price << " 萬" << endl;
	cout << this->year << " 年" << endl;
}

class Apartment: public Basic_property
{
private:
	bool lift_ready;
	int management_fee;
public:
	Apartment();
	Apartment(string type, string location, int year, int price, string owner, bool lift_ready, int management_fee);
	virtual void show_property() const;
};
Apartment::Apartment()
{
}
Apartment::Apartment(string aType, string aLocation, int aYear, int aPrice, string aOwner, bool aLift_ready, int aManagement_fee):Basic_property(aType, aLocation, aYear, aPrice, aOwner)
{
	this->lift_ready = aLift_ready;
	this->management_fee = aManagement_fee;
}
void Apartment::show_property() const
{
	Basic_property::show_property();
	cout << "***** Apartment Property *****" << endl;
	if(this->lift_ready) cout << "有電梯" << endl;
	else cout << "無電梯" << endl;
//	cout << this->lift_ready << endl;
	cout << "管理費每月： " << this->management_fee << " 元" << endl;
}

class BigHouse : Basic_property
{
private:
	bool garden;
	int luxy_tax;
public:
	BigHouse();
	BigHouse(string type, string location, int year, int price, string owner, bool garden, int luxy_tax);
	virtual void show_property() const;

};
BigHouse::BigHouse()
{
}
BigHouse::BigHouse(string bType, string bLocation, int bYear, int bPrice, string bOwner, bool bgarden, int bluxy_tax):Basic_property(bType, bLocation, bYear, bPrice, bOwner)
{
	this->garden = bgarden;
	this->luxy_tax = bluxy_tax;
}
void BigHouse::show_property() const
{
	Basic_property::show_property();
	cout << "***** BigHouse Property *****" << endl;
	if(this->garden) cout << "有花園" << endl;
	else cout << "無花園" << endl;
//	cout << this->lift_ready << endl;
	cout << "奢侈稅： " << this->luxy_tax << " 元" << endl;

}

int Basic_property::property_num = 0;
int main(void)
{
	Apartment taoyuan("公寓","龍潭鄉",10, 3500000, "David", true, 1500);
	taoyuan.show_property();
	Apartment taishi("公寓","大溪鎮",10, 2500000, "David", true, 1100);
	taishi.show_property();
	BigHouse Chungli("豪宅","中壢市",2, 13500000, "John", true, 150000);
	Chungli.show_property();
	cout << "*** Total Buildings ***** : " ;
	Basic_property::show_property_num();
	cout << endl;

	return 1;
}
